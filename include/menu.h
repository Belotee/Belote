#ifndef MENU_H
#define MENU_H

#include "../include/Belote.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Menu {
private:
    vector<std::string> options; 
    int selectedOption;               

public:
    Menu();
    ~Menu(); // Destructor declaration
    void displayMenu();
    void addOption(const string& option);
    void navigateMenu();
    int getSelectedOption() const;
};

#endif