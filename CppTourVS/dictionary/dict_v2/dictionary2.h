#pragma once
#ifndef DICTIONARY2
#define DICTIONARY2

#include "../dict_v1/dictionary.h"
#include "../../SFML/My_SFML.h"
#include "SFML/System/Vector2.hpp"

class Vector2;
namespace sf 
{
 class CircleShape;
}

class DictionaryV2 : public my_dictionary::MyDictionary, public my_sfml::MySFML
{
public:
 DictionaryV2();
 ~DictionaryV2();
 void MainLoop() override;
private:
 class sf::CircleShape* CursorCircle;
 int8_t MenuCounter = 0;
 // Current list pointer to display
 std::vector<std::string> *CurrentList;
 struct Vector2f {};
 struct Word {
  std::string word;
  std::string translation;
  std::string category;
  std::string example;
 };
 my_list::List<Word> Data;
 sf::Vector2f* CursorPosition;
 void const MakeList(std::vector<std::string> const &Text);
 void HandleEvents();
 void DrawWords() override;
 void AdjustCursorCirclebyMenuCounter();
};


#endif // !DICTIONARY2
