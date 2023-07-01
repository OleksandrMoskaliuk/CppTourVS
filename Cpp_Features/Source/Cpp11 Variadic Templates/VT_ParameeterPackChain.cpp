#include "VariadicTemplates.h"
namespace variadic_templates 
{

template <typename T>
T bar(T t) {
  /*...*/
  std::cout << t << "\n";
  return t;
}

char bar(char ch) {
  std::cout << "I'm char " << ch << "\n";
  return ch;
}

int bar(int nt) {
  std::cout << "I'm integer " << nt << "\n";
  return nt;
}

float bar(float fl) {
  std::cout << "I'm float " << fl << "\n";
  return fl;
}

template <typename... T>
void bar(T... t) {
  /*...*/
  bar(t...);
  return;
}

template <typename... Args>
void foo(Args... args) {
  //...
  bar(args...);
}

template <typename... Args>
void foo2(Args... args) {
  foo(bar(args)...);
}

 void ParamPackChain() 
 {
    
  foo2('1', 2, 3.f);
  return;
 }

}