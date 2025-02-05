#include "../include/Joueur.h"
using namespace std ;
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
Joueur::Joueur(const Joueur& other) {
    Nom = other.Nom;
    Rang = other.Rang;
    Paquet = other.Paquet;
}

Paquet_cartes Joueur:: get_player_paquet()const

{
	return Paquet;
}
Paquet_cartes& Joueur:: set_player_paquet(){
    return Paquet;

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
    for (size_t i=0;i<Paquet.getPaquet().size();i++){
        if (Paquet.getPaquet()[i].getCouleur()==atout){
            hasAtout = true;
            break;
        }
    }
    for (size_t i=0;i<Paquet.getPaquet().size();i++){
        if (Paquet.getPaquet()[i].getCouleur()==col){
            hasCol = true;
            break;
        }
    }
   if (hasCol){
        for (size_t i=0;i<Paquet.getPaquet().size();i++){
            if (Paquet.getPaquet()[i].getCouleur()==col){
                cartes.push_back(Paquet.getPaquet()[i]);
            }
        }
    }
    else if (hasAtout && !hasCol){
        for (size_t i=0;i<Paquet.getPaquet().size();i++){
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
    


int Joueur::choisir_carte(vector<Carte>& Paquet, vector<Carte> cartes_possible) {
    bool k = true;
    int card_index;
    do {
        std::cout << "Les cartes possible sont: "<<'\n';
        for (int j = 0; j<cartes_possible.size() ; j++){
                
                std::cout << cartes_possible[j].toString()<<'\n';
            }
        std::cout << "Enter the number of the card you wanna play from 1 - " << Paquet.size() << ": ";
        std::cin >> card_index;
        card_index--; // Adjust for 0-based indexing

        // Validate the chosen card
        for (size_t i = 0; i < cartes_possible.size(); i++) {
            if (card_index >= 0 && card_index < Paquet.size() && Paquet[card_index] == cartes_possible[i]) {
                k = false; // Valid card chosen
                break;
            }
        }
        if (k) {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (k);

    std::cout << "Good choice!\n";
    return card_index;
    Paquet.erase(Paquet.begin() + card_index); // Remove the chosen card from the player's hand
}
bool isValidColor(const string& color) {
    return (color == "Hearts" || color == "Diamonds" || color == "Clubs" || color == "Spades");
}
string Joueur::selectCardOrPass() {
    cout <<", select a card color (or type 'Passe' to pass): ";
    string input;
    cin >> input; // Get user input

    // Assuming you have a method to validate colors
    if (input == "Passe" || isValidColor(input)) {
        return input; // Return the selected color or "Passe"
    } else {
        cout << "Invalid selection. Please try again." << endl;
        return selectCardOrPass(); // Retry if input is invalid
    }
}
int Joueur :: setBid() {
    int bid;
    cout << Nom << ", enter your bid: ";
    cin >> bid; // Get user input for bid
    return bid;
}

