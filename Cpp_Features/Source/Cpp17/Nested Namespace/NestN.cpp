#include "NestN.h"

namespace nested_namespaces {

/////////////////////// Before Cpp17 ///////////////////////
namespace world {
namespace character {
namespace attributes {
class Atributes {
 public:
  Atributes();
  ~Atributes();

 private:
};

Atributes::Atributes() {}

Atributes::~Atributes() {}
}  // namespace attributes
}  // namespace character
}  // namespace world

   /////////////////////// After Cpp17 ///////////////////////
/* do the same in more clear way */
namespace cpp17_world::character::attributes 
{
class Atributes {
 public:
  Atributes();
  ~Atributes();
 private:
};

Atributes::Atributes() {}

Atributes::~Atributes() {}
}


}  // namespace nested_namespaces