#include "triangleCount.h"
#include "global.h"

using namespace std;

void countTriedNum(vector<StarEdgeData>& edges, vector<bool>& counted, int allTriedNum[3][2][2][2], int timeWindow)
{
    int len = edges.size();
    int triedNum[3][2][2][2] = {0};
    for(int i=0;i<len;++i)
    {
        int line1_nbr = edges[i].nbr;
        int line1_dir = edges[i].dir;
        int line1_t = edges[i].t;
        if(counted[line1_nbr]) continue;
        for(int j=i+1;j<len;++j)
        {
            int line2_nbr = edges[j].nbr;
            int line2_dir = edges[j].dir;
            int line2_t = edges[j].t;
            if(counted[line2_nbr]) continue;
            if(line2_t-line1_t>timeWindow) break;
            if(line2_nbr==line1_nbr) continue;
            if(edgeMap[line1_nbr].find(line2_nbr)!=edgeMap[line1_nbr].end())
            {
                for(int t:edgeMap[line1_nbr][line2_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][0];
                        // CM
                        // Type 1 triangle, so t_k (t here) is earliest timestamp
                        if (line1_dir==0 && line2_dir==0) {
                            motifTimestamps[4].push_back(t);
                            motifTimeCounts[4][t] += 1;
                        } else if (line1_dir==0 && line2_dir==1) {
                            motifTimestamps[16].push_back(t);
                            motifTimeCounts[16][t] += 1;
                        } else if (line1_dir==1 && line2_dir==0) {
                            motifTimestamps[10].push_back(t);
                            motifTimeCounts[10][t] += 1;
                        } else if (line1_dir==1 && line2_dir==1) {
                            motifTimestamps[22].push_back(t);
                            motifTimeCounts[22][t] += 1;
                        }
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][0];
                        // Type 2 triangle, so t_i (line1_t) is earliest timestamp
                        if (line1_dir==0 && line2_dir==0) {
                            motifTimestamps[16].push_back(line1_t);
                            motifTimeCounts[16][line1_t] += 1;
                        } else if (line1_dir==0 && line2_dir==1) {
                            motifTimestamps[4].push_back(line1_t);
                            motifTimeCounts[4][line1_t] += 1;
                        } else if (line1_dir==1 && line2_dir==0) {
                            motifTimestamps[11].push_back(line1_t);
                            motifTimeCounts[11][line1_t] += 1;
                        } else if (line1_dir==1 && line2_dir==1) {
                            motifTimestamps[5].push_back(line1_t);
                            motifTimeCounts[5][line1_t] += 1;
                        }
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][0];
                        // Type 3 triangle, so t_i (line1_t) is earliest timestamp
                        if (line1_dir==0 && line2_dir==0) {
                            motifTimestamps[17].push_back(line1_t);
                            motifTimeCounts[17][line1_t] += 1;
                        } else if (line1_dir==0 && line2_dir==1) {
                            motifTimestamps[5].push_back(line1_t);
                            motifTimeCounts[5][line1_t] += 1;
                        } else if (line1_dir==1 && line2_dir==0) {
                            motifTimestamps[10].push_back(line1_t);
                            motifTimeCounts[10][line1_t] += 1;
                        } else if (line1_dir==1 && line2_dir==1) {
                            motifTimestamps[4].push_back(line1_t);
                            motifTimeCounts[4][line1_t] += 1;
                        }
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
            if(edgeMap[line2_nbr].find(line1_nbr)!=edgeMap[line2_nbr].end())
            {
                for(int t:edgeMap[line2_nbr][line1_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][1];
                        // Type 1 triangle so first timestamp is t_k (t here)
                        if (line1_dir==0 && line2_dir==0) {
                            motifTimestamps[5].push_back(t);
                            motifTimeCounts[5][t] += 1;
                        } else if (line1_dir==0 && line2_dir==1) {
                            motifTimestamps[11].push_back(t);
                            motifTimeCounts[11][t] += 1;
                        } else if (line1_dir==1 && line2_dir==0) {
                            motifTimestamps[17].push_back(t);
                            motifTimeCounts[17][t] += 1;
                        } else if (line1_dir==1 && line2_dir==1) {
                            motifTimestamps[23].push_back(t);
                            motifTimeCounts[23][t] += 1;
                        }
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][1];
                        // Type 2 triangle, so t_i (line1_t) is earliest timestamp
                        if (line1_dir==0 && line2_dir==0) {
                            motifTimestamps[22].push_back(line1_t);
                            motifTimeCounts[22][line1_t] += 1;
                        } else if (line1_dir==0 && line2_dir==1) {
                            motifTimestamps[10].push_back(line1_t);
                            motifTimeCounts[10][line1_t] += 1;
                        } else if (line1_dir==1 && line2_dir==0) {
                            motifTimestamps[23].push_back(line1_t);
                            motifTimeCounts[23][line1_t] += 1;
                        } else if (line1_dir==1 && line2_dir==1) {
                            motifTimestamps[17].push_back(line1_t);
                            motifTimeCounts[17][line1_t] += 1;
                        }
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][1];
                        // Type 3 triangle, so t_i (line1_t) is earliest timestamp
                        if (line1_dir==0 && line2_dir==0) {
                            motifTimestamps[23].push_back(line1_t);
                            motifTimeCounts[23][line1_t] += 1;
                        } else if (line1_dir==0 && line2_dir==1) {
                            motifTimestamps[11].push_back(line1_t);
                            motifTimeCounts[11][line1_t] += 1;
                        } else if (line1_dir==1 && line2_dir==0) {
                            motifTimestamps[22].push_back(line1_t);
                            motifTimeCounts[22][line1_t] += 1;
                        } else if (line1_dir==1 && line2_dir==1) {
                            motifTimestamps[16].push_back(line1_t);
                            motifTimeCounts[16][line1_t] += 1;
                        }
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
        }
    }
    for(int i1=0;i1<3;++i1)
    {
        for(int i2=0;i2<2;++i2)
        {
            for(int i3=0;i3<2;++i3)
            {
                for(int i4=0;i4<2;++i4)
                {
                    allTriedNum[i1][i2][i3][i4] += triedNum[i1][i2][i3][i4];
                }
            }
        }
    }
}

