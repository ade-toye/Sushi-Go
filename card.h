#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
#include <ctime> 
#include "termfuncs.h"

using namespace std;

class Card {
public:
    // Constructors
    Card(); 
    Card(int index); 
    Card(int suit, int number); 
    
    // Getters
    string getSuit();
    string getNumber();
    
    // Setters
    void setSuit(string suit_str);
    void setNumber(string num_str);
    
    // Print function
    void print_card();
    
private:
    int suit;
    int number;
};

#endif
