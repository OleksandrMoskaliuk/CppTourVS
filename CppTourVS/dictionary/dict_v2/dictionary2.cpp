/* USER GUI*/
#include <SFML/Graphics.hpp>
#include "dictionary2.h"

DictionaryV2::DictionaryV2() {
}

DictionaryV2::~DictionaryV2() {
}

void DictionaryV2::MainLoop() {
 AddWorldOnScreen(10, 10, "Text");
 while (GetWindow()->isOpen()) 
 {
  HandleEvents();
  DrawWords();
  GetWindow()->display();
  GetWindow()->clear();
 }
}

void DictionaryV2::HandleEvents() {
 sf::String str = "dsagsdg";
 sf::Text dummy_text;
 dummy_text.setFont(*GetBisternFont());
 dummy_text.setPosition(50.f, 50.f);
 dummy_text.setString(str);
 dummy_text.setFillColor(sf::Color::Green);
 while (GetWindow()->pollEvent(*GetEvent()))
 {
  switch (GetEvent()->type)
  {
   default:
   {} break;
   case sf::Event::Closed:
   {
    GetWindow()->close();
   } break;
   // handle text input for player
   case sf::Event::TextEntered:
   {
    if (GetEvent()->text.unicode == '\b' && str.getSize() > 0)
    {
     str.erase(str.getSize() - 1, 1);
    }
    else
    {
     str += GetEvent()->text.unicode;
    }
    dummy_text.setString(str);
    GetWindow()->draw(dummy_text);
   } break;
  } // switch (Data->event->type)
 } // while (Data->MainWindow->pollEvent(*Data->event))
}

