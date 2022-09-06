#include "window.h"
#include <SFML/Graphics.hpp>
#include <iostream>



void my_window::Window::Draw() {
}

void my_window::Window::Update() {
 sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
 window.setFramerateLimit(30);
 sf::CircleShape shape(100.f);
 shape.setFillColor(sf::Color::Green);
 sf::Clock Clock;

 while (window.isOpen())
 {
  sf::Event event;
  while (window.pollEvent(event))
  {
   if (event.type == sf::Event::Closed)
    window.close();
  }

  window.clear();
  window.draw(shape);
  float Framerate = 1.f / Clock.restart().asSeconds();

  std::cout << "\n" << Framerate;

  //display only when draw ready
  window.display();
  system("CLS");

 }

}


void my_window::enter_point()
{
 Window df;
 df.Update();
}