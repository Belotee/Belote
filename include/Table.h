#ifndef TABLE_H
#define TABLE_H
#include <vector>
#include "Equipe.h"


using namespace std ;

class Table
//Documentation
{
    vector<Carte> CardsOnTable;             /*Conteneur correspondant aux 4 cartes 
                                              mise par chaque joueur sur la table*/
    int nbr_pli = 8;                        //Nombre de pli durant une manche
    vector<Carte> AllCards;                 //Conteneur contenant toutes les cartes du jeu
    vector<Joueur> Joueurs;                 //Conteneur contenant les 4 joueurs qui sont en train de jouer
    Equipe T1,T2;                        //Deux objets de classe equipe qui contiennent les deux equipes


public:
    Table(vector<Joueur>&,Equipe&,Equipe&);

    vector<Carte> getAllCards();            //Accesseur attribut AllCards
    vector<Carte>& setAllCards();
    vector<Joueur> getJoueurs();             //Accesseur attribut Joueurs
    vector<Joueur>& setJoueurs();
    Equipe getT1();                         //Accesseur Attribut T1
    Equipe& setT1();

    Equipe getT2();                         //Accesseur Attribut T2
    Equipe& setT2();
    vector<Carte> getCardsOnTable();
    vector<Carte>& setCardsOnTable();
    void melange();                  //Melange des cartes du vecteur AllCards
    Carte compareTableCards(string);
    void Score(string,int);
    int somme_score(string);
    int joueur_gagnant(string,int);
        

};

#endif // TABLE_H
