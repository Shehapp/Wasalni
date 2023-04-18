
#include "Point.h"
#include "bits/stdc++.h"

class Node {
private:
    Point point;
    std::string name;
public:
    Node();
    Node(std::string name,int x,int y);
    std::string getName();
    Point getPoint();
};


