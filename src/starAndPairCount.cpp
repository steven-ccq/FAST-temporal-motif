#include "starAndPairCount.h"
#include "global.h"

using namespace std;

void countStarNum(vector<StarEdgeData>& starEdges, int allStarNum[3][2][2][2], int allPairNum[2][2][2], int timeWindow)
{
    int starNum[3][2][2][2] = {0};
    int pairNum[2][2][2] = {0};
    int len = starEdges.size();
    unordered_map<int, int> nbrNum0;
    unordered_map<int, int> nbrNum1;
    for(int i=0;i<len;++i)
    {
        int start_nbr = starEdges[i].nbr;
        int start_dir = starEdges[i].dir;
        int sum[2] = {0};
        for(int j=i+1;j<len;++j)
        {
            if(starEdges[j].t>starEdges[i].t+timeWindow) break;
            int end_nbr = starEdges[j].nbr;
            int end_dir = starEdges[j].dir;
            if(end_nbr==start_nbr)
            {
                starNum[1][start_dir][0][end_dir] += (sum[0]-nbrNum0[end_nbr]);
                starNum[1][start_dir][1][end_dir] += (sum[1]-nbrNum1[end_nbr]);
                pairNum[start_dir][0][end_dir] += nbrNum0[start_nbr];
                pairNum[start_dir][1][end_dir] += nbrNum1[start_nbr];
            }
            else
            {
                starNum[0][start_dir][0][end_dir] += nbrNum0[end_nbr];
                starNum[0][start_dir][1][end_dir] += nbrNum1[end_nbr];
                starNum[2][start_dir][0][end_dir] += nbrNum0[start_nbr];
                starNum[2][start_dir][1][end_dir] += nbrNum1[start_nbr];
            }
            if(end_dir==0) ++nbrNum0[end_nbr];
            else ++nbrNum1[end_nbr];
            ++sum[end_dir];
        }
        nbrNum0.clear();
        nbrNum1.clear();
    }
    for(int s=0;s<3;++s)
    {
        for(int dir1=0;dir1<2;++dir1)
        {
            for(int dir2=0;dir2<2;++dir2)
            {
                for(int dir3=0;dir3<2;++dir3)
                {
                    allStarNum[s][dir1][dir2][dir3] += starNum[s][dir1][dir2][dir3];
                }
            }
        }
    }
    for(int dir1=0;dir1<2;++dir1)
    {
        for(int dir2=0;dir2<2;++dir2)
        {
            for(int dir3=0;dir3<2;++dir3)
            {
                allPairNum[dir1][dir2][dir3] += pairNum[dir1][dir2][dir3];
            }
        }
    }
}
