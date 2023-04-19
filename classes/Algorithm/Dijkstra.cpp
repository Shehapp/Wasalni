#pragma once

#include "Dijkstra.h"

void Dijkstra::run(string start, string end) {
    Path.first = -1;
    Path.second.clear();
    getPath(start, end, 0, {}, {}, graph->adj);
    cout << "Weight: " << Path.first << endl;
    cout << "Path: ";
    for (auto a: Path.second) {
        cout << a << " ";
    }
    cout << endl;
}


void Dijkstra::getPath(
        string start,
        string end,
        double weight,
        map<string ,bool>vis,
        vector<string>curPath,
        map<string ,vector<pair<string ,double>>>adj) {

    //implement dijkstra algorithm here
}



