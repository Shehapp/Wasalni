
#include "Graph.h"
// any Country has name
/*
 we stored graph as edges buz easy to delete and upd (nodes and edges),
 and after maintain this graph will turn it into adj list.
 everytime the graph get upd and the user have finished, the vector of edges will turn to
 adj :(

 this means we know names of nodes and name of edge and its weight when iterate the graph
 */

    Graph::Graph(string name){
        this->name=name;
    }
    bool Graph::addNode(string name,int x,int y){
        if(mapOfnodes.count(name)== 0)
            mapOfnodes[name]= Node(name,x,y);
        else
            return false;
        return true;
    }
    bool Graph::addEdge(string nameOfEdge,string node1,string node2){
        if(mapOfnodes.count(node1)==0)
            return false;
        if(mapOfnodes.count(node2)== 0)
            return false;
        mapOfEdges[nameOfEdge]= Edge(nameOfEdge,mapOfnodes[node1],mapOfnodes[node2]);
        edges.push_back(mapOfEdges[nameOfEdge]);
        return true;
    }
    void Graph::deleteNode(string nameOfNode){
        //delete edges has this node
        for(auto it = edges.begin(); it != edges.end(); ++it){
            if(it->IsEdgeHasThisNode(nameOfNode)){
                edges.erase(it);
                it--;
            }
        }
        // delete node from vector of node
        for(auto it = nodes.begin(); it != nodes.end(); ++it){
            if(it->getName()==nameOfNode){
                nodes.erase(it);
                break;
            }
        }
        mapOfnodes.erase(nameOfNode);
    }
    bool Graph::deleteEdge(string name){
        mapOfEdges.erase(name);
        for(auto it = edges.begin(); it != edges.end(); ++it){
            if(it->getName()==name){
                edges.erase(it);
                return true;
            }
        }
        return false;
    }
    void Graph::displayEdges(){
        for(auto i:edges){
            cout<<"from: "<<i.getNameOfNode1()<<" to: "<<i.getNameOfNode2()<<" by: "<<i.getName()<<" distance: "<<i.getDistance()<<'\n';
        }

    }
    void Graph::displayNodes(){
        for(auto [a,b]:mapOfnodes){
            cout<<a<<" "<<b.getPoint().getX()<<" "<<b.getPoint().getY()<<'\n';
        }

    }
    void Graph::displayGraph(){
        buildAdjList();
        // okkkkkkkk
    }
    void Graph::buildAdjList(){
        adj.clear();
        for(auto i:edges){
            adj[i.getNameOfNode1()].emplace_back(i.getNameOfNode2(),i.getName());
            adj[i.getNameOfNode2()].emplace_back(i.getNameOfNode1(),i.getName());
        }
    }
    void Graph::deleteGraph(){
        nodes.clear();// store all nodes
        mapOfnodes.clear(); //map all nodes by  name
        edges.clear(); // store all edges
        mapOfEdges.clear();
        adj.clear();
    }
    bool Graph::distanceBetweenTwoNode(){

    }
