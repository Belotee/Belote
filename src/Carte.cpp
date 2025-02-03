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

Carte::Carte(const Carte& other) {
    // Copy all member variables from the other Carte object
    this->id = other.id;
    this->couleur = other.couleur;
    this->valeur = other.valeur;
    this->atout = other.atout;
    this->acces = other.acces;
    this->val_atout = other.val_atout;
    this->val_hors_atout = other.val_hors_atout;
    this->AddressVertical = other.AddressVertical;
    this->AddressHorizontal = other.AddressHorizontal;
}

string Carte::toString() const {
    if (atout == true){
        int val = this->getVal_atout();
        return "Couleur: " + this->couleur + ", Number: " + this->valeur + 
           ", Atout: " + (this->atout ? "Yes" : "No") + 
           ", Valeur = " + std::to_string(val);
    }
    else{
        int val = this->getVal_hors_atout();
        return "Couleur: " + this->couleur + ", Number: " + this->valeur + 
           ", Atout: " + (this->atout ? "Yes" : "No") + 
           ", Valeur = " + std::to_string(val);
    }

}


string Carte::getCouleur() const{
    return couleur;
}

void Carte::setCouleur(string& s){
    couleur = s;
}

string Carte::getValeur() const{
    return valeur;
}

void Carte::setValeur(string& s){
    valeur = s;
}

bool Carte::getAtout() const{
    return atout;
}

void Carte::setAtout(int a){
    atout = a;
}

int Carte::getAcces() const{
    return acces;
}

void Carte::setAcces(int& a){
    acces = a;
}

int Carte::getVal_atout() const{
    return val_atout;
}

void Carte::setVal_atout(int& a){
    val_atout = a;
}

int Carte::getVal_hors_atout() const{
    return val_hors_atout;
}

void Carte::setVal_hors_atout(int& a){
    val_hors_atout = a;
}

void Carte::operator=(const Carte& C) {
    if (this != &C) { // Avoid self-assignment
        couleur = C.couleur;
        valeur = C.valeur;
        atout = C.atout;
        acces = C.acces;
        val_atout = C.val_atout;
        val_hors_atout = C.val_hors_atout;
    }
}



bool Carte::operator==(const Carte& C) const {
    // Compare relevant attributes to determine equality
    return (couleur == C.couleur && valeur == C.valeur && atout == C.atout);
}



string Carte::getAddress90() const{
    return AddressVertical;
}
void Carte::setAddress90(string& a){
    AddressVertical = a;
}
string Carte::getAddress0() const{
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