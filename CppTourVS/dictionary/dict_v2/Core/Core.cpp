#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Core.h"

 /*
 Holds all variables and configs for DctCore class
 */
 struct dct_core::MySFMLData
 {
  /*
  Pull event pointer variable
  */
  sf::Event* event;
  sf::Font BisternFont;
  sf::Font TrajanFont;
  sf::Font FuturaFont;
  sf::Font RoboSlab;
  sf::Text WelcomeText;
  std::wstring PlayerInput;
  sf::CircleShape SimpleCircle;
  std::vector<sf::Text> WordsToDraw;
  /*
  Push your object to this array to draw
  */
  std::vector<sf::Drawable*>* RegisteredOblectToDraw;

  MySFMLData() : RegisteredOblectToDraw(new std::vector<sf::Drawable*>()) {
   SetUpMainWindow();
   SetUpBisternFont();
   SetUpTrajanFont();
   SetUpFuturaFont();
   SetUpRobotoSlabFont();
   SetUpWelcomeText();
   SetUpSimpleCircle();
  }
  ~MySFMLData() {
   delete(event);
   event = nullptr;
  }
  /*
  Fill up RegisteredOblectToDraw variable
  than main class will handle  drawing of al objects in this variable
  */
  void RegistrateOblectToDraw(sf::Drawable& ObjectToRegistrate) {
   RegisteredOblectToDraw->push_back(&ObjectToRegistrate);
  }
  void UnregistrateOblectToDraw(sf::Drawable& ObjectToUnregistrate) {
   std::vector <sf::Drawable*>::iterator ToEraseIterator;
   ToEraseIterator = std::find(this->RegisteredOblectToDraw->begin(), this->RegisteredOblectToDraw->end(), &ObjectToUnregistrate);
   this->RegisteredOblectToDraw->erase(ToEraseIterator);
  }
 private:


  void SetUpBisternFont() {
   // load font
   if (!BisternFont.loadFromFile("dictionary/fonts/bistern/Bistern.otf"))
   {
    std::cout << "Main font wan't found !\n";
    return;
   }
  }
  void SetUpTrajanFont() {
    // load font
    if (!TrajanFont.loadFromFile("dictionary/dict_v2/fonts/Trajan/Trajan Pro.ttf")) {
      std::cout << "Main font wan't found !\n";
      return;
    }
  }
  void SetUpFuturaFont() {
    // load font
    if (!FuturaFont.loadFromFile(
            "dictionary/dict_v2/fonts/Futura/unicode.futurabb.ttf")) {
      std::cout << "Main font wan't found !\n";
      return;
    }
  }
  void SetUpRobotoSlabFont() {
    // load font
    if (!RoboSlab.loadFromFile(
            "dictionary/dict_v2/fonts/RobotoSlab/RobotoSlab-VariableFont_wght.ttf")) {
      std::cout << "Main font wan't found !\n";
      return;
    }
  }
  void SetUpWelcomeText() {
   // select the font
   WelcomeText.setFont(BisternFont); // font is a sf::Font
   // set the wstring to display
   WelcomeText.setString("");
   // set the character size
   WelcomeText.setCharacterSize(20); // in pixels, not points!
   // set the color
   WelcomeText.setFillColor(sf::Color::Green);
   // set the text style
   WelcomeText.setStyle(sf::Text::Bold);
   WelcomeText.setPosition(sf::Vector2f(0, 0));
   RegistrateOblectToDraw(WelcomeText);
  }
  void SetUpSimpleCircle() {
   SimpleCircle = sf::CircleShape(10.f, 10.f);
   SimpleCircle.setFillColor(sf::Color::Green);
   SimpleCircle.setPosition(sf::Vector2f(20.f, 20.f));
   this->RegistrateOblectToDraw(SimpleCircle);
  }
  void SetUpMainWindow() {
   // windows create and config
  
   event = new sf::Event;
  }

 }; // struct MySFMLData


