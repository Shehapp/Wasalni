#include "Point.h"

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

