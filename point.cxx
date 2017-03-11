// FILE: point.cxx
// AUTHOR: Tim Shur
// IMPLEMENTS: The functions of the Point class (see point.h for documentation)


#include <cmath>

namespace tim_struct
{

    // CONSTRUCTOR AND COPY CONSTRUCTOR
    Point::Point(double init_x, double init_y) {
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
        return Math.sqrt(Math.pow(x - other.x, 2) + Math.pow(y - other.y, 2));
    }

    double Point::distSq(const Point& other) const {
        return Math.pow(x - other.x, 2) + Math.pow(y - other.y, 2);
    }

    double Point::getX() const {
        return x;
    }

    double Point::getY() const {
        return y;
    }

    // NON-MEMBER FUNCTIONS
    double dist(const Point& p1, const Point& p2) const {
        return Math.sqrt(Math.pow(p1.getX() - p2.getX(), 2) +
                         Math.pow(p1.getY() - p2.getY(), 2));
    }

    double distSq(const Point& p1, const Point& p2) const {
        return Math.pow(p1.getX() - p2.getX(), 2) +
               Math.pow(p1.getY() - p2.getY(), 2);
    }

    bool operator == (const Point& p1, const Point& p2) const {
        return (p1.getX() == p2.getX() && p1.getY() == p2.getY());
    }

    bool operator != (const Point& p1, const Point& p2) const {
        return (p1.getX() != p2.getX() || p1.getY() != p2.getY());
    }

    Point operator + (const Point& p1, const Point& p2) const {
        return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY());
    }

    Point operator - (const Point& p1, const Point& p2) const {
        return Point(p1.getX() - p2.getX(), p1.getY() - p2.getY());
    }
}
