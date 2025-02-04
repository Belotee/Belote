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
    std::string languageScreenPath = "";  // Stores the current language image

    // Declare buttons for main menu
    RectButton button1(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(85.f, 310.f));   
    button1.setButtonLabel(40.f, "Play");
    button1.setButtonColor(sf::Color(255, 255, 255, 0));

    RectButton button2(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(85.f, 435.f));
    button2.setButtonLabel(40.f, "Options");
    button2.setButtonColor(sf::Color(255, 255, 255, 0));

    RectButton button3(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(85.f, 550.f));
    button3.setButtonLabel(40.f, "Exit");
    button3.setButtonColor(sf::Color(255, 255, 255, 0));

    // Declare buttons for settings menu
    RectButton language(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 300.f));
    language.setButtonLabel(40.f, "Language");
    language.setButtonColor(sf::Color(255, 255, 255, 0));

    RectButton sound(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(100.f, 400.f));
    sound.setButtonLabel(40.f, "Sound");
    sound.setButtonColor(sf::Color(255, 255, 255, 0));

    // Load sound for button clicks
    sf::SoundBuffer clickSoundBuffer;
    if (!clickSoundBuffer.loadFromFile("../assets/play.ogg")) {
        std::cerr << "Error loading sound!" << std::endl;
        return -1;
    }


    Joueur player1("Player1", 1);

    Joueur player2("Player2", 2);
    Joueur player3("Player3", 3);
    Joueur player4("Player4", 4);
      
    vector<Joueur> Players_list = { player1,  player2,  player3 ,  player4};
    Equipe team1(player1, player3);
    Equipe team2(player2, player4);
    Table table( Players_list, team1, team2);
    string atout ;
    table.melange(); 
    distribute(table, 8, 32);


    sf::Sound clickSound;
    clickSound.setBuffer(clickSoundBuffer);

    // Load      music
    //sf::Music backgroundMusic;
    //if (!backgroundMusic.openFromFile("../assets/sound.ogg")) {
    //    std::cerr << "Error loading background music!" << std::endl;
    //    return -1;
    //}
    //backgroundMusic.setLoop(true);
    //backgroundMusic.play();

    menu.displayAnimation(window);  // Show startup animation

    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);  // Update mouse position

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0; 
            }

            // Escape key to go back
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                if (!languageScreenPath.empty()) {
                    languageScreenPath = "";  // Close selected language screen
                } else if (showLanguageScreen) {
                    showLanguageScreen = false;
                } else if (showSettingsScreen) {
                    showSettingsScreen = false;  // Return to main menu
                } else if (showGameScreen) {
                    showGameScreen = false;
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
                    //backgroundMusic.setVolume(isMuted ? 0 : 100);
                    sound.isPressed = false;
                }
            }

            // Handle language selection
            if (showLanguageScreen && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                std::cout << "Mouse Click at: " << mousePos.x << ", " << mousePos.y << std::endl;
                
                if (mousePos.x >= 630 && mousePos.x <= 871 &&
                    mousePos.y >= 123 && mousePos.y <= 202) {
                    std::cout << "Tunisian selected!" << std::endl;
                    languageScreenPath = "../assets/Group 7.png";
                }
                if (mousePos.x >= 630 && mousePos.x <= 871 &&
                    mousePos.y >= 238 && mousePos.y <= 317) {
                    std::cout << "French selected!" << std::endl;
                    languageScreenPath = "../assets/Group 8.png";
                }
                if (mousePos.x >= 630 && mousePos.x <= 871 &&
                    mousePos.y >= 353 && mousePos.y <= 432) {
                    std::cout << "English selected!" << std::endl;
                    languageScreenPath = "../assets/Group 9.png";
                }
            }
        }

        // Clear the window before drawing new elements
        window.clear();

        // Display based on active screen
        if (!languageScreenPath.empty()) {
            menu.display(window, languageScreenPath);  // Show selected language image
        } else if (showLanguageScreen) {
            menu.display(window, "../assets/Group 4.png");  
        } else if (showSettingsScreen) {
            menu.display(window, "../assets/settings.png");
            sound.draw(window);
            language.draw(window);
        } else if (showGameScreen) {
            menu.display(window, "../assets/cards/tableBackground.png"); 
            
          
            bool ala = false;
            table.melange(); 
            distribute(table, 8, 32);
            
            vector<Carte>& cartes = table.setJoueurs()[0].set_player_paquet().getPaquet();
            vector<Carte> copy = cartes;
            
            bool displayed = false;
            while (ala == false){
                
      
                
                

                if (displayed == false ){    
                    for (int j=0;j<8;j++){
                        std::cout<<cartes[j].toString()<<'\n';
                        std::cout << cartes[j].getAddress0()<<'\n';

                    }
                    displayed = true;
                }
                for (int i =0; i<8;i++){
                    std::cout << cartes[i].getAddress0()<<'\n';

                    menu.displayCards(window,cartes[i].getAddress0(), i*100-200, 320);
                }
                ala = true;
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
