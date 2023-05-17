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

void ModernVisitor() {
  using Shapes = std::vector<Shape>;
  Shapes shapes;
  shapes.emplace_back(Circle(34.2f));
  shapes.emplace_back(Circle(23.1f));
  shapes.emplace_back(Square(11.5f));
  auto lb = [&]() {
    for (auto & s : shapes) {
      std::visit(Draw(), s);
    }
  };
  lb();
}

//

}  // namespace modern_visitor