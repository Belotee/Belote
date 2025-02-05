#ifndef JOUEUR_H_
#define JOUEUR_H_

#include "Paquet_cartes.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Joueur {
private:
    int Rang;                   // Player's rank
    string Nom;                // Player's name
    Paquet_cartes Paquet;      // Player's deck of cards

public:
    Joueur(); 
    Joueur(string name, int rank); 
    Joueur(const Joueur& other); // Copy constructor

    int getRang() const;                 
    void setRang(int& rank);
    string getNom() const;                  
    Paquet_cartes get_player_paquet() const; // Get player's deck
    Paquet_cartes& set_player_paquet(); // Set player's deck
    
    void operator=(Joueur other); // Assignment operator

    vector<Carte> cartes_possible(vector<Carte> all_cards, string color); // Get playable cards
    int choisir_carte(vector<Carte>& available_cards, vector<Carte> played_cards); // Choose a card
    void sortir_carte(vector<Carte>& played_cards, Carte card); // Play a card

    // Method for selecting a card or passing
    string selectCardOrPass(); // New method for player interaction

    // Method to set the bid (if needed)
    int setBid(); // Method to set the player's bid
};

#endif // JOUEUR_H_