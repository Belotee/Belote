#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>

using namespace std ;
class Menu {
private:
    vector<std::string> options; 
    int selectedOption;               

public:

    Menu();

    
    void addOption(const string& option);

    
    void displayMenu() const;

   
    void navigateMenu();

 
    int getSelectedOption() const;

 
    ~Menu();
};

#endif
