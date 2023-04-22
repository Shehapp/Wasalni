#pragma once
#import "classes/Application/App.h"
void readFile(Graph *graph){
    //read nodes
    ifstream nodes("Nodes.txt");
    string name;
    int x,y;
    while (nodes>>name>>x>>y){
        graph->addNode(name,x,y);
    }
    // add edges
    ifstream edges("Edges.txt");
    string n1,n2;
    while (edges>>n1>>n2){
        graph->addEdge(n1,n2);
    }
}

void saveFile(Graph *graph){
    //add nodes
    ofstream nodes("Nodes.txt");
    for(auto n:graph->mapOfnodes){
        string name=n.second.getName();
        int x= n.second.getPoint().getX();
        int y =n.second.getPoint().getY();
        nodes<<name<<" "<<x<<" "<<y<<'\n';
    }
    // add edges
    ofstream edges("Edges.txt");
    map<pair<string, string>,bool>isAdded;
    for(auto s:graph->adj){
        for(auto v:s.second){
            if(!isAdded[{v.first,s.first}]){
                isAdded[{s.first,v.first}]= true;
                edges<<v.first<<" "<<s.first<<'\n';
            }
        }
    }

}

int main() {

    // initialize object graph
    Graph *graph=new Graph();

    //read data from graph.txt file
    readFile(graph);

    //send graph as argument
    App *app = new App(graph);
    app->start();

    // write data into graph.txt file
    saveFile(graph);

    return 0;
}