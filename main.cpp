#include <bits/stdc++.h>

using namespace std;


///imagine graph as Country , streets as edge and Cites as nodes


///location of City
class Point{
private:
    int x;
    int y;
public:
    Point(){}
    Point(int x,int y){
        this->x=x;
        this->y=y;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
};

/// any City has name and location
class Node{
private:
    Point point;
    string name;
public:
    Node(){}
    Node(string name,int x,int y){
        this->name=name;
        this->point=Point(x,y);
    }
    string getName(){
        return this->name;
    }
    Point getPoint(){
        return point;
    }
};

/// any street has name and length
class Edge{
private:
    string name;
    Node node1;
    Node node2;
    double distance;
public:
    Edge(){}
    Edge(string name,Node node1,Node node2){
        this->name=name;
        this->node1=node1;
        this->node2=node2;
        //weight of edge hence,f
        CalcDistance();
    }
    double getDistance(){
        return this->distance;
    }
    string getName(){
        return name;
    }
    string getNameOfNode1(){
        return node1.getName();
    }
    string getNameOfNode2(){
        return node2.getName();
    }
    bool IsEdgeHasThisNode(string nodeToCheck){
        return (nodeToCheck==getNameOfNode1()) || (nodeToCheck==getNameOfNode2());
    }


private:
    void CalcDistance(){
        this->distance= sqrt(pow(node1.getPoint().getX()-node2.getPoint().getX(),2)+
                             pow(node1.getPoint().getY()-node2.getPoint().getY(),2));
    }
};

// any Country has name
/*
 we stored graph as edges buz easy to delete and upd (nodes and edges),
 and after maintain this graph will turn it into adj list.
 everytime the graph get upd and the user have finished, the vector of edges will turn to
 adj :(

 this means we know names of nodes and name of edge and its weight when iterate the graph
 */
class Graph{
private:

    string name;//name of graph aka city
    vector<Node>nodes;// store all nodes
    map<string ,Node>mapOfnodes; //map all nodes by  name
    vector<Edge>edges; // store all edges
    map<string ,Edge>mapOfEdges; //map all Edges by  name

    //               (name of node, name of edge)
    map<string ,vector<pair<string,string>>>adj; //adj list store node.
    // we can get name of nodes and  locations and name of edge and length of edge

public:
    Graph(string name){
        this->name=name;
    }
    bool addNode(string name,int x,int y){
        if(mapOfnodes.count(name)== 0)
            mapOfnodes[name]= Node(name,x,y);
        else
            return false;
        return true;
    }
    bool addEdge(string nameOfEdge,string node1,string node2){
        if(mapOfnodes.count(node1)==0)
            return false;
        if(mapOfnodes.count(node2)== 0)
            return false;
        mapOfEdges[nameOfEdge]= Edge(nameOfEdge,mapOfnodes[node1],mapOfnodes[node2]);
        edges.push_back(mapOfEdges[nameOfEdge]);
        return true;
    }
    void deleteNode(string nameOfNode){
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
    bool deleteEdge(string name){
        mapOfEdges.erase(name);
        for(auto it = edges.begin(); it != edges.end(); ++it){
            if(it->getName()==name){
                edges.erase(it);
                return true;
            }
        }
        return false;
    }
    void displayEdges(){
        for(auto i:edges){
            cout<<"from: "<<i.getNameOfNode1()<<" to: "<<i.getNameOfNode2()<<" by: "<<i.getName()<<" distance: "<<i.getDistance()<<'\n';
        }

    }
    void displayNodes(){
        for(auto [a,b]:mapOfnodes){
            cout<<a<<" "<<b.getPoint().getX()<<" "<<b.getPoint().getY()<<'\n';
        }

    }
    void displayGraph(){
        buildAdjList();
        // okkkkkkkk
    }
    void buildAdjList(){
        adj.clear();
        for(auto i:edges){
            adj[i.getNameOfNode1()].emplace_back(i.getNameOfNode2(),i.getName());
            adj[i.getNameOfNode2()].emplace_back(i.getNameOfNode1(),i.getName());
        }
    }
    void deleteGraph(){
        nodes.clear();// store all nodes
        mapOfnodes.clear(); //map all nodes by  name
        edges.clear(); // store all edges
        mapOfEdges.clear();
        adj.clear();
    }
    bool distanceBetweenTwoNode(){

    }
};


int main(){
    Graph graph("Egypt");
    cout<<"add Cites"<<":\n";
    while (true){
        string name;
        cin>>name;
        if(name=="s")break;
        int x,y;
        cin>>x>>y;
        graph.addNode(name,x,y);
    }
    cout<<"add Street from those Cites "<<":\n";
    graph.displayNodes();
    while (true){
        string name,name1,name2;
        cin>>name>>name1>>name2;
        if(name=="s")break;
        graph.addEdge(name,name1,name2);
    }
    //graph.displayEdges();
    graph.deleteNode("shehap");
    graph.displayNodes();

    //graph.displayEdges();
}
/*
shehap 1 2
mohamed 3 6
momen 5 2
osama 7 9
ahmed 2 6
s
one shehap osama
two shehap momen
three ahmed mohamed
four osama ahmed
five shehap ahmed
s s s

 */