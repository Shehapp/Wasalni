#pragma once
#import "classes/Application/App.h"


int main() {
    Graph *graph = new Graph();
    App *app = new App(graph);
    app->start();
    return 0;

}