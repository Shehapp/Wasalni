

#include "Node.h"
using namespace std;
/// any City has name and location

    Node::Node(){}
    Node::Node(string name,int x,int y){
        this->name=name;
        this->point=Point(x,y);
    }
    string Node::getName(){
        return this->name;
    }
    Point Node::getPoint(){
        return point;
    }

