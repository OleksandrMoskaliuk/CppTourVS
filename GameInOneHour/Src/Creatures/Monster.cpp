#include <SFML/Graphics.hpp>
#include <chrono>

class Monster {
 public:
  Monster(sf::Vector2f pos) {
    // Create the monster sprite
    m_pos = pos;
    m_body.setSize(sf::Vector2f(40, 90));  // create a rectangular body
    m_body.setPosition(m_pos);
    m_body.setFillColor(sf::Color(128, 0, 128));  // set the body color

    m_left_eye.setRadius(5);  // create the left eye
    m_left_eye.setFillColor(sf::Color::Green);
    m_left_eye.setPosition(
        m_pos + sf::Vector2f(20, 25));  // set the position of the left eye

    m_right_eye.setRadius(5);  // create the right eye
    m_right_eye.setFillColor(sf::Color::Green);
    m_right_eye.setPosition(
        m_pos + sf::Vector2f(30, 25));  // set the position of the right eye

    m_mouth.setSize(sf::Vector2f(20, 15));  // create the mouth
    m_mouth.setPosition(m_pos +
                        sf::Vector2f(15, 65));  // set the position of the mouth
    m_mouth.setFillColor(sf::Color::Red);       // set the mouth color

    m_horns.setPointCount(3);  // create the horns
    m_horns.setPoint(0, sf::Vector2f(5, 10));
    m_horns.setPoint(1, sf::Vector2f(10, 0));
    m_horns.setPoint(2, sf::Vector2f(30, 10));
    m_horns.setPosition(m_pos);
    m_horns.setFillColor(sf::Color(128, 128, 128));  // set the horns color

    // Define the movement speed of the monster
    m_movement_speed = 10.0f;
  }

  void handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
      switch (event.key.code) {
        case sf::Keyboard::Up:
          m_moving_up = true;
          break;
        case sf::Keyboard::Down:
          m_moving_down = true;
          break;
        case sf::Keyboard::Left:
          m_moving_left = true;
          break;
        case sf::Keyboard::Right:
          m_moving_right = true;
          break;
      }
    } else if (event.type == sf::Event::KeyReleased) {
      switch (event.key.code) {
        case sf::Keyboard::Up:
          m_moving_up = false;
          break;
        case sf::Keyboard::Down:
          m_moving_down = false;
          break;
        case sf::Keyboard::Left:
          m_moving_left = false;
          break;
        case sf::Keyboard::Right:
          m_moving_right = false;
          break;
      }
    }
  }

  void update() {
    auto current_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> delta_time = current_time - m_last_update_time;
    m_last_update_time = current_time;
    float elapsed_seconds = delta_time.count();

    sf::Vector2f movement(0.0f, 0.0f);
    if (m_moving_up) {
      movement += sf::Vector2f(0.0f, -1.0f);
    }
    if (m_moving_down) {
      movement += sf::
    }
  }