#pragma once
#include <string>
/*
Visitor is a behavioral design pattern that lets you separate algorithms from
the objects on which they operate.
*/
namespace visitor {
void visitor();
}
class ComponentA;
class ComponentB;
class ComponentC;

class Visitor {
 public:
  virtual void VisitComponentA(const ComponentA* comp) const = 0;
  virtual void VisitComponentB(const ComponentB* comp) const = 0;
  virtual void VisitComponentC(const ComponentC* comp) const = 0;
};

#include <iostream>
class VisitorImpl : public Visitor {
 public:
  void VisitComponentA(const ComponentA* comp) const override {
    std::cout << " visited " << comp->ComponentAFunc() << std::endl;
  };
  void VisitComponentB(const ComponentB* comp) const override {
    std::cout << " visited " << comp->ComponentBFunc() << std::endl;
  };
  void VisitComponentC(const ComponentC* comp) const override {
    std::cout << " visited " << comp->ComponentCFunc() << std::endl;
  };
};

class Component {
 public:
  virtual void Accept(Visitor* visitor) const = 0;
  virtual ~Component(){};
};

class ComponentA : public Component {
 public:
  void Accept(Visitor* visitor) const override {
    visitor->VisitComponentA(this);
  }

  std::string ComponentAFunc() const { return "ComponentA"; }
};

class ComponentB : public Component {
 public:
  void Accept(Visitor* visitor) const override {
    visitor->VisitComponentB(this);
  }

  std::string ComponentBFunc() const { return "ComponentB"; }
};

class ComponentC : public Component {
 public:
  void Accept(Visitor* visitor) const override {
    visitor->VisitComponentC(this);
  }

  std::string ComponentCFunc() const { return "ComponentC"; }
};

