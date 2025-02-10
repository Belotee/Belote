#include <string>
#include <cstdio>
#include "../include/Functions.h"
#include "../include/menu.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;

    
void distribute(Table& T) {
    std::vector<Joueur>& joueurs = T.setJoueurs();
    const size_t cardsPerPlayer = 8; // Number of cards per player

    std::vector<Carte> allCards = T.getAllCards();

    // Distribute unique cards to each player
    for (size_t i = 0; i < joueurs.size(); i++) {
        Paquet_cartes& carta = joueurs[i].set_player_paquet();
        std::vector<Carte> packetTemp;

        for (size_t j = 0; j < cardsPerPlayer; j++) {
            packetTemp.push_back(allCards[i * cardsPerPlayer + j]);
        }

        // Sort the player's cards by custom logic
        std::stable_sort(packetTemp.begin(), packetTemp.end(), [](const Carte& a, const Carte& b) {
            // Define color priorities
            if ((a.getCouleur() == "Coeur" || a.getCouleur() == "Carreau") &&
                (b.getCouleur() == "Pique" || b.getCouleur() == "Trèfle")) {
                return true;  // Red comes before Black
            }
            if ((a.getCouleur() == "Pique" || a.getCouleur() == "Trèfle") &&
                (b.getCouleur() == "Coeur" || b.getCouleur() == "Carreau")) {
                return false; // Black comes after Red
            }
            return a.getCouleur() < b.getCouleur(); // Default sorting by color
        });

        // Further rearrangement to avoid adjacent black colors
        std::vector<Carte> rearranged;
        std::vector<Carte> reds, blacks;

        // Separate red and black cards
        for (const auto& card : packetTemp) {
            if (card.getCouleur() == "Coeur" || card.getCouleur() == "Pique") {
                reds.push_back(card);
            } else {
                blacks.push_back(card);
            }
        }

        // Merge red and black cards with the red cards first
        rearranged.insert(rearranged.end(), reds.begin(), reds.end());
        rearranged.insert(rearranged.end(), blacks.begin(), blacks.end());

        // Add sorted cards back to the player's packet
        carta.setPaquet(rearranged);
    }

    std::cout << "Cards distributed successfully.\n";
}



void affectation_Atout(Table& T, vector<Carte>& V) {		
    // Changer la valeur d'atout de chaque Carte dans V à 1
    for (std::vector<Carte>::size_type j = 0; j < V.size(); j++) {
        // Identifier le carte de couleur égale à celle de l'atout
        if (V[j].getCouleur() == T.getAllCards()[20].getCouleur()) {
            V[j].setAtout(1);  // Changer la valeur de l'atout
        }
    }
}

void affectation_atout_joueur(Table& T) { // Affectation de l'atout de paquet de chaque joueur
    vector<Joueur> joueurs = T.getJoueurs();
    for (int i = 0; i < 4; i++) { // Parcours des joueurs
        // Appel à la fonction Affectation_atout
        Joueur joueur = joueurs[i]; 
        Paquet_cartes playerPacket = joueur.get_player_paquet();
        vector <Carte> paquet = playerPacket.getPaquet();
    affectation_Atout(T, paquet);
}
}
int play(Table& T, int b,sf::Event event, string atout) {
    //Fonction de jeu
    //b est l'indice du joueur qui commence à jouer
    //retourne l'indice du joueur qui va joué apres b
    vector<Carte>& cartes = T.setJoueurs()[b].set_player_paquet().getPaquet();
    vector<Carte>& CardsOnTable = T.setCardsOnTable();
    vector<Carte> cartes_possible = T.setJoueurs()[b].cartes_possible(CardsOnTable, atout);
    bool canPlay = false;
    int po = cartes.size();
    int number;
    
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode >= '1' && event.text.unicode <= '8') {
            number = event.text.unicode - '0';
            for (int i =0 ; i<cartes_possible.size(); i++) {
                if (cartes_possible[i].getAddress0() == cartes[number-1].getAddress0()) {
                    canPlay = true;
                    break;
                }
            }
            if (number > po || !canPlay) {
                return b;
            }
            else {
                CardsOnTable.push_back(cartes[number-1]);
                cartes.erase(cartes.begin() + number-1);
                std::this_thread::sleep_for(std::chrono::seconds(1));
                return (b+1)%4;
            }
        }
        
    
    }
    else{
            return b;
        }
}

std::tuple<int, string>  talba(Table &T) {
    //Fonction pour choisir l'atout

    string atout;
    Menu m;
    string atout_temp;
    int number;
    int bid;
    int bid_temp;
    vector<Joueur> joueurs = T.getJoueurs();
    bool atout_chosen = false; 
    while (!atout_chosen) {
        for (int i = 0; i < 3; i++) {
            do{
                std::cout << "Entrer la couleur de l'atout "<< joueurs[i].getNom() << " (Coeur, trefle, Carreau, Pique,Passe): ";
                std::cin >> atout_temp; 

            }while(atout_temp!= "Coeur" && atout_temp!= "trefle" && atout_temp!= "Carreau" && atout_temp!= "Pique" && atout_temp!="Passe");
            if (atout_temp == "Passe") {
                number++;
            }
            else {
                number = 0;
                
                std::cout << "Entrer 190 si voulez annuler";
                do {    
                    std::cout << "Entrer le nombre de points que vous voulez miser: ";
                    
                    std::cin >> bid_temp;
                }while (bid_temp < 90 || bid_temp > 190 || bid_temp%10 != 0 || bid_temp <= bid); 
                if (bid_temp == 190) {
                    number++;
                }
                else {
                    atout = atout_temp;
                    bid = bid_temp;
                }
            }

        }
        if(number>=3){
            atout_chosen = true;
        }

    }
    std::cout << "L'atout est: " << atout << '\n';
    return {bid, atout};

        
}
