#include<iostream>
#include "edgeLoader.h"
#include "global.h"
#include "starAndPairCount.h"
#include "triangleCount.h"
#include "convertMartix.h"

using namespace std;

map<string, string> args;

int main(int argc, char **argv)
{
    for(int i=1;i<argc;i+=2)
    {
        args[argv[i]] = argv[i+1];
        cout << argv[i] << " " << argv[i+1] << endl;
    }
    const string inputFile = args["-input"];
    const string outputFile = args["-output"];
    if(args.find("-f")!=args.end()) ompFlag = stoi(args["-f"]);
    if(args.find("-t")!=args.end()) threadNum = stoi(args["-t"]);
    if(args.find("-d")!=args.end()) thrd = stoi(args["-d"]);
    int timeWindow = 2147483647;
    if(args.find("-w")!=args.end()) timeWindow = stoi(args["-w"]);

    bool inputFlag = getEdges(inputFile);
    if(!inputFlag) return 0;
    starEdges.resize(nodesNum);
    getStarEdges();
    edgeMap.resize(nodesNum);
    getEdgeMap();
    edges.clear();
    cout << "loaded file" << endl;

    int allStarNum[3][2][2][2] = {0};
    int allPairNum[2][2][2] = {0};
    int allTriedNum[3][2][2][2] = {0};
    int allMotif[6][6] = {0};

    if(!ompFlag)
    {
        for(int nbr=0;nbr<nodesNum;++nbr)
        {
            countStarNum(starEdges[nbr], allStarNum, allPairNum, timeWindow);
        }
        vector<bool> counted(nodesNum, false);
        for(int nbr=0;nbr<nodesNum;++nbr)
        {
            countTriedNum(starEdges[nbr], counted, allTriedNum, timeWindow);
            counted[nbr] = true;
        }
    }
    else
    {
        #pragma omp parallel for num_threads(threads) reduction(+:allStarNum) reduction(+:allPairNum)
        for(int nbr=0;nbr<nodesNum;++nbr)
        {
            countStarNum(starEdges[nbr], allStarNum, allPairNum, timeWindow);
        }
        vector<int> nodes;
        #pragma omp parallel for num_threads(threads) reduction(+:allTriedNum)
        for(int nbr=0;nbr<nodesNum;++nbr)
        {
            int degree = starEdges[nbr].size();
            if(degree>thrd)
            {
                nodes.push_back(nbr);
                continue;
            }
            countTriedNum_parallel(starEdges[nbr], allTriedNum, timeWindow);
        }
        for(int nbr:nodes)
        {
            countTriedNum_innerParallel(starEdges[nbr], allTriedNum, timeWindow);
        }
    }

    getMartix(allPairNum, allStarNum, allTriedNum, allMotif);
    ofstream outfile;
    outfile.open(outputFile);
    if(!outfile.is_open())
    {
        cout << "open output file failed" << endl;
        cout << "output file path: " << outputFile << endl;
        return 0;
    }
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            outfile << allMotif[i][j] << " ";
        }
        outfile << "\n";
    }
    return 0;
}
