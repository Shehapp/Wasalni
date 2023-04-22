#pragma once

#include "Node.h"
class Graph {
public:

    string name;
    bool isUpdated = false;

    //store node in map
    map<string, Node> mapOfnodes;
    // parent               child      weight
    map<string, vector<pair<string, double>>> adj;

public:
    Graph();

    Graph(string name);

    bool addNode(string name, int x, int y);

    bool addEdge(string node1, string node2);

    void deleteNode(string nameOfNode);

    void deleteEdge(string node1, string node2);

    bool checkExistEdge(string node1, string node2);

    static double DitanceBetweenTwoNodes(Node node1, Node node2);

    void displayNodes();

    void displayGraph();

    void deleteGraph();

};