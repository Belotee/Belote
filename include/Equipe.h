#ifndef EQUIPE_H
#define EQUIPE_H
#include "Joueur.h"


class Equipe
//classe dediee aux 2 joueurs de chaque equipe, calcule le score en temps reel et verify ses decisions
{
   vector<Joueur> team;             /* Vecteur contenant les coequipiers 
                                       dans une equipe sous forme d'objet joueur*/

   int score=0;                       /* Un entier definissant le score d'une equipe 
                                       tout au long du jeu et en temps reel avec chaque pli*/

   int atout=0;                    // Un booleen qui indique si l'equipe designee a choisi l'atout ou non

public:
   Equipe();
	Equipe(Joueur&,Joueur&);         //Constructeur d'equipe de deux joueurs
	int getScore(); 
   int& setScore();                //Accesseurs de l'attribut privee score
   int& setatout();            //Mutateur de l'attribut privee atout
   string afficheTeam(int k);

};

#endif // EQUIPE_H
