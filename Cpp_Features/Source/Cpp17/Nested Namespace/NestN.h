#pragma once

/*
Nested Namespaces: C++17 allows you to create nested namespaces in a more
concise and readable way.
*/

namespace nested_namespaces {
// Before Cpp 17 //
namespace world {
namespace character {
namespace attributes {
class Atributes;
}
}  // namespace character
}  // namespace world

// After Cpp 17
namespace cpp17_world::character::attributes 
{
class Atributes;
}
}  // namespace nested_namespaces