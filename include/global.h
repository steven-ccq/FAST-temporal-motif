#ifndef GLOBAL_H
#define GLOBAL_H

#include "edgeLoader.h"

extern vector<Edge> edges;  //记录所有边
extern vector<vector<StarEdgeData>> starEdges;  //记录所有点的星形边
extern vector<map<int, vector<int>>> edgeMap;  //记录两点间的所有边
extern int nodesNum;  //所有点的个数
extern int threadNum;
extern bool ompFlag;
extern int thrd;
#endif // GLOBAL_H
