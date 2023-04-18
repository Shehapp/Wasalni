
#include "../Graph.h"


class ShortPathAlgorithm {
public:
    map<string ,Node>mapOfnodes;
    map<string ,Edge>mapOfEdges;
    //               (name of node, name of edge)
    map<string ,vector<pair<string,string>>>adj; //adj list store node.
    // we can get name of nodes and  locations and name of edge and length of edge

    virtual void run(string start, string end)=0;

};