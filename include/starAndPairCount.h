#ifndef STAR_AND_PAIR_COUNT_H
#define STAR_AND_PAIR_COUNT_H

#include<string>
#include<vector>
#include<string>
#include<fstream>
#include <algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include "edgeLoader.h"

//starºÍpair¼ÆÊý
void countStarNum(vector<StarEdgeData>& center_edges, int allStarNum[3][2][2][2], int allPairNum[2][2][2], int timeWindow);
#endif // STAR_AND_PAIR_H
