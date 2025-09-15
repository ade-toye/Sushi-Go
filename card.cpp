#include "card.h"

const int SUIT_COUNT = 4;
const int NUMBER_COUNT = 13;
const string SUITS[] = { "Spade", "Club", "Heart", "Diamond" };
const string NUMBERS[] = { "Two", "Three", "Four", "Five",
                           "Six", "Seven", "Eight", "Nine", "Ten",
                           "Jack", "Queen", "King", "Ace" };
/*
 * Constructor: Option #1
 * When no arguments are specified, the number and suit of the
 * card are randomly generated.
 */
Card::Card(){
   srand(time(0)); // Initialize the random number generator
   
   suit = (rand() % SUIT_COUNT);
   suit = (rand() % NUMBER_COUNT);
}

/*
 * Constructor: Option #2
 * When a single number is specified it is interpretted as an 
 * index in a 52-card deck and the suit/number are inferred.
 */
Card::Card(int index){
    if(index < 0 || index > 51){
        cerr << "Error: Specified card index out of range" << endl;
        exit(EXIT_FAILURE);
    }
    
    this->suit = index / NUMBER_COUNT;
    this->number = index % NUMBER_COUNT;
}

/*
 * Constructor: Option #3
 * The card's suit and number are both specified.
 */
Card::Card(int suit, int number){
    if(suit < 0 || suit >= SUIT_COUNT){
        cerr << "Error: Specified card suit out of range" << endl;
        exit(EXIT_FAILURE);
    }else if(number < 0 || number >= NUMBER_COUNT){
        cerr << "Error: Specified card number out of range" << endl;
        exit(EXIT_FAILURE);
    }
    
    this->suit = suit;
    this->number = number;
}

// Suit getter
string Card::getSuit(){
    return SUITS[suit];
}

// Number getter
string Card::getNumber(){
    return NUMBERS[number];
}

// Suit setter
void Card::setSuit(string suit_str){
    for(int i = 0; i < SUIT_COUNT; i++){
        if(SUITS[i] == suit_str){
            suit = i;
        }
    }
}

// Number setter
void Card::setNumber(string num_str){
    for(int i = 0; i < NUMBER_COUNT; i++){
        if(NUMBERS[i] == num_str){
            number = i;
        }
    }
}

// Prints the card
void Card::print_card() {
    string top = "  _________  \n";
    string second = " /         \\ \n";
    string blank = "|           |\n";
    string bottom = " \\_________/ \n";
    
    // Determine the "number" to print on the card
    string num_str;
    if (number < 8) {
        num_str = to_string(number + 2);
    } else {
        num_str = NUMBERS[number][0];
    }
    
    // Print the card
    cout << top << second;
    cout << "| ";
    if (suit > 1) {
        screen_fg("red");
    }
    cout << num_str;
    screen_fg("white");
    cout << "         |\n";
    cout << "| ";
    if (suit > 1) {
        screen_fg("red");
    }
    cout << SUITS[suit][0];
    screen_fg("white");
    cout << "         |\n";
    for (int i = 0; i < 3; i++) {
        cout << blank;
    }
    cout << "|         ";
    if (suit > 1) {
        screen_fg("red");
    }
    cout << SUITS[suit][0];
    screen_fg("white");
    cout << " |\n";
    cout << "|         ";
    if (suit > 1) {
        screen_fg("red");
    }
    cout << num_str;
    screen_fg("white");
    cout << " |\n";
    cout << bottom;
    cout << NUMBERS[number] << " of " << SUITS[suit] << "s\n\n";
}
