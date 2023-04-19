

#include "Point.h"

///location of City
//imagine graph as Country , streets as edge and Cites as nodes

///location of City
Point::Point() {}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

