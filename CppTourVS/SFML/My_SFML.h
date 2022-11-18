#pragma once
#ifndef MY_SFML
#define MY_SFML

// forvard declaration, used to minimize includes, see:
// https://blog.knatten.org/2012/11/30/how-to-avoid-includes-in-headers/
namespace sf 
{
 class Color;
 class Event;
 class RenderWindow;
 class Font;
}

namespace my_sfml
{
 struct MySFMLData;
 class MySFML
 {
 public:
  MySFML();
  ~MySFML();
  void AddWorldOnScreen(int xp, int yp, std::string Text);
  void AddWorldOnScreen(int xp, int yp, std::string Text, int TextSize, sf::Color TextColor);
  /* draw all words from Data->WordsToDraw buffer */
  virtual void DrawWords();
  void RemoveWordByName(std::string WordToRemove);
  void CleanAllWords();
  /* Get event poiner */
  sf::Event* GetEvent();
  /* Get window pointer */
  sf::RenderWindow* GetWindow();
  std::string GetString();
  sf::Font* GetBisternFont();
  /* Main loop should be overriden in children class */
  virtual void MainLoop();
 private:
  /* Holds all data in cpp struct */
  MySFMLData* Data;
  /* Draw object from inner data struct */
  void DrawAndDisplay();
  /* Handle all events */
  void EventsHandler();
 };
}
#endif