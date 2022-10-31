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
  sf::Text WelcomeText;
  sf::Font BisternFont;
  sf::String PlayerInput;
  sf::CircleShape SimpleCircle;
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
 private:

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

void my_sfml::MySFML::MainLoop() {
 while (Data->MainWindow->isOpen())
 {
  EventsHandler();
  DrawAndDisplay();
 }
}
