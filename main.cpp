#pragma once
#import "classes/Graph.h"
#import "classes/Algorithm/Dfs.h"
#import "classes/Algorithm/Dijkstra.h"
#import "classes/Algorithm/Floyd.h"
int main() {
    Graph *graph = new Graph();
    Dfs dfs(graph);
    Floyd floyd(graph);
    Dijkstra dijkstra(graph);
    cout << "Enter Cites name and x and y " << ":\n";
    while (true) {
        string name;
        cin >> name;
        if (name == "s")break;
        int x, y;
        cin >> x >> y;
        graph->addNode(name, x, y);
    }
    cout << "Enter Cites name to connect them " << ":\n";
    graph->displayNodes();
    while (true) {
        string name1, name2;
        cin >> name1 >> name2;
        if (name1 == "s")break;
        graph->addEdge(name1, name2);
    }
    graph->displayGraph();
    dfs.run("A", "E");
    graph->deleteNode("A");
    dfs.run("A", "E");

}
/*
A 1 0
B 4 0
C 7 0
D 3 0
E 0 0
s
A B
A D
A C
B C
C E
D E
s s


 */