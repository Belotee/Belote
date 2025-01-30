#include "../include/Joueur.h"

Joueur::Joueur(){
    Nom="";
    Rang=-1;
}

Joueur::Joueur(string name,int Rg){
	Nom=name;
	Rang=Rg;
}

string Joueur:: getNom()const{
    return Nom;
}


int Joueur:: getRang()const
{
    return Rang;
}
void Joueur::setRang(int& Rg) 
{
	Rang = Rg;
}

Paquet_cartes Joueur:: get_player_paquet()const
{
	return Paquet;
}
void Joueur:: set_player_paquet(Paquet_cartes& P){
	Paquet = P;
}

void Joueur::operator=(Joueur cop){
    Nom = cop.getNom();
    Rang = cop.getRang();
    Paquet = cop.get_player_paquet();
}

vector<Carte> Joueur::cartes_possible(vector<Carte> CardsOnTable,string atout){	
	vector<Carte> cartes;
    
    if (CardsOnTable.size()==0){
        return Paquet.getPaquet();
    }
    string col = CardsOnTable[0].getCouleur();
    bool hasAtout = false;
    bool hasCol = false;
    for (int i=0;i<Paquet.getPaquet().size();i++){
        if (Paquet.getPaquet()[i].getCouleur()==atout){
            hasAtout = true;
            break;
        }
    }
    for (int i=0;i<Paquet.getPaquet().size();i++){
        if (Paquet.getPaquet()[i].getCouleur()==col){
            hasCol = true;
            break;
        }
    }
   if (hasCol){
        for (int i=0;i<Paquet.getPaquet().size();i++){
            if (Paquet.getPaquet()[i].getCouleur()==col){
                cartes.push_back(Paquet.getPaquet()[i]);
            }
        }
    }
    else if (hasAtout && !hasCol){
        for (int i=0;i<Paquet.getPaquet().size();i++){
            if (Paquet.getPaquet()[i].getCouleur()==atout){
                cartes.push_back(Paquet.getPaquet()[i]);
            }
        }
    }
    else{
        return Paquet.getPaquet();
    }
    return cartes;
   } 
    


Carte Joueur::choisir_carte(vector<Carte>& cartes_possible){
    
}

void Joueur::sortir_carte(vector<Carte>& CardsOnTable,Carte ChosenCard){
    
}
