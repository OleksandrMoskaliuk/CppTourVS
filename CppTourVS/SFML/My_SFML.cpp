#include <SFML/Graphics.hpp>
#include <future>
#include <iostream>
#include <chrono>
#include <vector>

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
  sf::Font MainFont;
  sf::String PlayerInput;
  /* 
  Push your object to this array to draw 
  */
  std::vector<sf::Drawable*> *RegisteredOblectToDraw;

  MySFMLData() : RegisteredOblectToDraw(new std::vector<sf::Drawable*>()) {
   SetUpMainWindow();
   SetUpWelcomeText();
  }
 private:

  /*
  Fill up RegisteredOblectToDraw variable 
  than main class will handle  drawing of al objects in this variable
  */
  void SetUpRegisteredOblectToDraw(sf::Drawable& ObjectToRegistrate) {
   RegisteredOblectToDraw->push_back(&ObjectToRegistrate);
  }

  void SetUpWelcomeText() {
   // load font
   if (!MainFont.loadFromFile("dictionary/fonts/bistern/Bistern.otf"))
   {
    std::cout << "Main font wan't found !\n";
    return;
   }
   // select the font
   WelcomeText.setFont(MainFont); // font is a sf::Font
   // set the string to display
   WelcomeText.setString("");
   // set the character size
   WelcomeText.setCharacterSize(10); // in pixels, not points!
   // set the color
   WelcomeText.setFillColor(sf::Color::Green);
   // set the text style
   WelcomeText.setStyle(sf::Text::Bold);
   WelcomeText.setPosition(sf::Vector2f(0,0));
   SetUpRegisteredOblectToDraw(WelcomeText);
  }
  void SetUpMainWindow() {
   // windows create and config
   MainWindow = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
   event = new sf::Event;
  }
 
 }; // struct MySFMLData
}

my_sfml::MySFML::MySFML() : Data(new MySFMLData()) {
 //this->open_window();
 this->MainLoop();
}

void my_sfml::MySFML::open_window() {

 // make circle
 sf::CircleShape SimpleCircle(100.f);
 SimpleCircle.setFillColor(sf::Color::Green);


 std::future<void> future = std::async(std::launch::async, [&]() {
  while (true)
  {

  }
 });

 


}



void my_sfml::MySFML::DrawAndDisplay() {
 std::cout << "draw\n";
 Data->MainWindow->clear();
 for (sf::Drawable *dr : *Data->RegisteredOblectToDraw) 
 {
  Data->MainWindow->draw(*dr);
 }
 Data->MainWindow->display();
 //std::cout << "2\n";
 //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void my_sfml::MySFML::MainLoop() {

 while (Data->MainWindow->isOpen())
 {
  //handle events
  while (Data->MainWindow->pollEvent(*Data->event))
  {
   switch (Data->event->type)
   {
    default:
     break;
    case sf::Event::Closed:
    {
     Data->MainWindow->close();
    } break;
    case sf::Event::TextEntered:
    {
     Data->PlayerInput += Data->event->text.unicode;
     Data->WelcomeText.setString(Data->PlayerInput);
    } break;
   }
  
  }

  DrawAndDisplay();
 }
}
