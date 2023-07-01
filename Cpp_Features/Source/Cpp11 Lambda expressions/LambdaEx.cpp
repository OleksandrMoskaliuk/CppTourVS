#include "LambdaEx.h"
#include <vector>
#include <iostream>
#include <functional>


namespace lambdas 
{
 

 void find_if()
 {

 };

 void lambdas() 
 {
   // get all var inside this scope by ref
   auto lambda_by_ref = [&]() {};

   // get all var  inside this scope as copy
   auto lambda_by_val = [=]() {};

   // get only test_val and test_val1 inside this scope as ref
   int test_val = 0;
   int test_val1 = 1;
   auto spec_lambda_by_val = [&test_val, &test_val1]() {};

   // lambda usage
   std::vector<int> lemon = {10, 15, 20, 45};
   std::function<bool(int)> lambda_condition = [&](int value) {
     return value > 20 && value <= 45;
   };
   auto finded = std::find_if(lemon.begin(), lemon.end(), lambda_condition);
   std::cout << *finded;
   

  return;
 }
}