void countTriedNum_parallel(vector<StarEdgeData>& edges, int allTriedNum[3][2][2][2], int timeWindow)
{
    int len = edges.size();
    int triedNum[3][2][2][2] = {0};
    for(int i=0;i<len;++i)
    {
        int line1_nbr = edges[i].nbr;
        int line1_dir = edges[i].dir;
        int line1_t = edges[i].t;
        for(int j=i+1;j<len;++j)
        {
            int line2_nbr = edges[j].nbr;
            int line2_dir = edges[j].dir;
            int line2_t = edges[j].t;
            if(line2_t-line1_t>timeWindow) break;
            if(line2_nbr==line1_nbr) continue;
            if(edgeMap[line1_nbr].find(line2_nbr)!=edgeMap[line1_nbr].end())
            {
                for(int t:edgeMap[line1_nbr][line2_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][0];
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][0];
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][0];
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
            if(edgeMap[line2_nbr].find(line1_nbr)!=edgeMap[line2_nbr].end())
            {
                for(int t:edgeMap[line2_nbr][line1_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][1];
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][1];
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][1];
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
        }
    }
    for(int i1=0;i1<3;++i1)
    {
        for(int i2=0;i2<2;++i2)
        {
            for(int i3=0;i3<2;++i3)
            {
                for(int i4=0;i4<2;++i4)
                {
                    allTriedNum[i1][i2][i3][i4] += triedNum[i1][i2][i3][i4];
                }
            }
        }
    }
}

void countTriedNum_innerParallel(vector<StarEdgeData>& edges, int allTriedNum[3][2][2][2], int timeWindow)
{
    int len = edges.size();
    int triedNum[3][2][2][2] = {0};
    #pragma omp parallel for num_threads(threads) reduction(+:triedNum)
    for(int i=0;i<len;++i)
    {
        int line1_nbr = edges[i].nbr;
        int line1_dir = edges[i].dir;
        int line1_t = edges[i].t;
        for(int j=i+1;j<len;++j)
        {
            int line2_nbr = edges[j].nbr;
            int line2_dir = edges[j].dir;
            int line2_t = edges[j].t;
            if(line2_t-line1_t>timeWindow) break;
            if(line2_nbr==line1_nbr) continue;
            if(edgeMap[line1_dir].find(line2_dir)!=edgeMap[line1_dir].end())
            {
                for(int t:edgeMap[line1_nbr][line2_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][0];
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][0];
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][0];
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
            if(edgeMap[line2_dir].find(line1_dir)!=edgeMap[line2_dir].end())
            {
                for(int t:edgeMap[line2_nbr][line1_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][1];
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][1];
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][1];
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
        }
    }
    for(int i1=0;i1<3;++i1)
    {
        for(int i2=0;i2<2;++i2)
        {
            for(int i3=0;i3<2;++i3)
            {
                for(int i4=0;i4<2;++i4)
                {
                    allTriedNum[i1][i2][i3][i4] += triedNum[i1][i2][i3][i4];
                }
            }
        }
    }
}
