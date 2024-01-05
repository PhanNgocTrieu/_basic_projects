#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <unistd.h>

enum status_move {
    FORWARD,
    REVERSE
};

struct circle_properties {
    float circle_x = 0.0;
    float circle_y = 0.0;
    status_move circle_x_move {status_move::FORWARD};
    status_move circle_y_move {status_move::FORWARD};
};

void update_circle_state(circle_properties& m_circle) {
    std::cout << "Update circle state" << std::endl;
    // Update Position of X
    if (m_circle.circle_x_move == status_move::FORWARD) {
        if (m_circle.circle_x + 50 >= 800) {
            m_circle.circle_x_move = status_move::REVERSE;
        }
        else {
            m_circle.circle_x++;
        }
    } else {
        if (m_circle.circle_x - 50 < 0) {
            m_circle.circle_x_move = status_move::FORWARD;
        }
        else {
            m_circle.circle_x--;
        }
    }
    
    // Update Position of Y
    if (m_circle.circle_y_move == status_move::FORWARD) {
        if (m_circle.circle_y + 50 >= 460) {
            m_circle.circle_y_move = status_move::REVERSE;
        }
        else {
            m_circle.circle_y++;
        }
    } else {
        if (m_circle.circle_y - 50 < 0) {
            m_circle.circle_y_move = status_move::FORWARD;
        }
        else {
            m_circle.circle_y--;
        }
    }
}

int main(void) {
    sf::RenderWindow window(sf::VideoMode(800, 460), "Screen");
    sf::RenderWindow window_2(sf::VideoMode(200,200), "Popup");
    // Limit the framerate to 60 frames per second (this step is optional)
    // window.setFramerateLimit(60);

    // Load to display
    // sf::Texture texture; 
    // if (!texture.loadFromFile("src/background.jpeg")) {
    //     std::cerr << "Couldn't load background" << std::endl;
    //     return EXIT_FAILURE;
    // }

    sf::CircleShape circle;
    circle_properties m_circle;
    circle.setScale(1.0, 1.0);
    circle.setFillColor(sf::Color::Blue);
    circle.setRadius(50);
    circle.setOutlineColor(sf::Color::Red);
    circle.setPosition(10, 20);

    // sf::Sprite sprite(texture);
    // sprite.scale(sf::Vector2f{
    //     2.5f, 2.5f
    // });

    // sf::Font font;
    // if (!font.loadFromFile("fonts/Arial.ttf")) {
    //     return EXIT_FAILURE;
    // }

    // sf::Text text("Hello World!", font, 50);
    // text.setString(sf::String("Hello SFML"));
    // text.setColor(sf::Color::White);
    
    while (window.isOpen()) {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                std::cout << "Close Window" << std::endl;
                window.close();
            }
        }
        update_circle_state(m_circle);
        circle.setPosition(m_circle.circle_x, m_circle.circle_y);
        // Active the window for OpenGL rendering
        window.setActive();

        // OpenGL drawing commands go here
        // window.draw(sprite);
        // window.draw(text);
        window.draw(circle);

        // End the current frame and display its contents on scren
        window.display();
        usleep(1000);
    }
    return 0;
}