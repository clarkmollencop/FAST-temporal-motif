#include "starAndPairCount.h"
#include "global.h"

using namespace std;

void countStarNum(vector<StarEdgeData>& starEdges, int allStarNum[3][2][2][2], int allPairNum[2][2][2], int timeWindow)
{
    int starNum[3][2][2][2] = {0};
    int pairNum[2][2][2] = {0};
    int len = starEdges.size();
    unordered_map<int, int> nbrNum0;
    unordered_map<int, int> nbrNum1;
    for(int i=0;i<len;++i)
    {
        int start_nbr = starEdges[i].nbr;
        int start_dir = starEdges[i].dir;
        int sum[2] = {0};
        for(int j=i+1;j<len;++j)
        {
            if(starEdges[j].t>starEdges[i].t+timeWindow) break;
            int end_nbr = starEdges[j].nbr;
            int end_dir = starEdges[j].dir;
            if(end_nbr==start_nbr)
            {
                // CM
                int temp10 = starNum[1][start_dir][0][end_dir];
                starNum[1][start_dir][0][end_dir] += (sum[0]-nbrNum0[end_nbr]);
                if ( starNum[1][start_dir][0][end_dir] > temp10 ) {
                    if (start_dir==0 && end_dir==0) {
                        for (int k = 0; k < (starNum[1][start_dir][0][end_dir] - temp10); ++k) {
                            motifTimestamps[19].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[19][starEdges[i].t] += (starNum[1][start_dir][0][end_dir] - temp10);
                    } else if (start_dir==0 && end_dir==1) {
                        for (int k = 0; k < (starNum[1][start_dir][0][end_dir] - temp10); ++k) {
                            motifTimestamps[18].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[18][starEdges[i].t] += (starNum[1][start_dir][0][end_dir] - temp10);
                    } else if (start_dir==1 && end_dir==0) {
                        for (int k = 0; k < (starNum[1][start_dir][0][end_dir] - temp10); ++k) {
                            motifTimestamps[21].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[21][starEdges[i].t] += (starNum[1][start_dir][0][end_dir] - temp10);
                    } else if (start_dir==1 && end_dir==1) {
                        for (int k = 0; k < (starNum[1][start_dir][0][end_dir] - temp10); ++k) {
                            motifTimestamps[20].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[20][starEdges[i].t] += (starNum[1][start_dir][0][end_dir] - temp10);
                    }
                }
                int temp11 = starNum[1][start_dir][1][end_dir];
                starNum[1][start_dir][1][end_dir] += (sum[1]-nbrNum1[end_nbr]);
                if ( starNum[1][start_dir][1][end_dir] > temp11 ) {
                    if (start_dir==0 && end_dir==0) {
                        for (int k = 0; k < (starNum[1][start_dir][1][end_dir] - temp11); ++k) {
                            motifTimestamps[13].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[13][starEdges[i].t] += (starNum[1][start_dir][1][end_dir] - temp11);
                    } else if (start_dir==0 && end_dir==1) {
                        for (int k = 0; k < (starNum[1][start_dir][1][end_dir] - temp11); ++k) {
                            motifTimestamps[12].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[12][starEdges[i].t] += (starNum[1][start_dir][1][end_dir] - temp11);
                    } else if (start_dir==1 && end_dir==0) {
                        for (int k = 0; k < (starNum[1][start_dir][1][end_dir] - temp11); ++k) {
                            motifTimestamps[15].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[15][starEdges[i].t] += (starNum[1][start_dir][1][end_dir] - temp11);
                    } else if (start_dir==1 && end_dir==1) {
                        for (int k = 0; k < (starNum[1][start_dir][1][end_dir] - temp11); ++k) {
                            motifTimestamps[14].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[14][starEdges[i].t] += (starNum[1][start_dir][1][end_dir] - temp11);
                    }
                }
                // CM
                // only have to count on one of outgoing/incoming pair motifs because they are isomorphic and
                // will capture the first timestamp anyway, so I chose this one arbitrarily
                int tempp0 = pairNum[start_dir][0][end_dir];
                pairNum[start_dir][0][end_dir] += nbrNum0[start_nbr];
                if (pairNum[start_dir][0][end_dir] > tempp0) {
                    if (start_dir==0 && end_dir==0) {
                        for (int k = 0; k < (pairNum[start_dir][0][end_dir] - tempp0); ++k) {
                            motifTimestamps[28].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[28][starEdges[i].t] += (pairNum[start_dir][0][end_dir] - tempp0);
                    } else if (start_dir==0 && end_dir==1) {
                        for (int k = 0; k < (pairNum[start_dir][0][end_dir] - tempp0); ++k) {
                            motifTimestamps[35].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[35][starEdges[i].t] += (pairNum[start_dir][0][end_dir] - tempp0);
                    } else if (start_dir==1 && end_dir==0) {
                        for (int k = 0; k < (pairNum[start_dir][0][end_dir] - tempp0); ++k) {
                            motifTimestamps[29].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[29][starEdges[i].t] += (pairNum[start_dir][0][end_dir] - tempp0);
                    } else if (start_dir==1 && end_dir==1) {
                        for (int k = 0; k < (pairNum[start_dir][0][end_dir] - tempp0); ++k) {
                            motifTimestamps[34].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[34][starEdges[i].t] += (pairNum[start_dir][0][end_dir] - tempp0);
                    }
                }
                pairNum[start_dir][1][end_dir] += nbrNum1[start_nbr];
            }
            else
            { 
                // CM
                int temp00 = starNum[0][start_dir][0][end_dir];
                starNum[0][start_dir][0][end_dir] += nbrNum0[end_nbr];
                // CM
                // if there are new motifs, add their starting timestamps to motifTimestamps
                if (starNum[0][start_dir][0][end_dir] > temp00 ) {
                    if (start_dir==0 && end_dir==0){
                        for (int k = 0; k < (starNum[0][start_dir][0][end_dir] - temp00); ++k) {
                            motifTimestamps[7].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[7][starEdges[i].t] += (starNum[0][start_dir][0][end_dir] - temp00);
                    } else if (start_dir==0 && end_dir==1){
                        for (int k = 0; k < (starNum[0][start_dir][0][end_dir] - temp00); ++k) {
                            motifTimestamps[6].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[6][starEdges[i].t] += (starNum[0][start_dir][0][end_dir] - temp00);
                    } else if (start_dir==1 && end_dir==0){
                        for (int k = 0; k < (starNum[0][start_dir][0][end_dir] - temp00); ++k) {
                            motifTimestamps[1].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[1][starEdges[i].t] += (starNum[0][start_dir][0][end_dir] - temp00);
                    } else if (start_dir==1 && end_dir==1){
                        for (int k = 0; k < (starNum[0][start_dir][0][end_dir] - temp00); ++k) {
                            motifTimestamps[0].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[0][starEdges[i].t] += (starNum[0][start_dir][0][end_dir] - temp00);
                    }
                    
                }
                int temp01 = starNum[0][start_dir][1][end_dir];
                starNum[0][start_dir][1][end_dir] += nbrNum1[end_nbr];
                if (starNum[0][start_dir][1][end_dir] > temp01 ) {
                    if (start_dir==0 && end_dir==0){
                        for (int k = 0; k < (starNum[0][start_dir][1][end_dir] - temp01); ++k) {
                            motifTimestamps[9].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[9][starEdges[i].t] += (starNum[0][start_dir][1][end_dir] - temp01);
                    } else if (start_dir==0 && end_dir==1){
                        for (int k = 0; k < (starNum[0][start_dir][1][end_dir] - temp01); ++k) {
                            motifTimestamps[8].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[8][starEdges[i].t] += (starNum[0][start_dir][1][end_dir] - temp01);
                    } else if (start_dir==1 && end_dir==0){
                        for (int k = 0; k < (starNum[0][start_dir][1][end_dir] - temp01); ++k) {
                            motifTimestamps[3].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[3][starEdges[i].t] += (starNum[0][start_dir][1][end_dir] - temp01);
                    } else if (start_dir==1 && end_dir==1){
                        for (int k = 0; k < (starNum[0][start_dir][1][end_dir] - temp01); ++k) {
                            motifTimestamps[2].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[2][starEdges[i].t] += (starNum[0][start_dir][1][end_dir] - temp01);
                    }
                }
                int temp20 = starNum[2][start_dir][0][end_dir];
                starNum[2][start_dir][0][end_dir] += nbrNum0[start_nbr];
                if (starNum[2][start_dir][0][end_dir] > temp20 ) {
                    if (start_dir==0 && end_dir==0){
                        for (int k=0; k < (starNum[2][start_dir][0][end_dir] - temp20); ++k) {
                            motifTimestamps[31].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[31][starEdges[i].t] += (starNum[2][start_dir][0][end_dir] - temp20);
                    } else if (start_dir==0 && end_dir==1){
                        for (int k=0; k < (starNum[2][start_dir][0][end_dir] - temp20); ++k) {
                            motifTimestamps[25].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[25][starEdges[i].t] += (starNum[2][start_dir][0][end_dir] - temp20);
                    } else if (start_dir==1 && end_dir==0){
                        for (int k=0; k < (starNum[2][start_dir][0][end_dir] - temp20); ++k) {
                            motifTimestamps[33].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[33][starEdges[i].t] += (starNum[2][start_dir][0][end_dir] - temp20);
                    } else if (start_dir==1 && end_dir==1){
                        for (int k=0; k < (starNum[2][start_dir][0][end_dir] - temp20); ++k) {
                            motifTimestamps[27].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[27][starEdges[i].t] += (starNum[2][start_dir][0][end_dir] - temp20);
                    }
                }
                int temp21 = starNum[2][start_dir][1][end_dir];
                starNum[2][start_dir][1][end_dir] += nbrNum1[start_nbr];
                if (starNum[2][start_dir][1][end_dir] > temp21 ) {
                    if (start_dir==0 && end_dir==0){
                        for (int k=0; k < (starNum[2][start_dir][1][end_dir] - temp21); ++k) {
                            motifTimestamps[30].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[30][starEdges[i].t] += (starNum[2][start_dir][1][end_dir] - temp21);
                    } else if (start_dir==0 && end_dir==1){
                        for (int k=0; k < (starNum[2][start_dir][1][end_dir] - temp21); ++k) {
                            motifTimestamps[24].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[24][starEdges[i].t] += (starNum[2][start_dir][1][end_dir] - temp21);
                    } else if (start_dir==1 && end_dir==0){
                        for (int k=0; k < (starNum[2][start_dir][1][end_dir] - temp21); ++k) {
                            motifTimestamps[32].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[32][starEdges[i].t] += (starNum[2][start_dir][1][end_dir] - temp21);
                    } else if (start_dir==1 && end_dir==1){
                        for (int k=0; k < (starNum[2][start_dir][1][end_dir] - temp21); ++k) {
                            motifTimestamps[26].push_back(starEdges[i].t);
                        }
                        motifTimeCounts[26][starEdges[i].t] += (starNum[2][start_dir][1][end_dir] - temp21);
                    }
                }
            }
            if(end_dir==0) ++nbrNum0[end_nbr];
            else ++nbrNum1[end_nbr];
            ++sum[end_dir];
        }
        nbrNum0.clear();
        nbrNum1.clear();
    }
    for(int s=0;s<3;++s)
    {
        for(int dir1=0;dir1<2;++dir1)
        {
            for(int dir2=0;dir2<2;++dir2)
            {
                for(int dir3=0;dir3<2;++dir3)
                {
                    allStarNum[s][dir1][dir2][dir3] += starNum[s][dir1][dir2][dir3];
                }
            }
        }
    }
    for(int dir1=0;dir1<2;++dir1)
    {
        for(int dir2=0;dir2<2;++dir2)
        {
            for(int dir3=0;dir3<2;++dir3)
            {
                allPairNum[dir1][dir2][dir3] += pairNum[dir1][dir2][dir3];
            }
        }
    }
}
