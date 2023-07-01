#pragma once
#include <string>

namespace abstract_factory 
{
void AbstractFactoryPattern();

class AbstractProductA {
 public:
  virtual std::string UsefullFunction() const = 0;
  virtual ~AbstractProductA(){};
};
class ProductA1 : public AbstractProductA {
 public:
  ProductA1(){};
  std::string UsefullFunction() const override {
    return std::string("ProductA1\n");
  }
};
class ProductA2 : public AbstractProductA {
 public:
  std::string UsefullFunction() const override {
    return std::string("ProductA2\n");
  }
};

class AbstractProductB {
 public:
  virtual std::string UsefullFunction() const = 0;
  virtual ~AbstractProductB(){};
};
class ProductB1 : public AbstractProductB {
 public:
  std::string UsefullFunction() const override {
    return std::string("ProductB1\n");
  }
};
class ProductB2 : public AbstractProductB {
 public:
  std::string UsefullFunction() const override {
    return std::string("ProductB2\n");
  }
};


class AbstractFactory {
 public:
  virtual AbstractProductA* CreateProdA() const = 0;
  virtual AbstractProductB* CreateProdB() const = 0;
};
/**
 * Concrete Factories produce a family of products that belong to a single
 * variant. The factory guarantees that resulting products are compatible. Note
 * that signatures of the Concrete Factory's methods return an abstract product,
 * while inside the method a concrete product is instantiated.
 */
class ConcreteFactoryA : public AbstractFactory {
 public:
  ConcreteFactoryA(){};
  ~ConcreteFactoryA(){};
  AbstractProductA* CreateProdA() const override { return new ProductA1(); };
  AbstractProductB* CreateProdB() const override { return new ProductB1(); };
};
class ConcreteFactoryB : public AbstractFactory {
 public:
  AbstractProductA* CreateProdA() const override { return new ProductA2(); };
  AbstractProductB* CreateProdB() const override { return new ProductB2(); };
};



}