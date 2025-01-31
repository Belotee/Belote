#ifndef FUNCTION_H
#define FUNCTION_H

#include "Table.h"
#include <vector>  // Make sure vector is included for vector<Carte>

void distribute(Table&, int, int, int, int); // Function to distribute cards

int retour_indice(Table&); // Function to return the index of the player who picks the card on the table

void display_cards(std::vector<Carte>); // Function to display the cards
void affectation_atout_joueur(Table& T); // Function to assign the atout to each player's hand
void affectation_Atout(Table& T, std::vector<Carte>& V); // Function to assign the atout to a vector of cards

#endif // FUNCTION_H
