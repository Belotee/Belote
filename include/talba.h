#ifndef TALBA_H
#define TALBA_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Suit { NONE, TREFLE, HEART, CARREAU, PIQUE };

class Talba {
public:
    Suit trumpSuit;
    int highest_bid;
    int current_player;
    vector<string> players;
    Talba() : trumpSuit(NONE) {} // Constructor initializes no trump suit

    void setTrump(Suit chosenSuit);



};

#endif
