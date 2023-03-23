#include <SFML/Graphics.hpp>

int main() {
  // Create a window
  sf::RenderWindow window(sf::VideoMode(400, 400), "Monster Sprite");

  // Create the monster sprite
  sf::Vector2f monster_pos(150, 150);  // starting position of the monster
  sf::RectangleShape monster_body(
      sf::Vector2f(40, 90));  // create a rectangular body
  monster_body.setPosition(monster_pos);
  monster_body.setFillColor(sf::Color(128, 0, 128));  // set the body color

  sf::CircleShape left_eye(5);  // create the left eye
  left_eye.setFillColor(sf::Color::Green);
  left_eye.setPosition(
      monster_pos + sf::Vector2f(20, 25));  // set the position of the left eye

  sf::CircleShape right_eye(5);  // create the right eye
  right_eye.setFillColor(sf::Color::Green);
  right_eye.setPosition(
      monster_pos + sf::Vector2f(30, 25));  // set the position of the right eye

  sf::RectangleShape mouth(sf::Vector2f(20, 15));  // create the mouth
  mouth.setPosition(monster_pos +
                    sf::Vector2f(15, 65));  // set the position of the mouth
  mouth.setFillColor(sf::Color::Red);       // set the mouth color

  sf::ConvexShape horns(3);  // create the horns
  horns.setPoint(0, sf::Vector2f(5, 10));
  horns.setPoint(1, sf::Vector2f(10, 0));
  horns.setPoint(2, sf::Vector2f(30, 10));
  horns.setPosition(monster_pos);
  horns.setFillColor(sf::Color(128, 128, 128));  // set the horns color

  // Define the movement speed of the monster
  const float movement_speed = 5.0f;

  // Game loop
  while (window.isOpen()) {
    // Handle events
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // Handle keyboard input to move the monster sprite
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      monster_pos.y -= movement_speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      monster_pos.y += movement_speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      monster_pos.x -= movement_speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      monster_pos.x += movement_speed;
    }

    // Update the position of the monster sprite
    monster_body.setPosition(monster_pos);
    left_eye.setPosition(monster_pos + sf::Vector2f(20, 25));
    right_eye.setPosition(monster_pos + sf::Vector2f(30, 25));
    mouth.setPosition(monster_pos + sf::Vector2f(15, 65));
    horns.setPosition(monster_pos);

    // Clear the window
    window.clear(sf::Color::Black);

    // Draw the monster sprite
    window.draw(monster_body);
    window.draw(left_eye);
    window.draw(right_eye);
    window.draw(mouth);
    window.draw(horns);

    // Update the display
    window.display();
  }
}