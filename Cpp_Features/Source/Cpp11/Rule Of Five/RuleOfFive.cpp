namespace rule_of_five 
{
/*
If a class requires a user-defined destructor, a user-defined copy constructor,
or a user-defined copy assignment operator, it almost certainly requires all
three.


Because the presence of a user-defined (or = default or = delete declared)
destructor, copy-constructor, or copy-assignment operator prevents implicit
definition of the move constructor and the move assignment operator, any class
for which move semantics are desirable, has to declare all five special member functions.

*/



}