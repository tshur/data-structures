// FILE: point.cpp
// AUTHOR: Tim Shur
// IMPLEMENTS: The functions of the Point class (see point.h for documentation)


#include <cmath>     // Provides sqrt and pow
#include <iostream>  // Provides ostream
#include "point.h"


namespace tim_struct
{

    // CONSTRUCTOR AND COPY CONSTRUCTOR
    Point::Point(const double& init_x, const double& init_y) {
        x = init_x;
        y = init_y;
    }

    Point::Point(const Point& other) {
        x = other.x;
        y = other.y;
    }

    // MODIFICATION MEMBER FUNCTIONS
    void Point::setX(const double& newX) {
        x = newX;
    }

    void Point::setY(const double& newY) {
        y = newY;
    }

    void Point::shift(const double& other_x, const double& other_y) {
        x += other_x;
        y += other_y;
    }

    void Point::operator += (const Point& other) {
        x += other.x;
        y += other.y;
    }

    Point& Point::operator = (const Point& other) {
        x = other.x;
        y = other.y;
        return (*this);
    }

    // CONSTANT MEMBER FUNCTIONS
    double Point::dist(const Point& other) const {
    // Library facilities used: cmath

        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    double Point::distSq(const Point& other) const {
    // Library facilities used: cmath

        return pow(x - other.x, 2) + pow(y - other.y, 2);
    }

    double Point::getX() const {
        return x;
    }

    double Point::getY() const {
        return y;
    }

    // NON-MEMBER FUNCTIONS
    double dist(const Point& p1, const Point& p2) {
    // Library facilities used: cmath

        return sqrt(pow(p1.getX() - p2.getX(), 2) +
                    pow(p1.getY() - p2.getY(), 2));
    }

    double distSq(const Point& p1, const Point& p2) {
    // Library facilities used: cmath

        return pow(p1.getX() - p2.getX(), 2) +
               pow(p1.getY() - p2.getY(), 2);
    }

    bool operator == (const Point& p1, const Point& p2) {
        return (p1.getX() == p2.getX() && p1.getY() == p2.getY());
    }

    bool operator != (const Point& p1, const Point& p2) {
        return (p1.getX() != p2.getX() || p1.getY() != p2.getY());
    }

    Point operator + (const Point& p1, const Point& p2) {
        return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY());
    }

    Point operator - (const Point& p1, const Point& p2) {
        return Point(p1.getX() - p2.getX(), p1.getY() - p2.getY());
    }

    std::ostream& operator <<(std::ostream& outs, const Point& p) {
        outs << "Point(" << p.getX() << ", " << p.getY() << ")";
        return outs;
    }
}
