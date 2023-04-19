#pragma once
#import "classes/Graph.h"
#import "classes/Algorithm/Dfs.h"
#import "classes/Algorithm/Dijkstra.h"
#import "classes/Algorithm/Floyd.h"

class App {
public:
    Graph *graph;
    Dfs *dfs;
    Floyd *floyd;
    Dijkstra *dijkstra;
    App(Graph *graph){
        this->graph = graph;
        dfs = new Dfs(graph);
        floyd = new Floyd(graph);
        dijkstra = new Dijkstra(graph);
    }


    void chooseCities() {
        graph->displayGraph();

        cout << "-----------------------------------------\n";
        string city1, city2;
        cout << "Enter source and destination cities: ";
        cin >> city1 >> city2;

        algorithmTypes(city1, city2);

        cout << "";
    }

    void algorithmTypes(string from, string to) {
        int algorithm;
        while (true) {
            cout << "1.BFS\n";
            cout << "2.Floyd\n";
            cout << "3.Dijkstra\n";
            cout << "4.exit\n";
            cin >> algorithm;
            if (algorithm == 1)
                dfs->run(from, to);
            else if (algorithm == 2)
                floyd->run(from, to);
            else if (algorithm == 3)
                dijkstra->run(from, to);
            else if (algorithm == 4)
                break;
            else
                cout << "Enter a valid number(1:4)\n";
        }
        cout<<'\n';

    }
    int mainMenu() {
        int choice;
        cout << "Mini-Wasalny\n";
        cout << "------------------------------------------\n";
        cout << "1.Update Map\n";
        cout << "2.Create New Map\n";
        cout<<  "3.Shortest Path\n";
        cout<<  "4.show map\n";
        cout << "5.exit\n";
        cin >> choice;
        cout<<'\n';
        return choice;
    }
    void updateMap() {
        int choice;
        do {
            cout << "1.Add City\n";
            cout << "2.Add Path\n";
            cout << "3.Delete City\n";
            cout << "4.Delete Path\n";
            cout << "5.Delete Map\n";
            cout << "6.exit\n";
            cout<<'\n';

            cin >> choice;
            if (choice == 1) {
                cout<<'\n';
                string name;
                int x, y;
                cout << "Enter city name: ";
                cin >> name;
                cout << "Enter city x: ";
                cin >> x;
                cout << "Enter city y: ";
                cin >> y;
               if(!graph->addNode(name, x, y)){
                     cout<<"can't add node\n";
               }
                cout<<'\n';

            } else if (choice == 2) {
                string from, to;
                int distance;
                cout << "Enter source city: ";
                cin >> from;
                cout << "Enter destination city: ";
                cin >> to;
                if (!graph->addEdge(from, to)){
                    cout<<"can't add edge\n";
                }
                cout<<'\n';

            } else if (choice == 3) {
                string name;
                cout << "Enter city name: ";
                cin >> name;
                graph->deleteNode(name);
                cout<<'\n';

            } else if (choice == 4) {
                string from, to;
                cout << "Enter source city: ";
                cin >> from;
                cout << "Enter destination city: ";
                cin >> to;
                graph->deleteEdge(from, to);
            } else if (choice == 5) {
                graph->deleteGraph();
            } else if (choice == 6) {
                break;
            } else {
                cout << "Enter a valid number(1:6)\n";
            }
        } while (choice != 6);
        cout<<'\n';

    }
    void start() {
        int startChoice;
        do {
            startChoice = mainMenu();
            if (startChoice == 1)
                updateMap();
            if (startChoice == 2)
            {
                graph->deleteGraph();
                updateMap();
            }
            if (startChoice == 3)
                chooseCities();
            if (startChoice == 4)
                graph->displayGraph();
        } while (startChoice != 5);

    }
};


int main() {
    Graph *graph = new Graph();
    App *app = new App(graph);
    app->start();
    return 0;

}
/*
A 1 0
B 4 0
C 7 0
D 3 0
E 0 0
s
A B
A D
A C
B C
C E
D E
s s


 */