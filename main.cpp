#include <bits/stdc++.h>
#include "classes/Graph.h"
using namespace std;

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
    //graph.deleteNode("shehap");
    //graph.displayNodes();

    graph.displayEdges();
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