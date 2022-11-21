#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include "Messenger.h"

using namespace std;
using namespace sf;

int messenger() {
  using namespace std;
  using namespace sf;
  RenderWindow window(VideoMode(1000, 1000), "chat");
  setlocale(LC_ALL, "Russian");
  int x, y;

  bool text;
  text = 0;
  RectangleShape inputField;
  inputField.setPosition(Vector2f(100, 100));
  inputField.setSize(Vector2f(300, 850));
  inputField.setFillColor(Color(245, 245, 220));
  inputField.setOutlineColor(Color(100, 245, 220));

  RectangleShape line;
  line.setPosition(100, 125);
  line.setSize(Vector2f(300, 5));
  line.setFillColor(Color(128, 128, 128));

  wstring message = L"”Ù≥‡‚≥Ô¯≥Ú‚";

  sf::Font font;
  if (!font.loadFromFile("RobotoSlab-VariableFont_wght.ttf")) {
    return EXIT_FAILURE;
  }
  Text txt;
  txt.setPosition(100, 100);
  txt.setFont(font);
  txt.setString(message);
  txt.setFillColor(Color(128, 128, 128));
  txt.setCharacterSize(20);
  vector<Text> arr;
  while (window.isOpen()) {
    if (arr.size() != 0) {
      if (arr[arr.size() - 1].getPosition().y > 900) {
        arr.resize(0);
      }
    }
    x = Mouse::getPosition().x - window.getPosition().x - 5;
    y = Mouse::getPosition().y - window.getPosition().y - 30;
    window.clear(Color::Green - Color(100, 100, 100));
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) window.close();
      // Select input field before typing will be allowed
      if (event.type == event.MouseButtonReleased &&
          event.mouseButton.button == Mouse::Left) {
        if (x >= inputField.getPosition().x &&
            x <= inputField.getPosition().x + inputField.getSize().x &&
            y >= inputField.getPosition().y &&
            y <= inputField.getPosition().y + inputField.getSize().y) {
          text = true;
          inputField.setFillColor(Color(245, 245, 220));
        } else {
          text = false;
          inputField.setFillColor(Color(0, 245, 220));
        }
      }
      if (event.type == sf::Event::TextEntered) {
        if (text) {
          // Remove symbol if Backspace typed;
          if (event.text.unicode == 8 && message.size() != 0) {
            message.resize(message.size() - 1);
          } else {
            // message += static_cast<char>(event.text.unicode);
            message += (event.text.unicode);
            wcout << message << " " << message.size() << endl;
            std::cout << "event.text.unicode != 8\n";
          }
        }  //  if (text)
      }
    }
    txt.setString(message);
    window.draw(inputField);
    window.draw(txt);
    for (int i = 0; i < arr.size(); ++i) {
      window.draw(arr[i]);
    }
    window.draw(line);
    window.display();
  }
}

bool is_UTF8(sf::Event &event) {
  if (event.text.unicode < 128) {
    // auto a = event.text.unicode;
    //  ASCI English symbol typed;
    // std::cout << "ASCII character typed: "
    //           << static_cast<char>(event.text.unicode) << std::endl;
    return false;
  } else {
    // Unicode format;
    // std::cout << "UTF8 character typed: " << (event.text.unicode) <<
    // std::endl;
    return true;
  }
}