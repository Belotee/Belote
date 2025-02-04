#ifndef PAQUET_CARTES_H_
#define PAQUET_CARTES_H_
#include "Carte.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class Paquet_cartes
{
    vector<Carte> Paquet;                       //vecteur fih el kaf mtaa ensen
                                                  

    public:
            Paquet_cartes();
            Paquet_cartes(const Paquet_cartes& other);
            Paquet_cartes(vector<Carte>&);      //constructor
            ~Paquet_cartes();                   //Destructeur 
            Paquet_cartes& operator=(const Paquet_cartes& );

            vector<Carte>& getPaquet();         //return el kaf
            void setPaquet(const vector<Carte>& );     //taati el kaf

};


#endif