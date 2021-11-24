#ifndef TRIANGLE_COUNT_H
#define TRIANGLE_COUNT_H

#include<vector>
#include "edgeLoader.h"

/* count triangle-motifs */

/* use without OPENMP only */
void countTriedNum(vector<StarEdgeData>& edges, vector<bool>& counted, int allTriedNum[3][2][2][2], int timeWindow);

/* parallel counting method*/
void countTriedNum_parallel(vector<StarEdgeData>& edges, int allTriedNum[3][2][2][2], int timeWindow);
/* for nodes with degree >= thrd, use inner parallel method*/
void countTriedNum_innerParallel(vector<StarEdgeData>& edges, int allTriedNum[3][2][2][2], int timeWindow);
#endif // TRIANGLE_COUNT_H
