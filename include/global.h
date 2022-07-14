#ifndef GLOBAL_H
#define GLOBAL_H

#include "edgeLoader.h"

extern vector<Edge> edges;
extern vector<vector<StarEdgeData>> starEdges;
extern vector<map<int, vector<int>>> edgeMap;
extern int nodesNum;
extern int threadNum;
extern bool ompFlag;
extern int thrd;
// CM
extern vector<int> motifTimestamps[];
extern bool uniqueTimestamps;
#endif // GLOBAL_H
