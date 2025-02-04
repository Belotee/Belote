#include "include/Carte.h"
#include "include/menu.h"
#include "include/button.h"
#include "include/RectButton.h"
#include "include/EllipseButton.h"
#include "include/Functions.h"
#include "src/Belote.cpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>  
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Bella3b", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);  // Prevents screen tearing

    Menu menu;

    sf::Font buttonFont;
    if (!buttonFont.loadFromFile("../assets/ARIAL.TTF")) { 
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }

    bool showGameScreen = false;
    bool showSettingsScreen = false;
    bool showLanguageScreen = false;
    bool isMuted = false;
    bool hasDistributed = false;
    std::string languageScreenPath = "";  

    // Main Menu Buttons
    RectButton button1(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(85.f, 310.f));   
    button1.setButtonLabel(40.f, "Play");
    button1.setButtonColor(sf::Color(255, 255, 255, 0));

    RectButton button2(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(85.f, 435.f));
    button2.setButtonLabel(40.f, "Options");
    button2.setButtonColor(sf::Color(255, 255, 255, 0));

    RectButton button3(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(85.f, 550.f));
    button3.setButtonLabel(40.f, "Exit");
    button3.setButtonColor(sf::Color(255, 255, 255, 0));

    // Settings Buttons
    RectButton language(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 300.f));
    language.setButtonLabel(40.f, "Language");
    language.setButtonColor(sf::Color(255, 255, 255, 0));

    RectButton sound(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 400.f));
    sound.setButtonLabel(40.f, "Sound");
    sound.setButtonColor(sf::Color(255, 255, 255, 0));

    // Load Sound
    sf::SoundBuffer clickSoundBuffer;
    if (!clickSoundBuffer.loadFromFile("../assets/play.ogg")) {
        std::cerr << "Error loading sound!" << std::endl;
        return -1;
    } 

    sf::Sound clickSound;
    clickSound.setBuffer(clickSoundBuffer);

    Joueur player1("Player1", 1);
    Joueur player2("Player2", 2);
    Joueur player3("Player3", 3);
    Joueur player4("Player4", 4);

    vector<Joueur> Players_list = { player1, player2, player3, player4 };
    Equipe team1(player1, player3);
    Equipe team2(player2, player4);
    Table table(Players_list, team1, team2);

    menu.displayAnimation(window);  // Show startup animation

    // Enable smoothing for all loaded textures
    sf::Texture texture;
    if (!texture.loadFromFile("../assets/cards/BlueCardBack.png")) {
        std::cerr << "Error loading texture!" << std::endl;
        return -1;
    }
    texture.setSmooth(true);  // Enable anti-aliasing
    bool atout_set = false;
    int round = 0;
    int player_turn = 0;

    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0; 
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                if (!languageScreenPath.empty()) {
                    languageScreenPath = "";  
                } else if (showLanguageScreen) {
                    showLanguageScreen = false;
                } else if (showSettingsScreen) {
                    showSettingsScreen = false;  // Return to main menu
                } else if (showGameScreen) {
                    showGameScreen = false;
                    hasDistributed = false;  // Reset distribution when exiting game screen
                } else {
                    window.close(); // Close if on main menu
                }
            }

            // Main menu button handling
            if (!showSettingsScreen && !showGameScreen && !showLanguageScreen) {
                button1.getButtonStatus(window, event);
                button2.getButtonStatus(window, event);
                button3.getButtonStatus(window, event);

                if (button1.isPressed) {
                    std::cout << "Play button clicked! Switching to game screen..." << std::endl;
                    clickSound.play();
                    showGameScreen = true; 
                    hasDistributed = false; // Allow distribution again
                    button1.isPressed = false;
                    
                }
                if (button2.isPressed) { 
                    std::cout << "Options button clicked! Opening settings..." << std::endl;
                    clickSound.play();
                    showSettingsScreen = true;  
                    button2.isPressed = false;
                }
                if (button3.isPressed) { 
                    std::cout << "Exit button clicked! Closing game..." << std::endl;
                    clickSound.play();
                    window.close();
                    button3.isPressed = false;
                }
            }

            // Settings menu button handling
            if (showSettingsScreen && !showLanguageScreen) {
                language.getButtonStatus(window, event);
                sound.getButtonStatus(window, event);

                if (language.isPressed) {
                    std::cout << "Language button clicked! Opening language selection..." << std::endl;
                    showLanguageScreen = true;  // Activate the language screen
                    clickSound.play();
                    language.isPressed = false;
                }
                if (sound.isPressed) {
                    std::cout << "Sound button clicked!" << std::endl;
                    isMuted = !isMuted;
                    sound.isPressed = false;
                }
            }
        }

        // Clear the window before drawing new elements
        window.clear();

        if (!languageScreenPath.empty()) {
            menu.display(window, languageScreenPath);
        } else if (showLanguageScreen) {
            menu.display(window, "../assets/Group 4.png");  
        } else if (showSettingsScreen) {
            menu.display(window, "../assets/settings.png");
            sound.draw(window);
            language.draw(window);
        } else if (showGameScreen) {
            menu.display(window, "../assets/cards/Group 8.png"); 

            if (!hasDistributed) {
                table.melange(); 
                distribute(table, 8, 32);
                hasDistributed = true; // Prevent continuous distribution
            }

            vector<Carte>& cartes = table.setJoueurs()[0].set_player_paquet().getPaquet();


            for (int i = 0; i < 8; i++) {
                menu.displayCards(window, "../assets/cards/BlueCardBack.png", -350, i * 20);
                menu.displayCards(window, cartes[i].getAddress0(), i * 100 - 306, 360);
            }

            if (atout_set == false) {
                string atout;
                cin >> atout;
                for (size_t i = 0; i < 4; ++i) {
                    vector<Carte>& cartes = table.setJoueurs()[i].set_player_paquet().getPaquet();
                    for (int j = 0; j<8 ; j++){
                        if (cartes[j].getCouleur() == atout){
                            cartes[j].setAtout(1);
                            
                        }
                    }
                    
                }
                atout_set = true;
            }

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

