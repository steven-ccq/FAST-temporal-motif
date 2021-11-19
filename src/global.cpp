#include "global.h"

vector<Edge> edges;  //记录所有边
vector<vector<StarEdgeData>> starEdges;  //记录所有点的星形边
vector<map<int, vector<int>>> edgeMap;  //记录两点间的所有边
int nodesNum;  //所有点的个数
int threadNum = 1;
bool ompFlag = false;
int thrd = INT_MAX;
