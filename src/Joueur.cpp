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
    


void Joueur::choisir_carte(vector<Carte>& Paquet, vector<Carte> cartes_possible){

    bool k = true;
    int card_index;
    do {
        std::cout << " Enter the number of the card you wanna play from 1 - " << Paquet.size()<< ": ";
        std::cin >> card_index ;
        for (int i = 0 ; i < cartes_possible.size(); i ++){
            if ( card_index < Paquet.size() && Paquet[card_index] == cartes_possible[i]){
                k = false;
            }
        }

    }while(k == false);
    std::cout << "Good choice !";
    Paquet.erase(Paquet.begin() + card_index + 1);

    
}

void Joueur::sortir_carte(vector<Carte>& CardsOnTable,Carte ChosenCard){
    CardsOnTable.push_back(ChosenCard);
    
}
