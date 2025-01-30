#ifndef CARTE_H_
#define CARTE_H_
#include<string>
using namespace std;

class Carte 
                                        //class to define card carct
{
    int id;                             
	string couleur;                     //card's color(hob, sbata ...)
	string valeur;                      //the cards current value
    bool atout = 0;                     // True if the card is atout snn 0
    int acces = 1;                      //True if the player can play the card
    int val_atout;                      //the cards value in atout
	int val_hors_atout;                 //the cards value out of atout
    string AddressVertical;
    string AddressHorizontal;


public:

    Carte();                            //Constructeur without parameters 
    Carte(string,string,int,int);       //Constructeur with parametrs
    Carte(Carte*);                      //Constructeur to copy

	string& getCouleur();               //returns the cards color
	void setCouleur(string& s);         //changes the color

    string& getValeur();                //rreturn value
    void setValeur(string& s) ;         //to set the value  

    bool& getAtout();                   //check if it's part of atout
    void setAtout(int a);               //change atout

    int& getAcces();                    //return if there's access or not
    void setAcces(int& a);              //change access 

    int& getVal_atout();                //return card's atout value
    void setVal_atout(int& a);          //change card's atout value

    int& getVal_hors_atout();           //rreturn card's value out of atout
    void setVal_hors_atout(int& a);     //change card's vlaue outidse of aotut
    
    void operator=(Carte);              // Overloading the assignment operator  
	bool operator==(Carte);             // Overloading the equality operator to check for equality  
	
    string getAddress0();
    void setAddress0(const string& s);

    string getAddress90();
    void setAddress90(string& s);
	
    int compare (Carte,string);         //compare two cards //atout=couleur
};

#endif