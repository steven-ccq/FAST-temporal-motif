#include "triangleCount.h"
#include "global.h"

using namespace std;

void countTriedNum(vector<StarEdgeData>& edges, vector<bool>& counted, int allTriedNum[3][2][2][2], int timeWindow)
{
    int len = edges.size();
    int triedNum[3][2][2][2] = {0};
    for(int i=0;i<len;++i)
    {
        int line1_nbr = edges[i].nbr;
        int line1_dir = edges[i].dir;
        int line1_t = edges[i].t;
        if(counted[line1_nbr]) continue;
        for(int j=i+1;j<len;++j)
        {
            int line2_nbr = edges[j].nbr;
            int line2_dir = edges[j].dir;
            int line2_t = edges[j].t;
            if(counted[line2_nbr]) continue;
            if(line2_t-line1_t>timeWindow) break;
            if(line2_nbr==line1_nbr) continue;
            if(edgeMap[line1_nbr].find(line2_nbr)!=edgeMap[line1_nbr].end())
            {
                for(int t:edgeMap[line1_nbr][line2_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][0];
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][0];
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][0];
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
            if(edgeMap[line2_nbr].find(line1_nbr)!=edgeMap[line2_nbr].end())
            {
                for(int t:edgeMap[line2_nbr][line1_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][1];
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][1];
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][1];
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
        }
    }
    for(int i1=0;i1<3;++i1)
    {
        for(int i2=0;i2<2;++i2)
        {
            for(int i3=0;i3<2;++i3)
            {
                for(int i4=0;i4<2;++i4)
                {
                    allTriedNum[i1][i2][i3][i4] += triedNum[i1][i2][i3][i4];
                }
            }
        }
    }
}

void countTriedNum_parallel(vector<StarEdgeData>& edges, int allTriedNum[3][2][2][2], int timeWindow)
{
    int len = edges.size();
    int triedNum[3][2][2][2] = {0};
    for(int i=0;i<len;++i)
    {
        int line1_nbr = edges[i].nbr;
        int line1_dir = edges[i].dir;
        int line1_t = edges[i].t;
        for(int j=i+1;j<len;++j)
        {
            int line2_nbr = edges[j].nbr;
            int line2_dir = edges[j].dir;
            int line2_t = edges[j].t;
            if(line2_t-line1_t>timeWindow) break;
            if(line2_nbr==line1_nbr) continue;
            if(edgeMap[line1_nbr].find(line2_nbr)!=edgeMap[line1_nbr].end())
            {
                for(int t:edgeMap[line1_nbr][line2_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][0];
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][0];
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][0];
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
            if(edgeMap[line2_nbr].find(line1_nbr)!=edgeMap[line2_nbr].end())
            {
                for(int t:edgeMap[line2_nbr][line1_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][1];
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][1];
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][1];
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
        }
    }
    for(int i1=0;i1<3;++i1)
    {
        for(int i2=0;i2<2;++i2)
        {
            for(int i3=0;i3<2;++i3)
            {
                for(int i4=0;i4<2;++i4)
                {
                    allTriedNum[i1][i2][i3][i4] += triedNum[i1][i2][i3][i4];
                }
            }
        }
    }
}

void countTriedNum_innerParallel(vector<StarEdgeData>& edges, int allTriedNum[3][2][2][2], int timeWindow)
{
    int len = edges.size();
    int triedNum[3][2][2][2] = {0};
    #pragma omp parallel for num_threads(threads) reduction(+:triedNum)
    for(int i=0;i<len;++i)
    {
        int line1_nbr = edges[i].nbr;
        int line1_dir = edges[i].dir;
        int line1_t = edges[i].t;
        for(int j=i+1;j<len;++j)
        {
            int line2_nbr = edges[j].nbr;
            int line2_dir = edges[j].dir;
            int line2_t = edges[j].t;
            if(line2_t-line1_t>timeWindow) break;
            if(line2_nbr==line1_nbr) continue;
            if(edgeMap[line1_dir].find(line2_dir)!=edgeMap[line1_dir].end())
            {
                for(int t:edgeMap[line1_nbr][line2_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][0];
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][0];
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][0];
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
            if(edgeMap[line2_dir].find(line1_dir)!=edgeMap[line2_dir].end())
            {
                for(int t:edgeMap[line2_nbr][line1_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][1];
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][1];
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][1];
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
        }
    }
    for(int i1=0;i1<3;++i1)
    {
        for(int i2=0;i2<2;++i2)
        {
            for(int i3=0;i3<2;++i3)
            {
                for(int i4=0;i4<2;++i4)
                {
                    allTriedNum[i1][i2][i3][i4] += triedNum[i1][i2][i3][i4];
                }
            }
        }
    }
}
