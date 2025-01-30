#ifndef JOUEUR_H_
#define JOUEUR_H_
#include "Paquet_cartes.h"

using namespace std ;
class Joueur
{
private:

	int Rang; 					//Rang 
	string Nom;					 
	Paquet_cartes Paquet;       //kafou aamek el joueur
	
    

public:

	Joueur();
	Joueur(string,int);                //constructeur
	int getRang()const;			         
	int& setRang();
	string getNom()const; 				  

	Paquet_cartes get_player_paquet()const;  //nefdhahlou kafou
	Paquet_cartes& set_player_paquet(); //naatih kaf(paquet)
	
	void operator=(Joueur); //bech najem nkhadem el =

	vector<Carte> cartes_possible(vector<Carte>,string);// nchouf el kwaret elli tnajem tetelaab
	Carte choisir_carte(vector<Carte>&); // yaatini karta a tetfasakh mel paquet
	void sortir_carte(vector<Carte>&,Carte);//nzid el carta lel table mtaa el played cards
};



#endif