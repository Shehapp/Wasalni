#pragma once

#include "Point.h"

class Node {
private:
    Point point;
    std::string name;
public:
    Node();

    Node(std::string name, int x, int y);

    std::string getName();

    Point getPoint();
};


