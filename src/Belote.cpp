//#include "../include/Carte.h"
//#include <iostream>
//#include <SFML/Graphics.hpp>
//
//// Card constructor
//Card::Card(const std::string& suit, const std::string& rank, const sf::Texture& texture)
//    : suit(suit), rank(rank), sprite(texture) {}
//
//// Draw card at a specific position
//void Card::draw(sf::RenderWindow& window, float x, float y) {
//    sprite.setPosition(x, y);
//    window.draw(sprite);
//}
//
//// BeloteGame constructor
//BeloteGame::BeloteGame() 
//    : window(sf::VideoMode(800, 600), "Bella3b") {
//    if (!font.loadFromFile("path/to/font.ttf")) {
//        std::cerr << "Error loading font\n";
//    }
//
//    message.setFont(font);
//    message.setString("Welcome to Belote!");
//    message.setCharacterSize(24);
//    message.setFillColor(sf::Color::White);
//
//    initializeDeck();
//}
//
//// Initialize deck with card textures
//void BeloteGame::initializeDeck() {
//    sf::Texture texture;
//    texture.loadFromFile("path/to/card_image.png");  // Replace with actual texture path
//    deck.emplace_back("Hearts", "Ace", texture);
//    // Add more cards as needed
//}
//
//// Run the game loop
//void BeloteGame::run() {
//    while (window.isOpen()) {
//        processEvents();
//        update();
//        render();
//    }
//}
//
//void BeloteGame::processEvents() {
//    sf::Event event;
//    while (window.pollEvent(event)) {
//        if (event.type == sf::Event::Closed)
//            window.close();
//    }
//}
//
//void BeloteGame::update() {
//    // Update game logic here
//}
//
//void BeloteGame::render() {
//    window.clear();
//    for (size_t i = 0; i < deck.size(); ++i) {
//        deck[i].draw(window, 100.f + i * 30.f, 200.f);
//    }
//    window.draw(message);
//    window.display();
//}
//