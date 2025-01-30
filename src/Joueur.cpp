#include "../include/Joueur.h"

Joueur::Joueur(){
    Nom="";
    Rang=-1;
}

Joueur::Joueur(string name,int Rg)
{
	Nom=name;
	Rang=Rg;
}

string Joueur:: getNom()const
{
    return Nom;
}


int Joueur:: getRang()const
{
    return Rang;
}
int& Joueur::setRang()
{
	return Rang;
}

Paquet_cartes Joueur:: get_player_paquet()const
{
	return Paquet;
}
Paquet_cartes& Joueur:: set_player_paquet()
{
	return Paquet;
}

void Joueur::operator=(Joueur cop)
{
    Nom = cop.getNom();
    Rang = cop.getRang();
    Paquet = cop.get_player_paquet();}

vector<Carte> Joueur::cartes_possible(vector<Carte> CardsOnTable,string atout)
{	
	vector<Carte> cartes;
    if (CardsOnTable.size()==0){
        return Paquet.getPaquet();
    }
    else{
        for(int i=0;i<Paquet.getPaquet().size();i++)
        {
            if (Paquet.getPaquet()[i].getCouleur()==CardsOnTable[0].getCouleur() || Paquet.getPaquet()[i].getCouleur()==atout){
                cartes.push_back(Paquet.getPaquet()[i]);
            }
        }
        if (cartes.size()==0){
            return Paquet.getPaquet();
        }
        return cartes;
        
    }
	
}

Carte Joueur::choisir_carte(vector<Carte>& cartes_possible){
    cout<<"Choisir un numero entre 1 et "<<cartes_possible.size()<<endl;
    int i;cin>>i;
    return cartes_possible[i-1];
}

void Joueur::sortir_carte(vector<Carte>& CardsOnTable,Carte ChosenCard)
{
    vector<Carte> Temp=Paquet.setPaquet();
    vector<Carte>::iterator itr,storePosition;
    for(itr=Temp.begin();itr!=Temp.end();itr++){
        if ((*itr)==ChosenCard){
            storePosition=itr;
            break;
        }
    }
    Temp.erase(storePosition);
	CardsOnTable.push_back(ChosenCard);
}
