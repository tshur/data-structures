// File: point.h
// Created by: Tim Shur
// Description: Header file for the Point class
//
//
// VALUE SEMANTICS for the Point class:
//  The copy constructor and assignment operator are valid for the Point class.
//

#ifndef POINT_CLASS_H
#define POINT_CLASS_H

namespace tim_struct {
  class Point {

  public:
    // CONSTRUCTORS
    Point(double init_x = 0.0, double init_y = 0.0);
    Point(const Point& other);

    // MODIFICATION MEMBER FUNCTIONS
    void setX(const double& newX);
    void setY(const double& newY);
    Point& operator = (const Point& other);

    // CONSTANT MEMBER FUNCTIONS
    double dist(const Point& p1, const Point& p2) const;
    double distSq(const Point& p1, const Point& p2) const;
    double getX() const;
    double getY() const;
    bool operator == (const Point& other);

    // NON-MEMBER OPERATOR OVERLOADING
    Point operator + (const Point& p1, const Point& p2) const;
    Point operator - (const Point& p1, const Point& p2) const;

  private:
    double x;
    double y;
  }
}

#include "point.cxx"
#endif /* POINT_CLASS_H */
