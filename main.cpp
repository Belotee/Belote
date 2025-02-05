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

    // Initialize players and teams
    Joueur player1("Player1", 1);
    Joueur player2("Player2", 2);
    Joueur player3("Player3", 3);
    Joueur player4("Player4", 4);
    
    std::vector<Joueur> Players_list = { player1, player2, player3, player4 };
    Equipe team1(player1, player3);
    Equipe team2(player2, player4);
    Table table(Players_list, team1, team2);

    std::cout << "Initial Team 1 Score: " << team1.getScore() << std::endl;
    std::cout << "Initial Team 2 Score: " << team2.getScore() << std::endl;

    menu.displayAnimation(window);  // Show startup animation

    // Load and enable texture smoothing
    sf::Texture texture;
    if (!texture.loadFromFile("../assets/cards/BlueCardBack.png")) {
        std::cerr << "Error loading texture!" << std::endl;
        return -1;
    }
    texture.setSmooth(true);

    bool atout_set = false;
    bool talbaCompleted = false;  // Track if `talba` has been called
    int round = 0;
    std::string atout = "Coeur";
    int player_turn = 0;
    std::vector<Carte>& CardsOnTable = table.setCardsOnTable();

    bool showGameScreen = false;
    bool showSettingsScreen = false;
    bool showLanguageScreen = false;
    bool isMuted = false;
    bool hasDistributed = false;

    // Buttons
    RectButton button1(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(85.f, 310.f));   
    button1.setButtonLabel(40.f, "Play");
    button1.setButtonColor(sf::Color(255, 255, 255, 0));

    RectButton button2(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(85.f, 435.f));
    button2.setButtonLabel(40.f, "Options");
    button2.setButtonColor(sf::Color(255, 255, 255, 0));

    RectButton button3(buttonFont, sf::Vector2f(250.f, 70.f), sf::Vector2f(85.f, 550.f));
    button3.setButtonLabel(40.f, "Exit");
    button3.setButtonColor(sf::Color(255, 255, 255, 0));

    // Load Sound
    sf::SoundBuffer clickSoundBuffer;
    if (!clickSoundBuffer.loadFromFile("../assets/play.ogg")) {
        std::cerr << "Error loading sound!" << std::endl;
        return -1;
    } 

    sf::Sound clickSound;
    clickSound.setBuffer(clickSoundBuffer);

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0; 
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                if (showGameScreen) {
                    showGameScreen = false;
                    hasDistributed = false;
                    talbaCompleted = false;
                } else {
                    window.close();
                }
            }

            // Handle menu buttons
            if (!showSettingsScreen && !showGameScreen && !showLanguageScreen) {
                button1.getButtonStatus(window, event);
                button2.getButtonStatus(window, event);
                button3.getButtonStatus(window, event);

                if (button1.isPressed) {
                    std::cout << "Play button clicked!" << std::endl;
                    clickSound.play();
                    showGameScreen = true; 
                    hasDistributed = false;
                    talbaCompleted = false;
                    button1.isPressed = false;
                }
                if (button2.isPressed) { 
                    std::cout << "Options button clicked!" << std::endl;
                    clickSound.play();
                    showSettingsScreen = true;  
                    button2.isPressed = false;
                }
                if (button3.isPressed) { 
                    std::cout << "Exit button clicked!" << std::endl;
                    clickSound.play();
                    window.close();
                    button3.isPressed = false;
                }
            }
        }

        window.clear();

        if (showGameScreen) {
            menu.display(window, "../assets/cards/Group 8.png"); 

            if (!hasDistributed) {
                table.melange();
                distribute(table, 8, 32);
                hasDistributed = true;
            }

            // **Ensure `talba` only runs once**
            if (!talbaCompleted) {
                std::string result = menu.talba(table, team1, team2);
                std::cout << "Result from talba: " << result << std::endl;
                talbaCompleted = true;  // Prevent it from running multiple times
            }
            for (int i =0; i<4;i++){
                vector<Carte> kaf = table.setJoueurs()[i].set_player_paquet().getPaquet();
                std::cout << "--------------------"<<"PLAYER " << i+1<<"----------------------------------------";
                for (int j = 0; j<kaf.size();j++){
                    std::cout << kaf[j].toString()<<'\n';
                }
            }
            std::vector<Carte>& cartes = table.setJoueurs()[player_turn].set_player_paquet().getPaquet();
            player_turn = play(table, player_turn, event, atout);
            
            for (int i = 0; i < cartes.size(); i++) {
                menu.displayCards(window, cartes[i].getAddress0(), i * 100 - 306, 360);
            }

            // Display cards on table
            for (size_t i = 0; i < CardsOnTable.size(); i++) {
                menu.displayCards(window, CardsOnTable[i].getAddress0(), 50 + (i * 40), 180 - (i * 50));
            }

            
        } else if (showSettingsScreen) {
            menu.display(window, "../assets/settings.png");
        } else {
            menu.display(window, "../assets/Group 2.png");
            button1.draw(window);
            button2.draw(window);
            button3.draw(window);
        }

        window.display();
        if (CardsOnTable.size()==4){
            
            player_turn = table.joueur_gagnant(atout,( player_turn%3));
            table.Score(atout,player_turn);
            sf::sleep(sf::milliseconds(2000));
            CardsOnTable.clear();
        }
    }
    return 0; 
}
