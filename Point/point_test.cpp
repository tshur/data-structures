// FILE: point_test.cpp
// AUTHOR: Tim Shur
// TEST FILE for the Point class

#include <iostream>
#include "point.h"

using namespace tim_struct;

int main() {
    Point p0;
    Point p1;
    Point p2(3, 4);
    Point p3(p1);
    Point p4(p2);

    std::cout << p1 << "\t" <<
                 p2 << "\t" <<
                 p3 << "\t" <<
                 p4 << "\t" << std::endl;

    p1.setX(10);
    p1.setY(10);
    p1.shift();
    p3.shift(10, 10);
    p3 += p1;
    p4 = p3;
    std::cout << p2.dist(p0) << std::endl;
    std::cout << p2.distSq(p0) << std::endl;
    std::cout << "(" << p2.getX() << ", " << p2.getY() << ")" << std::endl;

    std::cout << p1 << "\t" <<
                 p2 << "\t" <<
                 p3 << "\t" <<
                 p4 << "\t" << std::endl;

    std::cout << (p3 == p4) << "   " << (p1 == p2) << std::endl;
}
