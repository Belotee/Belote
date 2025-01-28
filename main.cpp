#include "include/Belote.h"
#include "include/menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Bella3b");
    Menu menu;

    // Define the target area where the click will trigger the new window
    float targetX = 308.0f;
    float targetY = 286.0f;
    float targetWidth = 405.92f;
    float targetHeight = 143.f;

    bool displayNewWindow = false; // State variable to track which window to display

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0; // Close the window
            }

            // Mouse click detection and target area checking
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Get the mouse position

                // Debugging: Print mouse position in window coordinates
                std::cout << "Mouse position: (" << mousePos.x << ", " << mousePos.y << ")" << std::endl;

                // Check if the mouse is inside the target area
                if (mousePos.x >= targetX && mousePos.x <= targetX + targetWidth &&
                    mousePos.y >= targetY && mousePos.y <= targetY + targetHeight) {
                    std::cout << "Mouse clicked inside target area!" << std::endl; // Debugging line
                    displayNewWindow = true; // Change state to display the new window
                } else {
                    std::cout << "Mouse click outside target area!" << std::endl; // Debugging line
                }
            }
        }

        // Clear the window
        window.clear();

        // Display the appropriate content based on the state
        if (displayNewWindow) {
            menu.display(window, "../assets/ala.jpg"); // Display the new window content
        } else {
            menu.display(window, "../assets/Group 2.png"); // Display the main menu image
        }

        // Display the window contents
        window.display();
    }

    return 0; 
}