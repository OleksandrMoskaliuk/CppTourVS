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

namespace dct_core
{
 struct MySFMLData;
 class DctCore
 {
 public:
  DctCore();
  ~DctCore();
  void AddWorldOnScreen(int xp, int yp, std::wstring Text);
  void AddWorldOnScreen(int xp, int yp, std::wstring Text, int TextSize, sf::Color TextColor);
  /* draw all words from Data->WordsToDraw buffer */
  virtual void DrawWords();
  void RemoveWordByName(std::wstring WordToRemove);
  void CleanAllWords();
  /* Get event poiner */
  sf::Event* GetEvent();
  /* Get window pointer */
  sf::RenderWindow* GetWindow();
  std::wstring GetString();
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