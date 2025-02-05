#ifndef TABLE_H
#define TABLE_H
#include <vector>
#include "Equipe.h"


using namespace std ;

class Table
//Documentation
{
    vector<Carte> CardsOnTable;             //el kwaret elli tlaabet
                                            
    int nbr_pli = 8;                        //kadeh men plis fi jarya
    vector<Carte> AllCards;                 //el kwaret mtaa el looba lkol
    vector<Joueur> Joueurs ;                 //the players
    Equipe T1,T2;                        //les deux equipes
    


public:
    Table(vector<Joueur>&,Equipe&,Equipe&);  // constructor

    vector<Carte> getAllCards();            //Accesseur lel AllCards
    vector<Carte>& setAllCards();
    vector<Joueur> getJoueurs();             //Accesseur lel Joueurs
    vector<Joueur>& setJoueurs();
    Equipe getT1();                         //Accesseur lel T1
    Equipe& setT1();

    Equipe getT2();                         //Accesseur lel T2
    Equipe& setT2();
    vector<Carte> getCardsOnTable();
    vector<Carte>& setCardsOnTable();
    void melange();                  //tmachki
    Carte compareTableCards(string);
    void Score(string,int);
    int somme_score(string);
    int joueur_gagnant(string,int); //return l'indice mtaa el joueur elli rebah fel vecteur joueurs(rebah el plis)
        

};

#endif 
