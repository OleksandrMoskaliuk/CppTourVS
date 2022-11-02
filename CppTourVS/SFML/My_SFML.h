#pragma once
#ifndef MY_SFML
#define MY_SFML

// forvard declaration, used to minimize includes, see:
// https://blog.knatten.org/2012/11/30/how-to-avoid-includes-in-headers/
namespace sf 
{
 class Color;
}

namespace my_sfml
{
 struct MySFMLData;

 class MySFML
 {
 private:
  MySFMLData *Data;
 public:
  MySFML();
  ~MySFML();
  void AddWorldOnScreen(int xp, int yp, std::string Text);
  void AddWorldOnScreen(int xp, int yp, std::string Text, int TextSize, sf::Color TextColor);
  void RemoveWordByName(std::string WordToRemove);
 private:
  void open_window();
  void DrawAndDisplay();
  void EventsHandler();
  void DrawWords();
  /* 
  main sfml loop
  */
  void MainLoop();
 };

}
#endif