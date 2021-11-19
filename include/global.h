#ifndef GLOBAL_H
#define GLOBAL_H

#include "edgeLoader.h"

extern vector<Edge> edges;  //��¼���б�
extern vector<vector<StarEdgeData>> starEdges;  //��¼���е�����α�
extern vector<map<int, vector<int>>> edgeMap;  //��¼���������б�
extern int nodesNum;  //���е�ĸ���
extern int threadNum;
extern bool ompFlag;
extern int thrd;
#endif // GLOBAL_H
