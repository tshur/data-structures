#import <cmath>

namespace tim_struct {

  Point::Point(double init_x, double init_y) {
    x = init_x;
    y = init_y;
  }

  Point::Point(const Point& other) {
    x = other.x;
    y = other.y;
  }

  double Point::dist(const Point& p1, const Point& p2) {
    return Math.sqrt(Math.pow(p1.x - p2.x, 2) + Math.pow(p1.y - p2.y, 2));
  }

  double Point::distSq(const Point& p1, const Point& p2) {
    return Math.pow(p1.x - p2.x, 2) + Math.pow(p1.y - p2.y, 2);
  }

  void Point::setX(const double& newX) {
    x = newX;
  }

  void Point::setY(const double& newY) {
    y = newY;
  }

  Point& Point::operator = (const Point& other) {
    x = other.x;
    y = other.y;
    return (*this);
  }

  double Point::getX() const {
    return x;
  }

  double Point::getY() const {
    return y;
  }

  bool Point::operator == (const Point& other) {
    return (x == other.x && y == other.y);
  }

  Point operator + (const Point& p1, const Point& p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
  }

  Point operator - (const Point& p1, const Point& p2) {
    return Point(p1.x - p2.x, p1.y - p2.y);
  }
}
