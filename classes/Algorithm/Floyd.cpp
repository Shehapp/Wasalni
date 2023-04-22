#pragma once

#include "Floyd.h"


void Floyd::run(string start, string end) {
    Path.first = -1;
    Path.second.clear();

    // check those nodes exist in this graph
    if (graph->checkExistEdge(start,end)) {
        getPath(start, end, graph->adj, graph->isUpdated);
    }

     cout << "Weight: " << Path.first << endl;
     cout << "Path: ";
     for (auto i: Path.second) {
         cout << i << " ";
     }
    cout << endl;
}

void Floyd::getPath(
        string start,
        string end,
        map<string, vector<pair<string, double>>> adj,
        bool isUpdated) {

    int mx = 1000000;
    int now = 0;
    // hash name of node from string to number
    map<string, int> mapString;
    map<int, string> mapInt;
    for (auto i: adj) {
        mapString[i.first] = now++;
        mapInt[now - 1] = i.first;
    }

    // if graph is updated then i won't run floyd
    // buz i have weight and path between each two nodes
    if (!isUpdated) {
        dp.clear();
        next.clear();
        next.resize(graph->adj.size(), vector<int>(graph->adj.size(), -1));
        dp.resize(graph->adj.size(), vector<double>(graph->adj.size(), mx));
        graph->isUpdated = true;

        for (auto [i, v]: adj) {
            dp[mapString[i]][mapString[i]] = 0;
            for (auto u: v) {
                dp[mapString[i]][mapString[u.first]] = u.second;
                next[mapString[i]][mapString[u.first]] = mapString[u.first];
            }
        }

        int n = adj.size();
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[i][k] == mx || dp[k][j] == mx)continue;
                    if (dp[i][j] > dp[i][k] + dp[k][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }

    // if weight is less than MAX value this means
    // there is path between those nodes
    // and will get path
    if (dp[mapString[start]][mapString[end]] != mx) {
        Path.first = dp[mapString[start]][mapString[end]];
        int now = mapString[start];
        while (now != mapString[end]) {
            Path.second.push_back(mapInt[now]);
            now = next[now][mapString[end]];
        }
        Path.second.push_back(mapInt[now]);
    }
}




