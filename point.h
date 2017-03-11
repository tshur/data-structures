// FILE: point.h
// AUTHOR: Tim Shur
// PROVIDES: A class for a Point with 2D Cartesian coordinates within the
//     namespace tim_struct.
//
// INVARIANT for the Point class:
//     The Cartesian x and y coordinates are stored in variables x and y,
//     respectively.
//
// CONSTRUCTORS for the Point class:
//     Point(double init_x = 0.0, double init_y = 0.0)
//         Postcondition: The Point has been created with
//         (x, y) = (init_x, init_y). The default is a Point on the origin.
//
//     Point(const Point& other)
//         Postcondition: The Point is a copy of the Point other.
//
// MODIFICATION MEMBER FUNCTIONS for the Point class:
//     void setX(const double& newX)
//          Postcondition: x has been set to the value of newX.
//
//     void setY(const double& newY)
//          Postcondition: y has been set to the value of newY.
//
//     void shift(const double& other_x = 1.0, const double& other_y = 1.0)
//          Postcondition: x and y have been shifted by other_x and other_y,
//          respectively. The default shift is one unit in each direction.
//
//     void operator += (const Point& other)
//          Postcondition: x and y have been shifted by other.x and other.y,
//          respectively.
//
//     Point& operator = (const Point& other)
//          Postcondition: The Point has been assigned to be equal to the
//          Point other.
//
// CONSTANT MEMBER FUNCTIONS for the Point class:
//     double dist(const Point& other) const
//          Postcondition: Returns the distance between the Point and other.
//
//     double distSq(const Point& other) const
//          Postcondition: Returns the square of the distance between
//          the Point and other.
//
//     double getX() const
//          Postcondition: Returns the value of x.
//
//     double getY() const
//          Postcondition: Returns the value of y.
//
// NON-MEMBER FUNCTIONS for the Point class:
//     double dist(const Point& p1, const Point& p2) const
//          Postcondition: Returns the distance between Points p1 and p2.
//
//     double distSq(const Point& p1, const Point& p2) const
//          Postcondition: Returns the square of the distance between Points
//          p1 and p2.
//
//     bool operator == (const Point& p1, const Point& p2) const
//          Postcondition: Returns true if p1 and p2 have the same x and y
//          coordinates.
//
//     bool operator != (const Point& p1, const Point& p2) const
//          Postcondition: Returns false if p1 and p2 have the same x and y
//          coordinates.
//
//     Point operator + (const Point& p1, const Point& p2) const
//          Postcondition: Returns a Point with the sum of the coordinates of
//          Points p1 and p2.
//
//     Point operator - (const Point& p1, const Point& p2) const
//          Postcondition: Returns a Point with the difference of the
//          coordinates of Points p1 and p2.
//
//
// VALUE SEMANTICS for the Point class:
//     The copy constructor and assignment operator are valid for the Point
//     class.


#ifndef POINT_CLASS_H
#define POINT_CLASS_H

namespace tim_struct
{
    class Point
    {
    public:
        // CONSTRUCTOR and COPY CONSTRUCTOR
        Point(const double& init_x = 0.0, const double& init_y = 0.0);
        Point(const Point& other);

        // MODIFICATION MEMBER FUNCTIONS
        void setX(const double& newX);
        void setY(const double& newY);
        void shift(const double& other_x = 1.0, const double& other_y = 1.0);
        void operator += (const Point& other);
        Point& operator = (const Point& other);

        // CONSTANT MEMBER FUNCTIONS
        double dist(const Point& other) const;
        double distSq(const Point& other) const;
        double getX() const;
        double getY() const;

    private:
        double x;
        double y;
    };

    // NON-MEMBER FUNCTIONS for the Point class
    double dist(const Point& p1, const Point& p2) const;
    double distSq(const Point& p1, const Point& p2) const;
    bool operator == (const Point& p1, const Point& p2) const;
    bool operator != (const Point& p1, const Point& p2) const;
    Point operator + (const Point& p1, const Point& p2) const;
    Point operator - (const Point& p1, const Point& p2) const;
}

#include "Point.cxx"
#endif /* POINT_CLASS_H */
