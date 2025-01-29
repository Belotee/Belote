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

    bool displayNewWindow = false; 

    menu.displayAnimation(window); 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0; 
            }
            button.getButtonStatus(window, event);

            if (button.isPressed) {
                std::cout << "Button clicked!" << std::endl;
                displayNewWindow = true; 
            }
        }

        window.clear();
        
        if (displayNewWindow) {
            menu.display(window, "../assets/cards/tableBackground.png"); 
        } else {
            menu.display(window, "../assets/Group 2.png"); 
        }
        button.draw(window);
        window.display();
    }

    return 0; 
}