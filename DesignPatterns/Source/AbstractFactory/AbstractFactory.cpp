#include "AbstractFactory.h"
#include <iostream>

namespace abstract_factory {

/**
 * The client code works with factories and products only through abstract
 * types: AbstractFactory and AbstractProduct. This lets you pass any factory or
 * product subclass to the client code without breaking it.
 */
void ClientCode(AbstractFactory* AbstractFactory) {
  AbstractProductA* A = AbstractFactory->CreateProdA();
  AbstractProductB* B = AbstractFactory->CreateProdB();
  std::cout << A->UsefullFunction();
  std::cout << B->UsefullFunction();
  delete A;
  delete B;
}

void AbstractFactoryPattern() {
  AbstractFactory* af1 = new ConcreteFactoryA();
  AbstractFactory* af2 = new ConcreteFactoryB();
  ClientCode(af1);
  ClientCode(af2);
}

}  // namespace abstract_factory