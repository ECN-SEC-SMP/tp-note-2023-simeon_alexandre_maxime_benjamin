#include "Other.hpp"

Point::Point() {
  x = 0;
  y = 0;
}

Point::Point(float _x, float _y) {
  x = _x;
  y = _y;
}

Point::Point(const Point &_p) : x(_p.x), y(_p.y) {
  cout << "copie de Point" << endl;
}

float Point::getX() const { return x; }

float Point::getY() const { return y; }

void Point::setX(float _x) { x = _x; }

void Point::setY(float _y) { y = _y; }

void Point::translater(Point _p) {
  x += _p.getX();
  y += _p.getY();
}

void Point::translater(float dx, float dy) {
  x += dx;
  y += dy;
}

void Point::affiche() { cout << x << " ; " << y << endl; }

void Point::operator+=(Point const& _p){
  x += _p.getX();
  y += _p.getY();
}

ostream &operator<<(ostream &s, Point const &_point) {
  s << _point.getX() << " ; " << _point.getY();
  return s;
}