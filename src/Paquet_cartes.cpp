#include "../include/Paquet_cartes.h"

Paquet_cartes::Paquet_cartes(){
    Paquet = {};
}

Paquet_cartes::Paquet_cartes(vector<Carte>& kafek){
    Paquet = kafek;
}

vector<Carte>& Paquet_cartes::getPaquet(){
    return Paquet;
}

void Paquet_cartes::setPaquet(const vector<Carte>& newPaquet) {
    
    Paquet = newPaquet; 
    
}

Paquet_cartes::~Paquet_cartes() {
    Paquet.clear();  // Clears the vector
}

Paquet_cartes& Paquet_cartes::operator=(const Paquet_cartes& kaf) {
    if (this != &kaf) {  // Prevent self-assignment
        Paquet = kaf.Paquet;  // Properly copy the vector
    }
    return *this;
}



Paquet_cartes::Paquet_cartes(const Paquet_cartes& other) {
    Paquet = other.Paquet;
}
//176
//7109