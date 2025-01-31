#include <string>
#include <cstdio>
#include "../include/Functions.h"



using namespace std;

void distribute(Table& T, int NumberOfCardToDistribute = 8, int ending, int StartingCardPosition=1, int IndexOfFirstPlayer=0) {
    int j = IndexOfFirstPlayer;  // el man
    vector<Carte> packetTemp = {};  // vecteur fih el kaf mtaa kol wehed temp

    for (int i = StartingCardPosition; i < ending; i++) {  // Distribute cards starting from the given position
        if ((i - StartingCardPosition + 1) % NumberOfCardToDistribute == 0) {  // Once we reach the desired number of cards per player
            packetTemp.push_back(T.getAllCards()[i - 1]);

            Paquet_cartes paquet(packetTemp);  // Creating a Paquet_cartes object
            (T.setJoueurs()[j]).set_player_paquet(paquet);  // Assign the Paquet_cartes to the player

            packetTemp.clear();  // Clear the temporary packet after distribution
            j = (j + 1) % 4;  // Move to the next player
        } else {
            packetTemp.push_back(T.getAllCards()[i - 1]);  // Add card to temporary packet
        }
    }
}




void affectation_Atout(Table& T, vector<Carte>& V) {		
    // Changer la valeur d'atout de chaque Carte dans V à 1
    for (int j = 0; j < V.size(); j++) {
        // Identifier le carte de couleur égale à celle de l'atout
        if (V[j].getCouleur() == T.getAllCards()[20].getCouleur()) {
            V[j].setAtout(1);  // Changer la valeur de l'atout
        }
    }
}

void affeectation_atout_joueur(Table& T) { // Affectation de l'atout de paquet de chaque joueur
    vector<Joueur> joueurs = T.getJoueurs();
    for (int i = 0; i < 4; i++) { // Parcours des joueurs
        // Appel à la fonction Affectation_atout
        Joueur joueur = joueurs[i]; 
        Paquet_cartes playerPacket = joueur.get_player_paquet();
        vector <Carte> paquet = playerPacket.getPaquet();

        affectation_Atout(T, paquet);
    }
}
