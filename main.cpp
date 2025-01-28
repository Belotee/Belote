#include "include/Belote.h"
#include "include/menu.h"
#include "include/button.h"
#include "include/RectButton.h"
#include "include/EllipseButton.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Bella3b");
    Menu menu;

    // Load the font
    sf::Font buttonFont;
    if (!buttonFont.loadFromFile("../assets/ARIAL.TTF")) { // Adjust the path accordingly
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }

    // Create the button
    RectButton button(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 350.f));
    button.setButtonLabel(40.f, "Play");

    bool displayNewWindow = false; 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0; 
            }

            // Update button status based on events
            button.getButtonStatus(window, event);

            // Check if the button was pressed
            if (button.isPressed) {
                std::cout << "Button clicked!" << std::endl;
                displayNewWindow = true; // Change state to display the new window
            }
        }

        window.clear();
        
        // Display the appropriate content based on the state
        if (displayNewWindow) {
            menu.display(window, "../assets/ala.jpg"); 
        } else {
            menu.display(window, "../assets/Group 2.png"); 
        }

        // Draw the button
        button.draw(window);
        
        window.display();
    }

    return 0; 
}