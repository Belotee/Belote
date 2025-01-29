#include "include/Belote.h"
#include "include/menu.h"
#include "include/button.h"
#include "include/RectButton.h"
#include "include/EllipseButton.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Bella3b");
    Menu menu;

    sf::Font buttonFont;
    if (!buttonFont.loadFromFile("../assets/ARIAL.TTF")) { 
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }

    RectButton button(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(50.f, 250.f));
    button.setButtonLabel(40.f, "Play");

    bool isMenuActive = true;  // Track if we are on the main menu

    menu.displayAnimation(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0;
            }

            button.getButtonStatus(window, event);

            // Switch to another "page" when the button is clicked
            if (button.isPressed) {
                isMenuActive = false;  // Move to the next page
            }
        }

        window.clear();

        if (isMenuActive) {
            menu.display(window, "../assets/Group 2.png");
            button.draw(window);
        } else {
            menu.display(window, "../assets/ala.jpg");  // Display new "page"
        }

        window.display();
    }

    return 0;
}
