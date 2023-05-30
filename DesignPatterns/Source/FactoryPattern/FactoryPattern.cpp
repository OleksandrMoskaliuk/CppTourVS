#include "FactoryPattern.h"

namespace FactoryPattern {

int FactoryPattern() {
  std::string type;
  Toy* v = NULL;
  while (true) {
    std::cin >> type;
    std::cout << "\n";
    v = ToyFactory::createToy(type);

    if (type == "x") {
      if (v != (nullptr)) {
        delete v;
      }
      break;
    }
  }
  return 0;
}

}  // namespace FactoryPattern