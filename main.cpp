#include "include/Carte.h"
#include "include/menu.h"
#include "include/button.h"
#include "include/RectButton.h"
#include "include/EllipseButton.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>  
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Bella3b", sf::Style::Titlebar | sf::Style::Close);

    Menu menu;

    sf::Font buttonFont;
    if (!buttonFont.loadFromFile("../assets/ARIAL.TTF")) { 
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }

    // Declare buttons for main menu
    RectButton button1(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(85.f, 310.f));   
    button1.setButtonLabel(40.f, "Play");
    button1.setButtonColor(sf::Color(255, 255, 255, 0));  // Transparent background

    RectButton button2(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(85.f, 435.f));
    button2.setButtonLabel(40.f, "Options");
    button2.setButtonColor(sf::Color(255, 255, 255, 0));  // Transparent background

    RectButton button3(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(85.f, 550.f));
    button3.setButtonLabel(40.f, "Exit");
    button3.setButtonColor(sf::Color(255, 255, 255, 0));  // Transparent background

    // Declare buttons for settings menu
    RectButton language(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 300.f));
    language.setButtonLabel(40.f, "Language");
    language.setButtonColor(sf::Color(255, 255, 255, 0));  // Transparent background

    RectButton sound(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 400.f));
    sound.setButtonLabel(40.f, "Sound");
    sound.setButtonColor(sf::Color(255, 255, 255, 0));  // Transparent background

    // Load sound for button clicks
    sf::SoundBuffer clickSoundBuffer;
    if (!clickSoundBuffer.loadFromFile("../assets/play.ogg")) {
        std::cerr << "Error loading sound!" << std::endl;
        return -1;
    }

    sf::Sound clickSound;
    clickSound.setBuffer(clickSoundBuffer);

    // Load continuous background music
    sf::Music backgroundMusic;
    if (!backgroundMusic.openFromFile("../assets/sound.ogg")) {
        std::cerr << "Error loading background music!" << std::endl;
        return -1;
    }
    backgroundMusic.setLoop(true); // Set the music to loop continuously
    backgroundMusic.play();  // Start playing the music

    bool showGameScreen = false;    // Tracks if the game screen should be displayed
    bool showSettingsScreen = false; // Tracks if the settings screen should be displayed
    bool isMuted = false; // Tracks if the background music is muted

    menu.displayAnimation(window);  // Display animation at the beginning

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0; 
            }

            // Detect escape key press to go back to the previous screen
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                if (showSettingsScreen) {
                    showSettingsScreen = false; // Go back to main menu
                } else if (showGameScreen) {
                    showGameScreen = false; // Go back to main menu
                } else {
                    window.close(); // Close the window if on main menu
                }
            }

            // Handle button states for the main menu
            if (!showSettingsScreen && !showGameScreen) {
                button1.getButtonStatus(window, event);
                button2.getButtonStatus(window, event);
                button3.getButtonStatus(window, event);

                if (button1.isPressed) {
                    std::cout << "Play button clicked! Switching to game screen..." << std::endl;
                    clickSound.play();  // Play the click sound
                    showGameScreen = true; 
                    button1.isPressed = false;  // Reset button state
                }
                if (button2.isPressed) { 
                    std::cout << "Options button clicked! Opening settings..." << std::endl;
                    clickSound.play();  // Play the click sound
                    showSettingsScreen = true;  
                    button2.isPressed = false;  // Reset button state
                }
                if (button3.isPressed) { 
                    std::cout << "Exit button clicked! Closing game..." << std::endl;
                    clickSound.play();  // Play the click sound
                    window.close();
                    button3.isPressed = false;  // Reset button state
                }
            }
            if (showSettingsScreen) {
                language.getButtonStatus(window, event);
                sound.getButtonStatus(window, event);

                if (language.isPressed) {
                    std::cout << "Language button clicked!" << std::endl;
                    language.isPressed = false;  
                    clickSound.play(); 
                }
                if (sound.isPressed) {
                    std::cout << "Sound button clicked!" << std::endl;
                    isMuted = !isMuted;
                    if (isMuted) {
                        backgroundMusic.setVolume(0); // Mute the background music
                    } else {
                        backgroundMusic.setVolume(100); // Restore full volume
                    }
                    sound.isPressed = false;  // Reset the button after click
                }
            }
        }

        // Clear the window before drawing new elements
        window.clear();

        // Display the appropriate screen
        if (showSettingsScreen) {
            menu.display(window, "../assets/settings.png");
            sound.draw(window);
            language.draw(window);
        } else if (showGameScreen) {
            menu.display(window, "../assets/cards/tableBackground.png"); 
        } else {
            menu.display(window, "../assets/Group 2.png");
            button1.draw(window);
            button2.draw(window);
            button3.draw(window);
        }
        window.display();
    }

    return 0; 
}
