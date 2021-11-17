#ifndef TRIANGLE_COUNT_H
#define TRIANGLE_COUNT_H

using namespace std;

#include<string>
#include<vector>
#include<string>
#include<fstream>
#include <algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include "edgeLoader.h"

//Èý½ÇÐÎ¼ÆÊý
void countTriedNum(vector<StarEdgeData>& edges, int allTriedNum[2][2][2][3], int timeWindow);
//三角形计数 内部并行
void countTriedNum_innerParallel(vector<StarEdgeData>& edges, int allTriedNum[2][2][2][3], int timeWindow);
#endif // TRIANGLE_COUNT_H