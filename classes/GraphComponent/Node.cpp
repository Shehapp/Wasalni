#include "Node.h"

Node::Node() {}

Node::Node(string name, int x, int y) {
    this->name = name;
    this->point = Point(x, y);
}

string Node::getName() {
    return this->name;
}

Point Node::getPoint() {
    return point;
}



