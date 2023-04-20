#pragma once

#include "ShortPathAlgorithm.h"
class Dijkstra : public ShortPathAlgorithm {
public:

    Dijkstra(Graph *graph) : ShortPathAlgorithm(graph) {
        this->graph = graph;

    }


    void run(std::string start, std::string end);

    void getPath(
            string start = "",
            string end = "",
            double weight = 0,
            map<string, bool> vis = {},
            map<string, vector<pair<string, double>>> adj = {});
};


