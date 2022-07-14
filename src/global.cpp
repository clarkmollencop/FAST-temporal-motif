#include "global.h"

vector<Edge> edges;  //记录所有边  record all edges
vector<vector<StarEdgeData>> starEdges;  //记录所有点的星形边 Record the star sides of all points
vector<map<int, vector<int>>> edgeMap;  //记录两点间的所有边 record all edges between two points
int nodesNum;  //所有点的个数 the number of all points
int threadNum = 1;
bool ompFlag = false;
int thrd = 2147483647;
// CM
vector<int> motifTimestamps[36]; // array of vectors that holds timestamps at which the motifs occurred
bool uniqueTimestamps = false; // specifies if the timestamps in certain motifs are required to be unique or not, default=false