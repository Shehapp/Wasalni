#import "../Algorithm/Dfs.h"
#import "../Algorithm/Dijkstra.h"
#import "../Algorithm/Floyd.h"

class App {
public:
    Graph *graph;
    Dfs *dfs;
    Floyd *floyd;
    Dijkstra *dijkstra;

    explicit App(Graph *graph);


    void chooseCities() const;

    void algorithmTypes(string from, string to) const;

    static int mainMenu();

    void updateMap() const;

    void start() const;
};


