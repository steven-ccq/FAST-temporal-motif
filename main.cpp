#include<iostream>
#include "edgeLoader.h"
#include "global.h"
#include "starAndPairCount.h"
#include "triangleCount.h"
#include "convertMartix.h"

using namespace std;

int main(int argc, char **argv)
{
    getEdges("wiki-talk-temporal.txt");
    starEdges.resize(nodesNum);
    getStarEdges();
    edgeMap.resize(nodesNum);
    getEdgeMap();
    edges.clear();
    cout << "loaded file" << endl;

    int allStarNum[3][2][2][2] = {0};
    int allPairNum[2][2][2] = {0};
    int allTriedNum[2][2][2][3] = {0};
    int allMotif[6][6] = {0};
    #pragma omp parallel for num_threads(threads) reduction(+:allStarNum) reduction(+:allPairNum)
    for(int nbr=0;nbr<nodesNum;++nbr)
    {
        countStarNum(starEdges[nbr], allStarNum, allPairNum, 600);
    }
    #pragma omp parallel for num_threads(threads) reduction(+:allTriedNum)
    for(int nbr=0;nbr<nodesNum;++nbr)
    {
        countTriedNum(starEdges[nbr], allTriedNum, 600);
    }

    getMartix(allPairNum, allStarNum, allTriedNum, allMotif);
    return 0;
}
