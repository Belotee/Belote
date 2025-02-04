#include "../include/Table.h"
#include <fstream>
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cstring>  // for strerror(errno)


Table::Table(vector<Joueur>& Players_list, Equipe& team1, Equipe& team2) {
    T1 = team1; // Assign to member variable
    T2 = team2; // Assign to member variable
    Joueurs = Players_list;

    std::ifstream sortie("../src/cards.txt"); // Base de donne
    if (sortie.is_open()) {
        for (int i = 0; i < 32; i++) {
            Carte temp;
            string couleur, valeur, address0, address90;
            int val_atout, val_hors_atout;

            sortie >> couleur;
            sortie >> valeur;
            sortie >> val_atout;
            sortie >> val_hors_atout;
            sortie >> address0;
            sortie >> address90;

            temp.setCouleur(couleur);
            temp.setValeur(valeur);
            temp.setVal_atout(val_atout);
            temp.setVal_hors_atout(val_hors_atout);
            temp.setAddress0(address0);
            temp.setAddress90(address90);

            AllCards.push_back(temp);
        }
    } else {
        std::cerr << "Error opening file: " << strerror(errno) << std::endl;
    }
}

vector<Carte> Table::getAllCards(){
    return AllCards;
}
vector<Carte>& Table::setAllCards(){
    return AllCards;
}

vector<Joueur> Table::getJoueurs(){
    return Joueurs;
}

vector<Joueur>& Table::setJoueurs(){
    return Joueurs;
}

Equipe Table::getT1(){
    return T1;
}

Equipe& Table::setT1(){
    return T1;
}

Equipe Table::getT2(){
    return T2;
}

Equipe& Table::setT2(){
    return T2;
}

vector<Carte> Table::getCardsOnTable(){
    return CardsOnTable;
}

vector<Carte>& Table::setCardsOnTable(){
    return CardsOnTable;
}

void Table::melange(){
    std::random_device rd;
    std::mt19937 g(rd()); 
    std::shuffle(AllCards.begin(), AllCards.end(), g); 
}

Carte Table::compareTableCards(string atout){
    Carte Highest_card = CardsOnTable[0];
    for(int i=1;i<4;i++){
		if (CardsOnTable[i].compare(Highest_card,atout)>0){
			Highest_card=CardsOnTable[i];
		}
	}
	return Highest_card;
}

int Table::joueur_gagnant(string atout,int b)  {
    int index_Highest_Card ; // fi cardsOnTable

    for(std::vector<Carte>::size_type i=0;i<CardsOnTable.size();i++)
    {
        if(CardsOnTable[i]==compareTableCards(atout)){
        index_Highest_Card =i;  
        }
    }
    //b : fiha l'indice mtaa el joueur elli laab lowel
    int res=(b+index_Highest_Card)%4;
    //res indice mtaa el joueur elli hazha
    return res;
}

int Table::somme_score(string atout){
    int somme=0;
    for(std::vector<Carte>::size_type i=0;i<CardsOnTable.size();i++)
    {
        if(CardsOnTable[i].getCouleur()== atout)
        {
            somme+=CardsOnTable[i].getVal_atout();
        }
        else
        {
            somme+=CardsOnTable[i].getVal_hors_atout();
        }
    }
    return somme;
}

void Table::Score(string atout, int b){
    int score_pli;
    if (joueur_gagnant(atout, b) == 0 || joueur_gagnant(atout, b) == 2){
        score_pli = somme_score(atout);
        T1.setScore() = T1.getScore() + score_pli ;
    
    }
    else{
        score_pli = somme_score(atout);
        T2.setScore() = T2.getScore() + score_pli ;

    }

}