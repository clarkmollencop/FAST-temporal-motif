#include "global.h"

vector<Edge> edges;  //��¼���б�
vector<vector<StarEdgeData>> starEdges;  //��¼���е�����α�
vector<map<int, vector<int>>> edgeMap;  //��¼���������б�
int nodesNum;  //���е�ĸ���
int threadNum = 1;
bool ompFlag = false;
int thrd = INT_MAX;
