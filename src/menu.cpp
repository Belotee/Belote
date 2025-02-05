#include "../include/menu.h"
#include "../include/Table.h"
#include "../include/Equipe.h"
#include "../include/Joueur.h"
#include "../include/Carte.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

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

//displayCards function
void Menu::displayCards(sf::RenderWindow& window , string imagePath, int x, int y) {
    sf::Texture cardTexture;
    if (!cardTexture.loadFromFile(imagePath)) {
        std::cerr << "Error: Failed to load card image!" << std::endl;
        return;
    }

    sf::Sprite cardSprite;
    cardSprite.setTexture(cardTexture);
    cardSprite.setScale(0.5f, 0.5f);

    // Center the sprite
    sf::Vector2u windowSize = window.getSize();
    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);
    sf::FloatRect spriteBounds = cardSprite.getLocalBounds();
    float spriteWidth = spriteBounds.width;
    float spriteHeight = spriteBounds.height;
    cardSprite.setPosition((windowWidth - spriteWidth) / 2 + x, (windowHeight - spriteHeight) / 2 + y);

    window.draw(cardSprite);
}
<<<<<<< HEAD
string talba(Table &T, Equipe &team1, Equipe &team2) {
=======
string Menu :: talba(Table &T, Equipe &team1, Equipe &team2) {
>>>>>>> 032f64330f1d7692299340295fbb342991a4d2f8
    vector<Joueur> players = T.getJoueurs();
    int highest_bid = 90; // Starting bid
    vector<Joueur> winning_team;
    Carte atout_card; // To hold the atout card
    bool atout_card_set = false;

    // Loop for each player to select card type or pass
    for (size_t i = 0; i < players.size(); i++) {
        Joueur &player = players[i];
        string selected_color = player.selectCardOrPass(); // Get player's choice

        if (selected_color == "Passe") {
            continue; // Player chose to pass
        } else {
            // Find a card that matches the selected color in the player's hand
            vector<Carte> player_cards = player.get_player_paquet().getPaquet();
            for (const Carte &card : player_cards) {
                if (card.getCouleur() == selected_color) {
                    atout_card = card; // Set the atout card
                    atout_card.setAtout(1); // Mark this card as atout
                    atout_card_set = true;
                    break;
                }
            }

            // Player sets their bid
            int bid = player.setBid(); // Get the player's bid

            // Check if the bid is the highest
            if (bid > highest_bid) {
                highest_bid = bid;
                winning_team.clear(); // Clear previous winning team
                // Add players to the winning team based on their index
                if (i < 2) {
                    winning_team.push_back(players[0]);
                    winning_team.push_back(players[1]);
                } else {
                    winning_team.push_back(players[2]);
                    winning_team.push_back(players[3]);
                }
            }
        }
    }

    // Prepare the result string for the winning team
    string winning_team_names;
    for (const Joueur &player : winning_team) {
        winning_team_names += player.getNom() + " "; // Concatenate player names
    }

    // Update the scores of the winning team
    if (!winning_team.empty()) {
        if (winning_team[0].getNom() == players[0].getNom() || winning_team[0].getNom() == players[1].getNom()) {
            team1.setScore(team1.getScore() + 1); // Increment score for team 1
        } else {
            team2.setScore(team2.getScore() + 1); // Increment score for team 2
        }
    }

    // Return detailed results
    return "Atout Type: " + atout_card.getCouleur() + ", Highest Bid: " + to_string(highest_bid) +
           ", Winning Team: " + winning_team_names;
}
<<<<<<< HEAD
=======

>>>>>>> 032f64330f1d7692299340295fbb342991a4d2f8
