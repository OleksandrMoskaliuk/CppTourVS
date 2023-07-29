#include "StructureBindings.h"
#include <tuple>
#include <string>
#include <iostream>

// How i would deal with this before cpp 17
namespace structure_bindings {

 
std::tuple<int, std::string> GetWeapons() { return {2, "GreatSword"}; }

void example_before17() 
{ 
  int amount = std::get<0>(GetWeapons());
  std::string Item = std::get<1>(GetWeapons());
  // do smth with Item ant it's amount 
}

void example_before17_v2() 
{
  // Or using std::tie
  int amount = 0;
  std::string Item;
  std::tie(amount, Item) = GetWeapons();
  // do smth with Item ant it's amount
}

// After cpp17 release or how "Structure bindings" works
void example_Cpp17() {
  // Code looks much more clean
  auto[amount, Item] = GetWeapons();
  // do smth with Item ant it's amount, for example print it
  std::cout << "Item = " << Item << "\nAmount = " << amount;

}

}  // namespace structure_bindings