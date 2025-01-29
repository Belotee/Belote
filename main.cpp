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

    RectButton button(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 350.f));
    button.setButtonLabel(40.f, "Play");

    bool showGameScreen = false;  // Tracks if the game screen should be displayed

    menu.displayAnimation(window);  // Display animation at the beginning

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0; 
            }
            button.getButtonStatus(window, event);

            // Detect button click and switch to the game screen
            if (button.isPressed) {
                std::cout << "Button clicked! Switching screen..." << std::endl;
                showGameScreen = true; 
                button.isPressed = false;  // Reset button state to prevent continuous triggering
            }
        }

        // Clear window before drawing new elements
        window.clear();

        // Switch screens based on `showGameScreen`
        if (showGameScreen) {
            menu.display(window, "../assets/cards/tableBackground.png"); 
        } else {
            menu.display(window, "../assets/Group 2.png"); 
            button.draw(window);  // Only draw button on the menu screen
        }

        window.display();
    }

    return 0; 
}
