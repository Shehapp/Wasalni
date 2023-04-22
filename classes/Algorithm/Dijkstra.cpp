#pragma once

#include "Dijkstra.h"

void Dijkstra::run(string start, string end) {
    Path.first = -1;
    Path.second.clear();
    // check those nodes exist in this graph
    if (graph->checkExistEdge(start, end))
        getPath(start, end, 0, {}, graph->adj);
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
        map<string ,vector<pair<string ,double>>>adj) {
    if (start == end) {
        Path.first = 0;
        Path.second.push_back(start);
        return;
    }
    map<string, double>cost;
    map<string, string>parent;
    priority_queue<pair<double, string>>nex;
    nex.emplace(0, start);
    cost[start] = 0;
    parent[start] = start;

    while (!nex.empty()) {
        double cur = -nex.top().first;
        string node = nex.top().second;
        nex.pop();
        if (vis[node]) continue;
        vis[node] = true;
        for (auto [to, w]: adj[node]) {
            if (cost[to] == 0 || cost[to] > cur + w) {
                cost[to] = cur + w;
                parent[to] = node;
                nex.emplace(-cost[to], to);
            }
        }
    }

    //if cost equal zero this means that no path
    if(start!=end && cost[end]==0)
        return;

    // get the path with smallest weight
    Path.first = cost[end];
    Path.second.push_back(end);
    while (parent[end]!=start){
        Path.second.push_back(parent[end]);
        end = parent[end];
    }
    Path.second.push_back(start);
    reverse(Path.second.begin(),Path.second.end());
}