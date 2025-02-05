#ifndef FUNCTION_H
#define FUNCTION_H

#include "Table.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

void distribute(Table& T);
int retour_indice(Table&);
void display_cards(std::vector<Carte>);
void affectation_atout_joueur(Table& T);
void affectation_Atout(Table& T, std::vector<Carte>& V);
int play(Table& T, int b,sf::Event event, string atout);

#endif