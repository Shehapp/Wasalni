#pragma once

#include "ShortPathAlgorithm.h"
class Dfs : public ShortPathAlgorithm {
public:

    explicit Dfs(Graph *graph) : ShortPathAlgorithm(graph) {
        this->graph = graph;

    }

    void run(std::string
    start,
    std::string end
    ) override;

    void getPath(
            string start = "",
            string end = "",
            double weight = 0,
            map<string, bool> vis = {},
            vector<string> curPath = {},
            map<string, vector<pair<string, double>>> adj = {});
};


