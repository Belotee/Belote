#ifndef EQUIPE_H
#define EQUIPE_H
#include "Joueur.h"


class Equipe
{
   vector<Joueur> team;             // Vecteur fih el zouz elli yalaabou maa baadhhom
                                      

   int score=0;                       // score de l'equipe 
                                      

   int atout=0;                    // Un booleen ikolek ken el aquipe hedhi khatret l'atout

public:
   Equipe();
	Equipe(Joueur&,Joueur&);         //Constructeur dequipe 
	int getScore(); 
   int& setScore();                //Accesseurs lel score
   int& setatout();            //Mutateur lel atout
   string afficheTeam(int k);

};

#endif 
