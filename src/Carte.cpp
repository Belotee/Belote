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

int Carte::compare(Carte C, string atout){

}