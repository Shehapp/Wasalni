
#include "bits/stdc++.h"
#include "Node.h"
using namespace std;
class Edge {
private:
    string name;
    Node node1;
    Node node2;
    double distance;
public:
    Edge();
    Edge(string name,Node node1,Node node2);
    double getDistance();
    string getName();
    string getNameOfNode1();
    string getNameOfNode2();
    bool IsEdgeHasThisNode(string nodeToCheck);
    void CalcDistance();
};


