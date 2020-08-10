#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <string>
#include <sstream>

#include "deck.h"

using namespace std;


int main() {
    //for testing, set playercount to 3
    int playercount = 0;
    string input = "";

    //create and shuffle a 53 card deck
    Deck deck1 = Deck();
    deck1.shuffledeck();

    //ask for number of players and deal out deal to those players
    //found on cplusplus.com
    while (true) {
        std::cout << "How many players are playing? ";
        getline(std::cin, input);

        // This code converts from string to number safely.
        stringstream myStream(input);
        if (myStream >> playercount)
            break;
        cout << "Invalid number, please try again" << endl;
    }
    
    deck1.deal(playercount);
    deck1.play();
    
    return 0;
}