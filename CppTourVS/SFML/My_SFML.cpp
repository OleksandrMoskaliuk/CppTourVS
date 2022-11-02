#include <SFML/Graphics.hpp>
#include <future>
#include <iostream>
#include <chrono>
#include <vector>
#include <memory>

#include "My_SFML.h"

namespace my_sfml {
 /*
 Holds all variables and configs for MySFML class
 */
 struct MySFMLData
 {
  /*
  Main window class
  */
  sf::RenderWindow* MainWindow;
  /*
  Pull event pointer variable
  */
  sf::Event* event;
  sf::Font BisternFont;
  sf::Text WelcomeText;
  sf::String PlayerInput;
  sf::CircleShape SimpleCircle;
  std::vector<sf::Text> WordsToDraw;
  /*
  Push your object to this array to draw
  */
  std::vector<sf::Drawable*>* RegisteredOblectToDraw;

  MySFMLData() : RegisteredOblectToDraw(new std::vector<sf::Drawable*>()) {
   SetUpMainWindow();
   SetUpBisternFont();
   SetUpWelcomeText();
   SetUpSimpleCircle();
  }
  ~MySFMLData() {
   delete(MainWindow);
   delete(event);
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

  
  void SetUpBisternFont() 
  {
   // load font
   if (!BisternFont.loadFromFile("dictionary/fonts/bistern/Bistern.otf"))
   {
    std::cout << "Main font wan't found !\n";
    return;
   }
  }
  void SetUpWelcomeText() {
   // select the font
   WelcomeText.setFont(BisternFont); // font is a sf::Font
   // set the string to display
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
   MainWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");
   event = new sf::Event;
  }

 }; // struct MySFMLData
}

my_sfml::MySFML::MySFML() : Data(new MySFMLData()) {
 // draw words before main loop starts
 AddWorldOnScreen(10, 10, "Yahari",16, sf::Color::Green);
 AddWorldOnScreen(10, 30, "Nani", 16, sf::Color::Green);
 AddWorldOnScreen(10, 50, "Monanto");
 RemoveWordByName("Nani");
 //AddWorldOnScreen(10, 40, "Nani");
 //AddWorldOnScreen(10, 70, "Monanto");
 this->Data->UnregistrateOblectToDraw(this->Data->SimpleCircle);
 // start point
 this->MainLoop();
}

my_sfml::MySFML::~MySFML()  {
 delete(Data);
}

void my_sfml::MySFML::open_window() {

 /*std::future<void> future = std::async(std::launch::async, [&]() {
  while (true)
  {

  }
 });*/



}

void my_sfml::MySFML::DrawAndDisplay() {
 Data->MainWindow->clear();
 for (sf::Drawable* dr : *Data->RegisteredOblectToDraw)
 {
  Data->MainWindow->draw(*dr);
 }
 // Draw words added by my_sfml::MySFML::AddWorldOnScreen function
 DrawWords();
 Data->MainWindow->display();
 //std::cout << "2\n";
 //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

// handler  for all events
void my_sfml::MySFML::EventsHandler() {

 while (Data->MainWindow->pollEvent(*Data->event))
 {
  switch (Data->event->type)
  {
   default:
   {} break;
   case sf::Event::Closed:
   {
    Data->MainWindow->close();
   } break;
   // handle text input for player
   case sf::Event::TextEntered:
   {
    if (Data->event->text.unicode == '\b')
    {
     Data->PlayerInput.erase(Data->PlayerInput.getSize() - 1, 1);
    } else {
    Data->PlayerInput += Data->event->text.unicode;
    }
    Data->WelcomeText.setString(Data->PlayerInput);
   } break;
  } // switch (Data->event->type)
 } // while (Data->MainWindow->pollEvent(*Data->event))
}

void my_sfml::MySFML::RemoveWordByName(std::string WordToRemove) {
 std::vector <sf::Text>::iterator ToEraseIterator = Data->WordsToDraw.begin();
 for (int counter = 0 ; counter < Data->WordsToDraw.size(); counter++)
 {
  std::string str_to_compare = std::string(Data->WordsToDraw[counter].getString());
  if (!str_to_compare.compare(WordToRemove)) 
  {
   this->Data->WordsToDraw.erase(ToEraseIterator);
   return;
  }
  ToEraseIterator++;
 }
}

void my_sfml::MySFML::AddWorldOnScreen(int xp, int yp, std::string Text) {
 int TextSize = 20; 
 sf::Color TextColor = sf::Color::Green;
 this->AddWorldOnScreen(xp, yp, Text, TextSize, TextColor);
}

void my_sfml::MySFML::AddWorldOnScreen(int xp, int yp, std::string Text, int TextSize, sf::Color TextColor) {
 sf::String str = Text;
 sf::Text txt;
 txt.setFont(this->Data->BisternFont);
 txt.setString(str);
 txt.setCharacterSize(TextSize);
 txt.setFillColor(TextColor);
 txt.setPosition(sf::Vector2f(xp, yp));
 this->Data->WordsToDraw.push_back(txt);
}

//void my_sfml::MySFML::AddWorldOnScreen(int xp, int yp, std::string word, int FontSize, sf::Color color)  {
// sf::String str = word;
// sf::Text txt;
// txt.setFont(this->Data->BisternFont);
// txt.setCharacterSize(FontSize)
// txt.setString(word);
// txt.setFillColor(sf::Color::Green);
// txt.setPosition(sf::Vector2f(xp, yp));
// this->Data->WordsToDraw.push_back(txt);
//}

void my_sfml::MySFML::DrawWords() {
 for (sf::Text text : this->Data->WordsToDraw) 
 {
  Data->MainWindow->draw(text);
 }
}

void my_sfml::MySFML::MainLoop() {
 while (Data->MainWindow->isOpen())
 {
  EventsHandler();
  DrawAndDisplay();
 }
}
