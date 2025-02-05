#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp> // Include SFML graphics header
#include "../include/Carte.h"
#include "../include/Table.h"
#include <iostream>
#include <vector>
#include <string>
#include "../include/Joueur.h"
class Menu {
private:
    std::vector<std::string> options; // List of menu options
    int selectedOption;                // Index of the currently selected option

public:
    Menu();                            // Constructor
    ~Menu();                           // Destructor

    // Main function to display the menu and handle user input
bool display(sf::RenderWindow& window, const std::string& imagePath);
    void addOption(const std::string& option); // Add an option to the menu
    void navigateMenu();                       // Handle navigation through the menu options
    int getSelectedOption() const;            // Get the currently selected option index
    void displayAnimation(sf::RenderWindow& window) ;
    void displayCards(sf::RenderWindow& window,string imagePath , int x, int y);
    string talba(Table &T );
};


#endif // MENU_H