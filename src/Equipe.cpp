#include "../include/Equipe.h"

Equipe::Equipe(){
    team = {};
}

Equipe::Equipe(Joueur& J1, Joueur& J2){
    team = {J1, J2};
}

int Equipe::getScore(){
    return score;
}

int& Equipe::setScore(){
    return score;
}

int& Equipe::setatout(){
    return atout;
}

string Equipe::afficheTeam(int k){
    string s="Equipe"+to_string(k)+"\n";
    for (std::vector<Joueur>::size_type  i=0;i<team.size();i++){
        s+=(team[i].getNom());
        s+="\n";
    }
    return s;
}