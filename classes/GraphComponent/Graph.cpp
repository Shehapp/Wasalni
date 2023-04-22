#pragma once

#include "Graph.h"


Graph::Graph() {}

Graph::Graph(string name) {
    this->name = name;
}

bool Graph::addNode(string name, int x, int y) {
    //check if already exist in graph
    if (mapOfnodes.count(name) == 0)
        mapOfnodes[name] = Node(name, x, y);
    else
        return false;
    return true;
}

bool Graph::addEdge(string node1, string node2) {
    // set graph isn't updated
    isUpdated = false;
    // check if any node not exist
    if (mapOfnodes.count(node1) == 0)
        return false;
    if (mapOfnodes.count(node2) == 0)
        return false;
    double Ditance = DitanceBetweenTwoNodes(mapOfnodes[node1], mapOfnodes[node2]);

    adj[node1].emplace_back(node2, Ditance);
    adj[node2].emplace_back(node1, Ditance);
    return true;
}


double Graph::DitanceBetweenTwoNodes(Node node1, Node node2) {
    return sqrt(pow(node1.getPoint().getX() - node2.getPoint().getX(), 2) +
                pow(node1.getPoint().getY() - node2.getPoint().getY(), 2));
}


void Graph::deleteNode(string nameOfNode) {
    if(!checkExistEdge(nameOfNode,nameOfNode))
        return;
    isUpdated = false;
    mapOfnodes.erase(nameOfNode);
    adj.erase(nameOfNode);
    for (auto &item: adj) {
        for (auto it = item.second.begin(); it != item.second.end(); ++it) {
            if (it->first == nameOfNode) {
                item.second.erase(it);
                it--;
            }
        }
    }
}

void Graph::deleteEdge(string node1, string node2) {
    if(!checkExistEdge(node1,node2))
        return;
    isUpdated = false;
    for (auto it = adj[node1].begin(); it != adj[node1].end(); ++it) {
        if (it->first == node2) {
            adj[node1].erase(it);
            break;
        }
    }
    for (auto it = adj[node2].begin(); it != adj[node2].end(); ++it) {
        if (it->first == node1) {
            adj[node2].erase(it);
            break;
        }
    }
}

// display graph in console

void Graph::displayNodes() {
    for (auto [a, b]: mapOfnodes) {
        cout << a << " " << b.getPoint().getX() << " " << b.getPoint().getY() << '\n';
    }

}

void Graph::displayGraph() {
    for (auto item: adj) {
        cout << item.first << ": \n";
        for (auto it = item.second.begin(); it != item.second.end(); ++it) {
            cout << it->first << " " << it->second << '\n';
        }
    }
}

void Graph::deleteGraph() {
    mapOfnodes.clear();
    adj.clear();
}

bool Graph::checkExistEdge(string node1, string node2){
    return mapOfnodes.count(node2)>0 and
           mapOfnodes.count(node1)>0;
}



