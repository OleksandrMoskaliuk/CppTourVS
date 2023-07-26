#include "Delegating constructors.h"
#include <string>

namespace delegating_constructors 
{

 class Person {
 private:
  std::string name;
  int age;

 public:
  Person() : Person("", 0) {
    // Delegating constructor with default values
  }

  Person(const std::string& name) : Person(name, 0) {
    // Delegating constructor with default age
  }

  Person(const std::string& name, int age) : name(name), age(age) {
    // Constructor with complete initialization
  }
};


 void example1() 
 { 
  Person pr; // Using Person first and third constructors
  Person pr2(""); // Using Person second constructors
 }

}