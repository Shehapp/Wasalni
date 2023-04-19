#pragma once

#import "bits/stdc++.h"
#include "../GraphComponent/Graph.h"
using namespace std;
class ShortPathAlgorithm {
public:
    ShortPathAlgorithm(Graph *graph);
    Graph *graph;
    pair<double,vector<string>>Path;

    virtual void run(std::string start, std::string end);

    virtual void getPath(
             string start="",
             string end="",
             double weight=0,
             map<string ,bool>vis={},
             vector<string>curPath={},
             map<string ,vector<pair<string ,double>>>adj={});

};