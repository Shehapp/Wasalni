
#include "Edge.h"

/// any street has name and length

    Edge::Edge(){}
    Edge::Edge(string name,Node node1,Node node2){
        this->name=name;
        this->node1=node1;
        this->node2=node2;
        //weight of edge hence,f
        CalcDistance();
    }
    double  Edge::getDistance(){
        return this->distance;
    }
    string  Edge::getName(){
        return name;
    }
    string  Edge::getNameOfNode1(){
        return node1.getName();
    }
    string  Edge::getNameOfNode2(){
        return node2.getName();
    }
    bool  Edge::IsEdgeHasThisNode(string nodeToCheck){
        return (nodeToCheck==getNameOfNode1()) || (nodeToCheck==getNameOfNode2());
    }

    void  Edge::CalcDistance(){
        this->distance= sqrt(pow(node1.getPoint().getX()-node2.getPoint().getX(),2)+
                             pow(node1.getPoint().getY()-node2.getPoint().getY(),2));
    }