dct_core::DctCore::DctCore()
     : MainWindow(new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!")),
           Data(new MySFMLData()) {
  
 }

dct_core::DctCore::~DctCore() {
 delete(Data);
}

void dct_core::DctCore::DrawAndDisplay() {
 for (sf::Drawable* dr : *Data->RegisteredOblectToDraw)
 {
  MainWindow->draw(*dr);
 }
 // Draw words added by dct_coreDctCore::AddWorldOnScreen function
 MainWindow->display();
 MainWindow->clear();
 //std::cout << "2\n";
 //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

// handler  for all events
void dct_core::DctCore::EventsHandler() {
 while (MainWindow->pollEvent(*Data->event))
 {
  switch (Data->event->type)
  {
   default:
   {} break;
   case sf::Event::Closed:
   {
    MainWindow->close();
   } break;
   // handle text input for player
   case sf::Event::TextEntered:
   {
    if (Data->event->text.unicode == '\b'&& Data->PlayerInput.size() > 0)
    {
     Data->PlayerInput.erase(Data->PlayerInput.size() - 1, 1);
    }
    else
    {
     Data->PlayerInput += Data->event->text.unicode;
    }
    Data->WelcomeText.setString(Data->PlayerInput);
   } break;
  } // switch (Data->event->type)
 } // while (Data->MainWindow->pollEvent(*Data->event))
}

// TODO: check if same word exist on screen
void dct_core::DctCore::AddWorldOnScreen(int xp, int yp, std::wstring Text) {
 int TextSize = 20;
 sf::Color TextColor = sf::Color::Green;
 this->AddWorldOnScreen(xp, yp, Text, TextSize, TextColor);
}

// TODO: check if same word exist on screen
void dct_core::DctCore::AddWorldOnScreen(int xp, int yp, std::wstring Text,
                                         int TextSize, sf::Color TextColor) {
 std::wstring str = Text;
 sf::Text txt;
 
 txt.setFont(this->Data->RoboSlab);
 std::wstring name = L"Ó ê ð";
 txt.setString(name);
 txt.setCharacterSize(TextSize);
 txt.setFillColor(TextColor);
 txt.setPosition(sf::Vector2f(xp, yp));
 MainWindow->draw(txt);
 this->Data->WordsToDraw.push_back(txt);
}

void dct_core::DctCore::RemoveWordByName(std::wstring WordToRemove) {
 std::vector <sf::Text>::iterator ToEraseIterator = Data->WordsToDraw.begin();
 for (int counter = 0; counter < Data->WordsToDraw.size(); counter++)
 {
  std::wstring str_to_compare = std::wstring(Data->WordsToDraw[counter].getString());
  if (!str_to_compare.compare(WordToRemove))
  {
   this->Data->WordsToDraw.erase(ToEraseIterator);
   return;
  }
  ToEraseIterator++;
 }
}

void dct_core::DctCore::CleanAllWords() {
 this->Data->WordsToDraw.clear();
}

sf::Event* dct_core::DctCore::GetEvent() {
 return Data->event;
}

sf::RenderWindow* dct_core::DctCore::GetWindow() {
 return MainWindow;
}

std::wstring dct_core::DctCore::GetString() {
 std::wstring reuslt_str;
 sf::Vector2f window_center = sf::Vector2f(400.f, 300.f);
 Data->WelcomeText.setPosition(window_center);
 while (true)
 {
  while (MainWindow->pollEvent(*Data->event))
  {
   MainWindow->clear();
   switch (Data->event->type)
   {
    default:
    {} break;
    case sf::Event::Closed:
    {
     MainWindow->close();
    } break;
    // handle input for user
    case sf::Event::TextEntered:
    {
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
     {
      return std::wstring(reuslt_str);
      break;
     }
     // Backspace button pressed
     if (Data->event->text.unicode == '\b' && reuslt_str.size() > 0)
     {
      reuslt_str.erase(reuslt_str.size() - 1, 1);
     }
     else
     {
     reuslt_str += Data->event->text.unicode;
     }
     // place text exactly on center of window
     Data->WelcomeText.setString(reuslt_str);  
     sf::Vector2f new_origin((Data->WelcomeText.getCharacterSize() * reuslt_str.size()/4), 0.f);
     Data->WelcomeText.setOrigin(new_origin);
    } break;
   } // switch (Data->event->type)
   DrawWords();
   MainWindow->draw(Data->WelcomeText);
   MainWindow->display();
  } // while (Data->MainWindow->pollEvent(*Data->event))
 }
 return std::wstring();
}

sf::Font* dct_core::DctCore::GetBisternFont() {
 return &Data->BisternFont;
}

void dct_core::DctCore::MainLoop() {
 // draw words before main loop starts
 AddWorldOnScreen(10, 10, L"Yahari", 16, sf::Color::Green);
 AddWorldOnScreen(10, 30,L"Nani", 16, sf::Color::Green);
 RemoveWordByName(L"No");
 std::wstring StringFromUser = GetString();
 AddWorldOnScreen(10, 50, StringFromUser, 16, sf::Color::Green);
 while (MainWindow->isOpen())
 {
  EventsHandler();
  DrawWords();
  DrawAndDisplay();
 }
}

void dct_core::DctCore::DrawWords() {
 for (sf::Text text : this->Data->WordsToDraw)
 {
  MainWindow->draw(text);
 }
}

