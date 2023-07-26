#include "UniquePointer.h"
#include <iostream>

namespace unique_pointer 
{

 template <class T>
UniquePointer<T> ret_rvalue_unique_ptr(T val) 
{
  return UniquePointer<T> (new T(val));
}

void example() 
{

 // Usual constructor
 UniquePointer<int> up1(new int(10));

 // Not allowed to pass another value 
 UniquePointer<int> up2(new int(5));
 UniquePointer<int> up3(new int(20));
 //up3 = up2; error
 //up3(up2); error

 // Only rvalue allowed to pass, that will swap current resource with it own
 UniquePointer<int> up4(new int(8));
 UniquePointer<int> up5(new int(9));
 // usage of assign operator <rvalues>
 up4 = std::move(UniquePointer<int>(new int(10)));
 // usage of move constructor <rvalues>
 UniquePointer<int> up6(std::move(UniquePointer<int>(new int(10))));
 UniquePointer<int> up7(ret_rvalue_unique_ptr(120));

}

}

