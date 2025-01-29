#include "include/Carte.h"
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

    // Declare multiple buttons with unique names
    RectButton button1(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 300.f));
    button1.setButtonLabel(40.f, "Play");

    RectButton button2(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 400.f));
    button2.setButtonLabel(40.f, "Options");

    RectButton button3(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 500.f));
    button3.setButtonLabel(40.f, "Exit");

    bool showGameScreen = false;  // Tracks if the game screen should be displayed

    menu.displayAnimation(window);  // Display animation at the beginning

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0; 
            }

            // Check button states
            button1.getButtonStatus(window, event);
            button2.getButtonStatus(window, event);
            button3.getButtonStatus(window, event);

            // Detect button clicks
            if (button1.isPressed) {
                std::cout << "Play button clicked! Switching screen..." << std::endl;
                showGameScreen = true; 
                button1.isPressed = false;  // Reset button state
            }
            if (button3.isPressed) { 
                std::cout << "Exit button clicked! Closing game..." << std::endl;
                window.close();
            }
        }

        // Clear window before drawing new elements
        window.clear();

        // Switch screens based on `showGameScreen`
        if (showGameScreen) {
            menu.display(window, "../assets/cards/tableBackground.png"); 
        } else {
            menu.display(window, "../assets/Group 2.png"); 

            // Draw buttons
            button1.draw(window);
            button2.draw(window);
            button3.draw(window);
        }

        window.display();
    }

    return 0; 
}
