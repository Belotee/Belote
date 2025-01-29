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

    // Declare multiple buttons
    RectButton language(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 300.f));
    language.setButtonLabel(40.f, "Language");

    RectButton sound(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 400.f));
    sound.setButtonLabel(40.f, "Sound");

    RectButton button1(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 300.f));
    button1.setButtonLabel(40.f, "Play");

    RectButton button2(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 400.f));
    button2.setButtonLabel(40.f, "Options");

    RectButton button3(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 500.f));
    button3.setButtonLabel(40.f, "Exit");

    bool showGameScreen = false;    // Tracks if the game screen should be displayed
    bool showSettingsScreen = false; // Tracks if the settings screen should be displayed

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
                showSettingsScreen = false; // Ensure settings screen is closed when game starts
                button1.isPressed = false;  // Reset button state
            }
            if (button3.isPressed) { 
                std::cout << "Exit button clicked! Closing game..." << std::endl;
                window.close();
                button3.isPressed = false;  // Reset button state
            }
            if (button2.isPressed) { 
                std::cout << "Options button clicked! Opening settings..." << std::endl;
                showSettingsScreen = true;  
                showGameScreen = false; // Ensure game screen is not active
                button2.isPressed = false;  // Reset button state
            }

            // Check the language and sound buttons only if the settings screen is shown
            if (showSettingsScreen) {
                language.getButtonStatus(window, event);
                sound.getButtonStatus(window, event);

                if (language.isPressed) {
                    std::cout << "Language button clicked!" << std::endl;
                    language.isPressed = false;  // Reset the button after click
                }
                if (sound.isPressed) {
                    std::cout << "Sound button clicked!" << std::endl;
                    sound.isPressed = false;  // Reset the button after click
                }
            }
        }

        // Clear window before drawing new elements
        window.clear();

        // Display the appropriate screen
        if (showSettingsScreen) {
            menu.display(window, "../assets/settings.png"); 

            // Draw the language and sound buttons
            language.draw(window);
            sound.draw(window);
        } else if (showGameScreen) {
            menu.display(window, "../assets/cards/tableBackground.png"); 
        } else {
            menu.display(window, "../assets/Group 2.png"); 

            // Draw buttons only when in main menu
            button1.draw(window);
            button2.draw(window);
            button3.draw(window);
        }

        window.display();
    }

    return 0; 
}
