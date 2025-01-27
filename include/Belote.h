#ifndef BELOTE_H
#define BELOTE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Card {
public:
    Card(const std::string& suit, const std::string& rank, const sf::Texture& texture);
    void draw(sf::RenderWindow& window, float x, float y);

private:
    std::string suit;  // Card suit (e.g., Hearts, Spades)
    std::string rank;  // Card rank (e.g., Ace, King)
    sf::Sprite sprite; // Card sprite for rendering
};

class BeloteGame {
public:
    BeloteGame();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    std::vector<Card> deck;
    sf::Font font;
    sf::Text message;

    void initializeDeck();
};

#endif  // BELOTE_H
