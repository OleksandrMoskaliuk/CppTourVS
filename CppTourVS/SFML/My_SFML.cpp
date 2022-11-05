#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "My_SFML.h"

 /*
 Holds all variables and configs for MySFML class
 */
 struct my_sfml::MySFMLData
 {
  /*
  Main window class
  */
  sf::RenderWindow* MainWindow;
  /*
  Pull event pointer variable
  */
  sf::Event* event;
  sf::Font BisternFont;
  sf::Text WelcomeText;
  sf::String PlayerInput;
  sf::CircleShape SimpleCircle;
  std::vector<sf::Text> WordsToDraw;
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
   event = nullptr;
  }
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
 private:


  void SetUpBisternFont() {
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


my_sfml::MySFML::MySFML() : Data(new MySFMLData()) {
}

my_sfml::MySFML::~MySFML() {
 delete(Data);
}

void my_sfml::MySFML::DrawAndDisplay() {
 for (sf::Drawable* dr : *Data->RegisteredOblectToDraw)
 {
  Data->MainWindow->draw(*dr);
 }
 // Draw words added by my_sfml::MySFML::AddWorldOnScreen function
 Data->MainWindow->display();
 Data->MainWindow->clear();
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
    if (Data->event->text.unicode == '\b'&& Data->PlayerInput.getSize() > 0)
    {
     Data->PlayerInput.erase(Data->PlayerInput.getSize() - 1, 1);
    }
    else
    {
     Data->PlayerInput += Data->event->text.unicode;
    }
    Data->WelcomeText.setString(Data->PlayerInput);
   } break;
  } // switch (Data->event->type)
 } // while (Data->MainWindow->pollEvent(*Data->event))
}

// TODO: check if same word exist on screen
void my_sfml::MySFML::AddWorldOnScreen(int xp, int yp, std::string Text) {
 int TextSize = 20;
 sf::Color TextColor = sf::Color::Green;
 this->AddWorldOnScreen(xp, yp, Text, TextSize, TextColor);
}

// TODO: check if same word exist on screen
void my_sfml::MySFML::AddWorldOnScreen(int xp, int yp, std::string Text, int TextSize, sf::Color TextColor) {
 sf::String str = Text;
 sf::Text txt;
 txt.setFont(this->Data->BisternFont);
 txt.setString(str);
 txt.setCharacterSize(TextSize);
 txt.setFillColor(TextColor);
 txt.setPosition(sf::Vector2f(xp, yp));
 Data->MainWindow->draw(txt);
 this->Data->WordsToDraw.push_back(txt);
}

void my_sfml::MySFML::RemoveWordByName(std::string WordToRemove) {
 std::vector <sf::Text>::iterator ToEraseIterator = Data->WordsToDraw.begin();
 for (int counter = 0; counter < Data->WordsToDraw.size(); counter++)
 {
  std::string str_to_compare = std::string(Data->WordsToDraw[counter].getString());
  if (!str_to_compare.compare(WordToRemove))
  {
   this->Data->WordsToDraw.erase(ToEraseIterator);
   return;
  }
  ToEraseIterator++;
 }
}

void my_sfml::MySFML::CleanAllWords() {
 this->Data->WordsToDraw.clear();
}

sf::Event* my_sfml::MySFML::GetEvent() 
{
 return Data->event;
}

sf::RenderWindow* my_sfml::MySFML::GetWindow() 
{
 return Data->MainWindow;
}

std::string my_sfml::MySFML::GetString() {
 sf::String reuslt_str;
 sf::Vector2f window_center = sf::Vector2f(400.f, 300.f);
 Data->WelcomeText.setPosition(window_center);
 while (true)
 {
  while (Data->MainWindow->pollEvent(*Data->event))
  {
   Data->MainWindow->clear();
   switch (Data->event->type)
   {
    default:
    {} break;
    case sf::Event::Closed:
    {
     Data->MainWindow->close();
    } break;
    // handle input for user
    case sf::Event::TextEntered:
    {
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
     {
      return std::string(reuslt_str);
      break;
     }
     // Backspace button pressed
     if (Data->event->text.unicode == '\b' && reuslt_str.getSize() > 0)
     {
      reuslt_str.erase(reuslt_str.getSize() - 1, 1);
     }
     else
     {
     reuslt_str += Data->event->text.unicode;
     }
     // place text exactly on center of window
     Data->WelcomeText.setString(reuslt_str);  
     sf::Vector2f new_origin((Data->WelcomeText.getCharacterSize() * reuslt_str.getSize()/4), 0.f);
     Data->WelcomeText.setOrigin(new_origin);
    } break;
   } // switch (Data->event->type)
   DrawWords();
   Data->MainWindow->draw(Data->WelcomeText);
   Data->MainWindow->display();
  } // while (Data->MainWindow->pollEvent(*Data->event))
 }
 return std::string();
}

sf::Font* my_sfml::MySFML::GetBisternFont() 
{
 return &Data->BisternFont;
}

void my_sfml::MySFML::MainLoop() {
 // draw words before main loop starts
 AddWorldOnScreen(10, 10, "Yahari", 16, sf::Color::Green);
 AddWorldOnScreen(10, 30, "Nani", 16, sf::Color::Green);
 RemoveWordByName("No");
 std::string StringFromUser = GetString();
 AddWorldOnScreen(10, 50, StringFromUser, 16, sf::Color::Green);
 while (Data->MainWindow->isOpen())
 {
  EventsHandler();
  DrawWords();
  DrawAndDisplay();
 }
}

void my_sfml::MySFML::DrawWords() {
 for (sf::Text text : this->Data->WordsToDraw)
 {
  Data->MainWindow->draw(text);
 }
}

