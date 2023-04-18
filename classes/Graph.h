#include "bits/stdc++.h"
#include "Edge.h"
#include "Algorithm/Floyd.h"
#include "Algorithm/Dfs.h"
#include "Algorithm/Dijkstra.h"

class Graph {
private:

    string name;
    vector<Node>nodes;
    map<string ,Node>mapOfnodes;
    vector<Edge>edges;
    map<string ,Edge>mapOfEdges;
    map<string ,vector<pair<string,string>>>adj;

public:
    Graph(string name);
    bool addNode(string name,int x,int y);
    bool addEdge(string nameOfEdge,string node1,string node2);
    void deleteNode(string nameOfNode);
    bool deleteEdge(string name);
    void displayEdges();
    void displayNodes();
    void displayGraph();
    void buildAdjList();
    void deleteGraph();
    bool distanceBetweenTwoNode();
};