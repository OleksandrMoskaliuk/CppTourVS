/* USER GUI*/
#include <SFML/Graphics.hpp>
#include "dictionary2.h"
#include <thread>
#include <chrono>


DictionaryV2::DictionaryV2() : CursorPosition(new sf::Vector2f(0.f, 0.f)) {
 //setup simple circle , for menu cursor
 CursorCircle = new sf::CircleShape(10.f, 10.f); // size of circle
 CursorCircle->setFillColor(sf::Color::Green);
 CursorCircle->setPosition(sf::Vector2f(0.f, 0.f));
}

DictionaryV2::~DictionaryV2() {
 delete(CursorPosition);
}

void DictionaryV2::MainLoop() {
 std::vector<std::string> menu_info;
 // to add new case just push back it to menu_info vector;
 menu_info.push_back("_SHOW_DICTIONARY");  // case 0
 menu_info.push_back("_ADD_WORD");         // case 1
 menu_info.push_back("_REMOVE_WORD");      // case 2
 menu_info.push_back("_EDIT_WORD");        // case 3
 menu_info.push_back("_TEST_YOURSELF");    // case 4
 menu_info.push_back("_SAVE");             // case 5
 menu_info.push_back("_SAVE_AND_EXIT");    // case 6
 menu_info.push_back("_EXIT");             // case 7
 CurrentList = &menu_info;
 
 std::thread th([&]() {
  std::this_thread::sleep_for(std::chrono::seconds(10));
  RemoveWordByName("Text");
 });
 th.detach();

 while (GetWindow()->isOpen())
 {
  HandleEvents();
  MakeList(*CurrentList);
  // Will write word into draw buffer
  DrawWords();
  GetWindow()->display();
  GetWindow()->clear();
 }
}

void const DictionaryV2::MakeList(std::vector<std::string> const& Text) {
 this->CleanAllWords();
 CursorPosition->y = 0;
 CursorPosition->x = 30;
 for (std::string wrd : Text)
 {
  AddWorldOnScreen(CursorPosition->x, CursorPosition->y, wrd, 18, sf::Color::Green);
  CursorPosition->y += 22;
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
   case sf::Event::KeyPressed:
   {
    // Move cursor down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
     this->MenuCounter++;
     AdjustCursorCirclebyMenuCounter();
    }
    //Move cursor up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
     this->MenuCounter--;
     AdjustCursorCirclebyMenuCounter();
    }
   }
  } // switch (Data->event->type)
 } // while (Data->MainWindow->pollEvent(*Data->event))
}

void DictionaryV2::DrawWords() {
 if (CurrentList && CurrentList->size() > 0)
 {
 /* if (((*CurrentList)[MenuCounter].compare(std::string(std::string("->>") + (*CurrentList)[MenuCounter])))) 
  {
    (*CurrentList)[MenuCounter] = std::string("->> ") + (*CurrentList)[MenuCounter];
  }
  */
  //std::cout << (int)MenuCounter << "\n";



  
 }
 GetWindow()->draw(*this->CursorCircle);
 my_sfml::MySFML::DrawWords();
}

void DictionaryV2::AdjustCursorCirclebyMenuCounter() {
 if (MenuCounter > (int16_t)CurrentList->size() - 1)
 {
  MenuCounter = 0;
 }
 if (MenuCounter < 0)
 {
  MenuCounter = CurrentList->size() - 1;
 }
 CursorCircle->setPosition(0, MenuCounter * 22);
}

