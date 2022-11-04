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
  void CleanAllWords();
  std::string GetString();
  /* run main loop */
  virtual void RunLoop();
 private:
  void DrawAndDisplay();
  void EventsHandler();
  /* draw all words from Data->WordsToDraw buffer */
  void DrawWords();
  /* 
  main sfml loop
  */
  void MainLoop();
 };

}
#endif