#include "edgeLoader.h"
#include "global.h"

using namespace std;

bool cmp(const StarEdgeData& edge1, const StarEdgeData& edge2)
{
    //return edge1.t<edge2.t;
    return edge1.t<edge2.t||(edge1.t==edge2.t&&edge1.nbr<edge2.nbr);
}

bool getEdges(const string& file)
{
    ifstream infile;
    infile.open(file, ios::in);
    if(!infile.is_open ())
    {
        cout << "open input file failed" << endl;
        cout << "input file path: " << file << endl;
        return false;
    }
    while(!infile.eof())
    {
        int node1, node2, timestamp;
        infile >> node1 >> node2 >> timestamp;
        if(node1==node2) continue;
        Edge edge(node1, node2, timestamp);
        edges.push_back(edge);
    }
    infile.close();
    int edgesNum = edges.size();
    if(edgesNum>0)
    {
        edges.pop_back();
        edgesNum -= 1;
    }
    cout << edgesNum << endl;
    set<int> nodes;
    for(int i=0;i<edgesNum;i++)
    {
        nodes.insert(edges[i].node1);
        nodes.insert(edges[i].node2);
    }
    nodesNum = nodes.size();
    map<int, int> nodes_nbr;
    int p = 0;
    for(const int& node:nodes)
    {
        nodes_nbr[node] = p++;
    }
    for(int i=0;i<edgesNum;i++)
    {
        edges[i].node1 = nodes_nbr[edges[i].node1];
        edges[i].node2 = nodes_nbr[edges[i].node2];
    }
    return true;
}

void getStarEdges()
{
    cout << "insert" << endl;
    StarEdgeData starEdge;
    for(Edge& edge:edges)
    {
        starEdge.t = edge.timestamp;
        starEdge.nbr = edge.node2;
        starEdge.dir = 1;
        starEdges[edge.node1].push_back(starEdge);
        starEdge.nbr = edge.node1;
        starEdge.dir = 0;
        starEdges[edge.node2].push_back(starEdge);
    }
    cout << "sort" << endl;
    int starEdgesNum = starEdges.size();
    for(int i=0;i<starEdgesNum;i++)
    {
        sort(starEdges[i].begin(), starEdges[i].end(), cmp);
    }
}

void getEdgeMap()
{
    int num = starEdges.size();
    for(int n=0;n<num;n++)
    {
        for(StarEdgeData& starEdge:starEdges[n])
        {
            if(starEdge.dir==1) edgeMap[n][starEdge.nbr].push_back(starEdge.t);
        }
    }
}
