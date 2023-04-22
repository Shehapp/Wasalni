#pragma once

#include "ShortPathAlgorithm.h"
class Floyd : public ShortPathAlgorithm {
public:
    vector<vector<double>> dp;

    // save next state to get path
    vector<vector<int>> next;
    Floyd(Graph *graph) : ShortPathAlgorithm(graph) {
        this->graph = graph;

    }


    void run(std::string start, std::string end);

    void getPath(
            string start = "",
            string end = "",
            map<string, vector<pair<string, double>>> adj = {},
            bool isUpdated = false);
    };


