#include "../include/Paquet_cartes.h"

Paquet_cartes::Paquet_cartes(){
    Paquet = {};
}

Paquet_cartes::Paquet_cartes(vector<Carte>& kafek){
    Paquet = kafek;
}

vector<Carte> Paquet_cartes::getPaquet(){
    return Paquet;
}

vector<Carte>& Paquet_cartes::setPaquet() {
    return Paquet;
}

void Paquet_cartes::operator=(Paquet_cartes kaf){
    Paquet = kaf.Paquet;
}