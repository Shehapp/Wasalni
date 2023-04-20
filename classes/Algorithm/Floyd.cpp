#pragma once

#include "Floyd.h"


void Floyd::run(string start, string end) {
    Path.first = -1;
    Path.second.clear();
    getPath(start, end, 0, {}, graph->adj);
    cout << "Weight: " << Path.first << endl;
    cout << "Path: ";
    for (auto a: Path.second) {
        cout << a << " ";
    }
    cout << endl;
}

void Floyd::getPath(
        string start,
        string end,
        double weight,
        map<string, bool> vis,
        map<string, vector<pair<string, double>>> adj) {

    //implement Floyd algorithm here
}





