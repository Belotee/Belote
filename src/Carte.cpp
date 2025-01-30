#include "../include/Carte.h"

Carte::Carte(){
    valeur = "out";
    couleur = "out";
    val_atout = -1;
    val_hors_atout = -1;

}

Carte::Carte(string val, string col, int Vatout, int VHatout){
    valeur = val;
    couleur = col;
    val_atout = Vatout;
    val_hors_atout = VHatout;

}

Carte::Carte(Carte* C){
    valeur = C->getValeur();
    couleur = C->getCouleur();
    val_atout = C->getVal_atout();
    val_hors_atout = C->getVal_hors_atout();

}

string& Carte::getCouleur(){
    return couleur;
}

void Carte::setCouleur(string& s){
    couleur = s;
}

string& Carte::getValeur(){
    return valeur;
}

void Carte::setValeur(string& s){
    valeur = s;
}

bool& Carte::getAtout(){
    return atout;
}

void Carte::setAtout(int a){
    atout = a;
}

int& Carte::getAcces(){
    return acces;
}

void Carte::setAcces(int& a){
    acces = a;
}

int& Carte::getVal_atout(){
    return val_atout;
}

void Carte::setVal_atout(int& a){
    val_atout = a;
}

int& Carte::getVal_hors_atout(){
    return val_hors_atout;
}

void Carte::setVal_hors_atout(int& a){
    val_hors_atout = a;
}

void Carte::operator=(Carte C){
    valeur = C.getValeur();
    couleur = C.getCouleur();
    atout = C.getAtout();
    acces = C.getAcces();
    val_atout = C.getVal_atout();
    val_hors_atout = C.getVal_hors_atout();

}

bool Carte::operator==(Carte C) {
    if (C.getCouleur() == couleur && C.getValeur() == valeur &&  C.getAtout() == atout){
        return true;
    }
    return false;
}

string Carte::getAddress90(){
    return AddressVertical;
}
void Carte::setAddress90(string& a){
    AddressVertical = a;
}
string Carte::getAddress0(){
    return AddressHorizontal;
}
void Carte::setAddress0(const string& s){
    AddressHorizontal = s;
}

int Carte:: compare (Carte obj,string atout) 
{

    if (couleur == atout){
        if(obj.getCouleur()==atout){
            int diff=val_atout-obj.getVal_atout();
            if (diff==0) return 0;
            else if (diff>0) return 1;
            else return -1;
        }
        else if (obj.getCouleur() != atout){
            int diff=val_atout-obj.getVal_hors_atout();
            if (diff==0) return 0;
            else if (diff>0) return 1;
            else return -1;
        }
    }
    else if (couleur != atout) {
        if (obj.getCouleur()==atout){
            int diff=val_hors_atout-obj.getVal_atout();
            if (diff==0) return 0;
            else if (diff>0) return 1;
            else return -1;
        }
        else if (obj.getCouleur() != atout){
            int diff=val_hors_atout-obj.getVal_hors_atout();
            if (diff==0) return 0;
            else if (diff>0) return 1;
            else return -1;
        }
    }
    return -1;
}