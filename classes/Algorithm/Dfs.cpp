#pragma once

#include "Dfs.h"

void Dfs::run(string start, string end) {
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

void Dfs::getPath(
        string start,
        string end,
        double weight,
        map<string, bool> vis,
        vector<string> curPath,
        map<string, vector<pair<string, double>>> adj) {


    vis[start] = true;
    curPath.emplace_back(start);
    if (start == end) {
        if (Path.first == -1) {
            Path.first = weight;
            Path.second = curPath;
        } else if (Path.first > weight) {
            Path.first = weight;
            Path.second = curPath;
        }
        return;
    }
    for (auto [a, b]: adj[start]) {
        if (!vis[a]) {
            getPath(a, end, weight + b, vis, curPath, adj);
            vis[a] = false;
        }
    }
    curPath.pop_back();
}




