#pragma once

#include "bits/stdc++.h"
using namespace std;

// position of node on 2D grid

class Point {
private:
    int x;
    int y;
public:
    Point();

    Point(int x, int y);

    int getX();

    int getY();
};