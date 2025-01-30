#ifndef PAQUET_CARTES_H_
#define PAQUET_CARTES_H_
#include "Carte.h"
#include <vector>
#include <iostream>
using namespace std;
class Paquet_cartes
{
    vector<Carte> Paquet;                       //vecteur fih el kaf mtaa ensen
                                                  

    public:
            Paquet_cartes();
            Paquet_cartes(vector<Carte>&);      //constructor
            // ~Paquet_cartes();                   //Destructeur 
            void operator=(Paquet_cartes);

            vector<Carte> getPaquet();         //return el kaf
            vector<Carte>& setPaquet();     //taati el kaf

};


#endif