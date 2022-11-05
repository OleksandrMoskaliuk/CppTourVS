#pragma once
#ifndef DICTIONARY2
#define DICTIONARY2

#include "../dict_v1/dictionary.h"
#include "../../SFML/My_SFML.h"

class DictionaryV2 : public my_dictionary::MyDictionary, public my_sfml::MySFML
{
public:
 DictionaryV2();
 ~DictionaryV2();
 void MainLoop() override;
private:
 void HandleEvents();
};


#endif // !DICTIONARY2
