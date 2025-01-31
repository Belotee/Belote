//#include <string>
//#include <cstdio>
//#include "../include/Functions.h"
//
//
//
//using namespace std;
//
//void distribute(Table& T, int NumberOfCardToDistribute = 8, int ending, int StartingCardPosition=1, int IndexOfFirstPlayer=0) {
//    int j = IndexOfFirstPlayer;  // el man
//    vector<Carte> packetTemp = {};  // vecteur fih el kaf mtaa kol wehed temp
//
//    for (int i = StartingCardPosition; i < ending; i++) {  // Distribute cards starting from the given position
//        if ((i - StartingCardPosition + 1) % NumberOfCardToDistribute == 0) {  // Once we reach the desired number of cards per player
//            packetTemp.push_back(T.getAllCards()[i - 1]);
//
//            Paquet_cartes paquet(packetTemp);  // Creating a Paquet_cartes object
//            (T.setJoueurs()[j]).set_player_paquet(paquet);  // Assign the Paquet_cartes to the player
//
//            packetTemp.clear();  // Clear the temporary packet after distribution
//            j = (j + 1) % 4;  // Move to the next player
//        } else {
//            packetTemp.push_back(T.getAllCards()[i - 1]);  // Add card to temporary packet
//        }
//    }
//}
//
//
//
//
//void affectation_Atout(Table& T, vector<Carte>& V) {		
//    // Changer la valeur d'atout de chaque Carte dans V à 1
//    for (int j = 0; j < V.size(); j++) {
//        // Identifier le carte de couleur égale à celle de l'atout
//        if (V[j].getCouleur() == T.getAllCards()[20].getCouleur()) {
//            V[j].setAtout(1);  // Changer la valeur de l'atout
//        }
//    }
//}
//
//void affeectation_atout_joueur(Table& T) { // Affectation de l'atout de paquet de chaque joueur
//    for (int i = 0; i < 4; i++) { // Parcours des joueurs
//        // Appel à la fonction Affectation_atout
//        affectation_Atout(T, T.getJoueurs()[i].get_player_paquet().getPaquet());
//    }
//}
//
//
//int verify(string s,int i){
//	if (s=="YES") return i;
//	else return -1;
//}
//int retour_indice(Table& T,QGridLayout* layout){
//		
//																			//Retourne l'indice de joueur qui prend l'atout 
//	int j=1;
//
//	affectation_Atout (T,T.setAllCards());													//changer l'atout tout les cartes de Table
//				
//	if (j==3 || j==1){																		//Changer l'atout de l'equipe 1
//		T.setT1().setatout()=1;
//	}
//	
//	else {																					//changer l'atout de l'equipe 2
//		T.setT2().setatout()=1;
//	}
//	return j;
//			
//			
//		
//
//	
//}

