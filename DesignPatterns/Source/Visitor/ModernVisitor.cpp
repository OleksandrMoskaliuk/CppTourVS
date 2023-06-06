#include "ModernVisitor.h"

namespace modern_visitor {

void ModernVisitor() {
  using Shapes = std::vector<Shape>;
  Shapes shapes;
  shapes.emplace_back(Circle(34.2f));
  shapes.emplace_back(Circle(23.1f));
  shapes.emplace_back(Square(11.5f));
  auto lb = [&]() {
    for (auto& s : shapes) {
      std::visit(Draw(), s);
    }
  };
  lb();
}


}  // namespace modern_visitor