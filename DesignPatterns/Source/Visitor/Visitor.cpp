#include "Visitor.h"
#include <array>

namespace visitor 
{

 void visitor() 
 { 
  std::array<Component*, 4> compnents = {new ComponentA, new ComponentB, new ComponentC};

  VisitorImpl *vi = new VisitorImpl;

  for (Component* cmp : compnents) {
    cmp->Accept(vi);
  }

 }


}
