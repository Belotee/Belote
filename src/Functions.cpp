    #include <string>
    #include <cstdio>
    #include "../include/Functions.h"
    #include <vector>
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <iostream>

    using namespace std;

    void distribute(Table& T,  int ending, int StartingCardPosition) {
        vector<Carte> packetTemp ;
        
        vector<Joueur>& joueurs = T.setJoueurs() ;
        StartingCardPosition = 0;
        ending = 8;
        for ( size_t i = 0 ; i <4; i++){
            
            Paquet_cartes& carta = joueurs[i].set_player_paquet();
            packetTemp = {};
            for (int j= StartingCardPosition; j<ending; j++){
                packetTemp.push_back(T.getAllCards()[j]);
            }
            carta.setPaquet(packetTemp);
            
            StartingCardPosition += 8;
            ending += 8;
            
        } 
        std::cout <<'\n';   

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
        //retourne l'indice du joueur qui a gagné le pli

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
                    return (b+1)%4;
                }


            }
        
        }


    }