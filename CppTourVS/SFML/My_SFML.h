#pragma once
#ifndef MY_SFML
#define MY_SFML

// forvard declaration, used to minimize includes, see:
// https://blog.knatten.org/2012/11/30/how-to-avoid-includes-in-headers/

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
 private:
  void open_window();
  void DrawAndDisplay();
  void EventsHandler();
  /* 
  main sfml loop
  */
  void MainLoop();
 };

}
#endif