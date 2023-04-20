#pragma once
#import "classes/Application/App.h"


int main() {
    App *app = new App(new Graph());
    app->start();
    return 0;

}