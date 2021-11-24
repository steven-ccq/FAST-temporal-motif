#ifndef EDGE_LOADER_H
#define EDGE_LOADER_H

#include<iostream>
#include<string>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;

/* an edge records 3 information: number of two nodes and a timestamp */
struct Edge {
    int node1;
    int node2;
    int timestamp;
    Edge(){}
    Edge(int node1_, int node2_, int timestamp_)
    {
        this->node1 = node1_;
        this->node2 = node2_;
        this->timestamp = timestamp_;
    }
};

/* a starEdge is used to represent an edge connect to a specific node */
/* a starEdge records 3 information: number of the node in another side, timestamp and direction relative to the specific node (1-out 0-in) */
struct StarEdgeData {
    int t;
    int nbr;
    int dir;
    StarEdgeData(){}
    StarEdgeData(int t_, int nbr_, int dir_)
    {
        this->t = t_;
        this->nbr = nbr_;
        this->dir = dir_;
    }
};

/* sorting algorithm */
bool cmp(const StarEdgeData& edge1, const StarEdgeData& edge2);
/* get all edges from data file */
bool getEdges(const string& file);
/* convert edges into starEdges */
void getStarEdges();
/* get the map of connections between nodes */
void getEdgeMap();
#endif // EDGE_LOADER
