#include "../include/menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Menu::Menu() : selectedOption(0) {}
Menu::~Menu() {}

bool Menu::display(sf::RenderWindow& window, const std::string& imagePath) {
    sf::Texture menuTexture;
    if (!menuTexture.loadFromFile(imagePath)) {
        std::cerr << "Error: Failed to load image from path: " << imagePath << std::endl;
        return false;
    }

    sf::Sprite menuSprite;
    menuSprite.setTexture(menuTexture);
    menuSprite.setScale(
        window.getSize().x / menuSprite.getLocalBounds().width,
        window.getSize().y / menuSprite.getLocalBounds().height
    );
    
    window.draw(menuSprite);  // Just draw without calling window.display()
    return true; 
}

void Menu::displayAnimation(sf::RenderWindow& window) {
    sf::Sprite sprite;
    std::vector<sf::Texture> frames(18);
    for (int i = 1; i <= 18; ++i) {
        if (!frames[i-1].loadFromFile("../assets/frame" + std::to_string(i) + ".gif")) {
            std::cerr << "Error: Failed to load frame " << i << "!" << std::endl;
            return;
        }
    }

    sprite.setTexture(frames[0]);
    int currentFrame = 0;
    sf::Clock clock;  
    const float frameDuration = 0.1f;  
    sf::Clock totalTimeClock;  
    const float maxAnimationTime = 5.0f; 

    // Center the sprite
    sf::Vector2u windowSize = window.getSize();
    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);
    sf::FloatRect spriteBounds = sprite.getLocalBounds();
    float spriteWidth = spriteBounds.width;
    float spriteHeight = spriteBounds.height;
    sprite.setPosition((windowWidth - spriteWidth) / 2, (windowHeight - spriteHeight) / 2);

    // Load font for the text
    sf::Font font;
    if (!font.loadFromFile("../assets/inspiration.ttf")) { 
        std::cerr << "Error: Failed to load font!" << std::endl;
        return;
    }

    // Create text to display in the top-left corner
    sf::Text text;
    text.setFont(font);
    text.setString("Bella3b");
    text.setCharacterSize(80);
    text.setFillColor(sf::Color::Black);
    text.setPosition(40.f, 40.f); // Set position to top-left

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }

        if (totalTimeClock.getElapsedTime().asSeconds() >= maxAnimationTime) {
            break;
        }

        if (clock.getElapsedTime().asSeconds() >= frameDuration) {
            currentFrame = (currentFrame + 1) % 18; 
            sprite.setTexture(frames[currentFrame]);  
            clock.restart();
        }

        window.clear(sf::Color::White);  
        window.draw(sprite);
        window.draw(text);  // Draw the text on top-left
        window.display();
    }
}

