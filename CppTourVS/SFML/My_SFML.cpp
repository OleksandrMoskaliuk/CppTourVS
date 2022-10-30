#include <SFML/Graphics.hpp>
#include <future>
#include <iostream>
#include <chrono>

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
  MySFMLData() {
   SetUpMainWindow();
   SetUpWelcomeText();
  }
 private:
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
  }
  void SetUpMainWindow() {
   // windows create and config
   MainWindow = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
   event = new sf::Event;
  }
 }; // struct MySFMLData
}

my_sfml::MySFML::MySFML() {
 this->Data =  new MySFMLData();
 this->open_window();
}

void my_sfml::MySFML::open_window() {

 // make circle
 sf::CircleShape shape(100.f);
 shape.setFillColor(sf::Color::Green);


 std::future<void> future = std::async(std::launch::async, [&]() {
  while (true)
  {

  }
 });

 this->MainLoop();







}

void my_sfml::MySFML::draw() {

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

  Data->MainWindow->clear();
  //MainWindow->draw(shape);
  Data->MainWindow->draw(Data->WelcomeText);
  Data->MainWindow->display();


 }

}
