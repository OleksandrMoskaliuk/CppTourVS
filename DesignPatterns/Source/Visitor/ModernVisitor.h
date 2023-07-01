#pragma once
#include <iostream>
#include <variant>
#include <vector>
namespace modern_visitor {

class Circle;
class Square;
using Shape = std::variant<Circle, Square>;

class Circle {
 public:
  explicit Circle(float rad)
      : radius{rad}  // initialize radius
        {};

  float getRadius() { return radius; }
  // get center , get rotation etc...
 private:
  float radius;
};

class Square {
 public:
  explicit Square(double s) : side{s} {};
  double getSide() { return side; }

 private:
  double side;
};

// Visitor operations 
class Draw {
 public:
  void operator()(Circle & circle) const {
    std::cout << "circle radius = " << circle.getRadius()
    << std::endl;
  };
  void operator()(Square & square) const { 
   std::cout << "square size = " << square.getSide() << std::endl;
  };
};


//

}  // namespace modern_visitor