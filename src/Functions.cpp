#include <string>
#include <cstdio>
#include "../include/Functions.h"
#include <vector>

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
        //std::cout <<"fi west el fonction : "<< &carta <<'\n';
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
