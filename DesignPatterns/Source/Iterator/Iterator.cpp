#include "Iterator.h"

namespace IteratorPattern {

/**
 * The client code may or may not know about the Concrete Iterator or Collection
 * classes, for this implementation the container is generic so you can used
 * with an int or with a custom class.
 */

void iterator_pattern() {
  std::cout << "________________Iterator with "
               "int______________________________________"
            << std::endl;
  CustomContainer<int> cont;

  for (int i = 0; i < 10; i++) {
    cont.Add(i);
  }

  Iterator<int, CustomContainer<int>> *it = cont.CreateIterator();
  for (it->First(); !it->IsDone(); it->Next()) {
    std::cout << *it->Current() << std::endl;
  }

  std::cout << "________________Iterator with custom "
               "Class______________________________"
            << std::endl;

  CustomContainer<Data> cont2;
  Data a(100), b(1000), c(10000);
  cont2.Add(a);
  cont2.Add(b);
  cont2.Add(c);

  Iterator<Data, CustomContainer<Data>> *it2 = cont2.CreateIterator();
  for (it2->First(); !it2->IsDone(); it2->Next()) {
    std::cout << it2->Current()->data() << std::endl;
  }
  delete it;
  delete it2;
}

}  // namespace IteratorPattern