#include "../include/menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Menu::Menu() : selectedOption(0) {}
Menu::~Menu() {
 
}

void Menu::displayMenu() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bella3b");

    // Load the menu image
    sf::Texture menuTexture;
    if (!menuTexture.loadFromFile("../assets/Group 2.png")) { // Adjust path if needed
        std::cerr << "Error: Failed to load menu image!" << std::endl;
        return; // Just exit the function, not return -1
    }

    // Create a sprite for the menu
    sf::Sprite menuSprite;
    menuSprite.setTexture(menuTexture);

    // Scale the image to fit the window
    menuSprite.setScale(
        window.getSize().x / menuSprite.getLocalBounds().width,
        window.getSize().y / menuSprite.getLocalBounds().height
    );

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear and draw the menu
        window.clear();
        window.draw(menuSprite);
        window.display();
    }
}
