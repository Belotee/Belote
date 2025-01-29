
#include "../include/menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Menu::Menu() : selectedOption(0) {}
Menu::~Menu() {
 
}


bool Menu::display(sf::RenderWindow& window, const std::string& imagePath) {
    // Load the texture from the provided image path
    sf::Texture menuTexture;
    if (!menuTexture.loadFromFile(imagePath)) {
        std::cerr << "Error: Failed to load image from path: " << imagePath << std::endl;
        return false;
    }

    // Create a sprite for the image
    sf::Sprite menuSprite;
    menuSprite.setTexture(menuTexture);

    // Scale the image to fit the window
    menuSprite.setScale(
        window.getSize().x / menuSprite.getLocalBounds().width,
        window.getSize().y / menuSprite.getLocalBounds().height
    );

    // Draw the menu content (image)
    window.clear();
    window.draw(menuSprite);
    window.display();

    return true; 
}
