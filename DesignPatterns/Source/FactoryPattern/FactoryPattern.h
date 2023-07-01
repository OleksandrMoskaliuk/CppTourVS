#pragma once

#include <iostream>
#include <string>

namespace FactoryPattern {

class Toy {
 protected:
  std::string name;
  float price;

 public:
  virtual void prepareParts() = 0;
  virtual void combineParts() = 0;
  virtual void assembleParts() = 0;
  virtual void applyLabel() = 0;
  virtual void showProduct() = 0;
};

class Car : public Toy {
  // make all constructor private or protected !!
 public:
  void prepareParts() {
    std::cout << "Preparing car parts "
              << "\n";
  }
  void combineParts() {
    std::cout << "Combine car  parts "
              << "\n";
  }
  void assembleParts() {
    std::cout << "Assemble car parts "
              << "\n";
  }
  void applyLabel() {
    std::cout << "Apply car parts "
              << "\n";
  }
  void showProduct() {
    std::cout << "Show car parts "
              << "\n";
  }
};

class Robot : public Toy {
  // make all constructor private or protected !!
 public:
  void prepareParts() {
    std::cout << "Preparing Robot parts "
              << "\n";
  }
  void combineParts() {
    std::cout << "Combine Robot  parts "
              << "\n";
  }
  void assembleParts() {
    std::cout << "Assemble Robot parts "
              << "\n";
  }
  void applyLabel() {
    std::cout << "Apply Robot parts "
              << "\n";
  }
  void showProduct() {
    std::cout << "Show Robot parts "
              << "\n";
  }
};

class ToyFactory {
 public:
  // Use static, because you don't need to create object of the factory
  static Toy* createToy(const std::string& type) {
    Toy* object_p = nullptr;
    if (type == "car") {
      object_p = new Car();
    } else if (type == "robot") {
      object_p = new Robot();
    } else {
      std::cout << "ERROR types is not mach";
      return nullptr;
    }
    object_p->prepareParts();
    object_p->combineParts();
    object_p->assembleParts();
    object_p->applyLabel();
    object_p->showProduct();
    return object_p;
  }
};

}  // namespace FactoryPattern