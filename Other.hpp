#include <iostream>
using namespace std;

class Point {
private:
  float x;
  float y;

public:
  Point();
  Point(float _x, float _y);
  Point(const Point &_p);
  float getX() const;
  float getY() const;
  void setX(float _x);
  void setY(float _y);
  void translater(Point _p);
  void translater(float dx, float dy);
  void affiche();
  void operator+=(Point const& _p);
};

ostream &operator<<(ostream &s, Point const &_point);