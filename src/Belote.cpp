#include "include/Carte.h"
#include "include/Paquet_cartes.h"
#include "include/Joueur.h"
#include "include/Equipe.h"
#include "include/Table.h"
#include "include/Functions.h"
#include <vector>
#include <iostream>

int playerIndex = 0;

int main() {
    // Step 1: Create Players
    Joueur player1("Player1", 1);
    //std::cout << "player 1 adress: "<<&player1 <<'\n';
    Joueur player2("Player2", 2);
    Joueur player3("Player3", 3);
    Joueur player4("Player4", 4);

    vector<Joueur> Players_list = { player1,  player2,  player3 ,  player4};
    Equipe team1(player1, player3);
    Equipe team2(player2, player4);
    
    bool ala = false;
    string atout ;

    while (ala == false){
        Table table( Players_list, team1, team2);

        table.melange();
        distribute(table, 8, 32);



        for (size_t i = 0; i < 4; ++i) {
            vector<Carte> cartes = table.setJoueurs()[i].set_player_paquet().getPaquet();
            std::cout<<"---------------------"<< "PLAYER "<<i+1<<"---------------------"<<'\n';
            for (int j = 0; j<8 ; j++){
                std::cout << cartes[j].toString()<<'\n';
            }
            std::cout<<'\n';
        }
        cin >> atout; 
        for (size_t i = 0; i < 4; ++i) {
            vector<Carte>& cartes = table.setJoueurs()[i].set_player_paquet().getPaquet();
            std::cout<<"---------------------"<< "PLAYER "<<i+1<<"---------------------"<<'\n';
            for (int j = 0; j<8 ; j++){
                if (cartes[j].getCouleur() == atout){
                    cartes[j].setAtout(1);
                    
                }
                std::cout << cartes[j].toString()<<'\n';
            }
            std::cout<<'\n';
        } 
        std::cout << "-----------------------------------"<< "NOW WE PLAY"<< "-----------------------------------" <<'\n'<<'\n';
        vector<Carte>& CardsOnTable = table.setCardsOnTable();
        for (int i = 0 ; i<8 ; i++){
            
            CardsOnTable = {};
            for (int j = 0; j<4 ; j++){
                vector<Carte>& cartes = table.setJoueurs()[playerIndex].set_player_paquet().getPaquet();
                for (int m = 0; m<cartes.size() ; m++){
                    std::cout << cartes[m].toString()<<'\n';
                }
                std::cout << "PLAYER "<<playerIndex+1<<" :"<<'\n';
                vector<Carte>& kaf = table.setJoueurs()[playerIndex].set_player_paquet().getPaquet();
                Joueur& joueur = table.setJoueurs()[playerIndex];
                int card_index = joueur.choisir_carte(kaf, joueur.cartes_possible(CardsOnTable,atout));
                CardsOnTable.push_back(kaf[card_index]);
                kaf.erase(kaf.begin() + card_index);
                std::cout << kaf.size()<<'\n';
                playerIndex = (playerIndex + 1)%4;
            }
            std::cout << "----------"<<"THE CARDS THAT HAVE BEEN PLAYED ARE "
                << "------------------"<<'\n';
            for (int    k = 0; k<4;k++){
                
                std::cout<<CardsOnTable[k].toString()<<'\n';

            }
            std::cout << "----------"<<"THE WINNER IS "
                << "------------------"<<'\n';
            playerIndex = table.joueur_gagnant(atout, playerIndex);
            std::cout<<table.setJoueurs()[playerIndex].getNom()<<'\n';
            table.Score(atout,playerIndex);
            std::cout << "----------"<<"THE SCORES ARE "
                << "------------------"<<'\n';
            std::cout<<"TEAM 1: "<<table.getT1().getScore()<<'\n';
            std::cout<<"TEAM 2: "<<table.getT2().getScore()<<'\n';
        }

        ala = true;



    }   
    


    return 0;
}
