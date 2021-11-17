#ifndef EDGE_LOADER_H
#define EDGE_LOADER_H

#include<iostream>
#include<string>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;

// �ߣ���¼�����ź�ʱ��
struct Edge {
    int node1;
    int node2;
    int timestamp;
    Edge(){}
    Edge(int node1_, int node2_, int timestamp_)
    {
        this->node1 = node1_;
        this->node2 = node2_;
        this->timestamp = timestamp_;
    }
};

//���αߣ���¼һ����Χ�ı�
struct StarEdgeData {
    int t;
    int nbr;
    int dir;
    StarEdgeData(){}
    StarEdgeData(int t_, int nbr_, int dir_)
    {
        this->t = t_;
        this->nbr = nbr_;
        this->dir = dir_;
    }
};

//��������
//������
bool cmp(const StarEdgeData& edge1, const StarEdgeData& edge2);
//��ȡ���б�
void getEdges(const string& file);
//��ȡstarEdges
void getStarEdges();
//��ȡedgeMap
void getEdgeMap();
#endif // EDGE_LOADER
