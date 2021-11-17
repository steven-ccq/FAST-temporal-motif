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

// 边，记录两点编号和时间
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

//星形边，记录一点周围的边
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

//函数声明
//排序函数
bool cmp(const StarEdgeData& edge1, const StarEdgeData& edge2);
//获取所有边
void getEdges(const string& file);
//获取starEdges
void getStarEdges();
//获取edgeMap
void getEdgeMap();
#endif // EDGE_LOADER
