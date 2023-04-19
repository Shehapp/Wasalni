#pragma once

#import "ShortPathAlgorithm.h"



ShortPathAlgorithm::ShortPathAlgorithm(Graph *graph) {
    this->graph = graph;
}

void ShortPathAlgorithm::getPath(string start,
                                 string end,
                                 double weight,
                                 map<string, bool> vis,
                                 vector<string> curPath,
                                 map<string, vector<pair<string, double>>> adj) {

}

void ShortPathAlgorithm::run(std::string start, std::string end) {

}




