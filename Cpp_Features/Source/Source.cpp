//C++11:
//
//Lambda expressions
//Range-based for loops
//Move semantics
//Smart pointers
//constexpr keyword
//Variadic templates
//Uniform initialization syntax
//Type inference using auto keyword
//nullptr keyword
//Delegating constructors
//Example of lambda expression:
//
//auto add = [](int x, int y) -> int {
//  return x + y; };
//int result = add(3, 4);  // result is 7
//C++14:
//
//Generic lambdas
//Return type deduction for functions
//Binary literals
//Variable templates
//Digit separators
//decltype(auto) keyword
//Polymorphic lambdas
//Example of generic lambda:
//
//auto add = [](auto x, auto y) {
//  return x + y; };
//int result1 = add(3, 4);         // result1 is 7
//double result2 = add(3.5, 4.2);  // result2 is 7.7
//C++ 17 :
//
//    Structured bindings constexpr if statement Fold expressions Inline variables
//        Nested namespaces std::optional type std::variant type std::any type
//            Parallel algorithms Example of structured bindings :
//
//    std::pair<int, double>
//        p = {42, 3.14};
//auto [x, y] = p;
//std::cout << x << " " << y;  // prints "42 3.14"
//C++ 20 :
//
//    Concepts Ranges library Coroutines Modules Three -
//    way comparison operator std::span type std::format function
//        std::stop_token type Synchronized output streams Example of concepts :
//
//    template <typename T>
//    concept Integral = std::is_integral_v<T>;
//
//template <Integral T>
//T add(T x, T y) {
//  return x + y;
//}
//
//int result1 = add(3, 4);         // result1 is 7
//double result2 = add(3.5, 4.2);  // error: double is not an Integral type

int main() 
{ 
 return 0;
}