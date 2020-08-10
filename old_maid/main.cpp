#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

#include "deck.h"


int main() {
    //for testing, set playercount to 3
    int playercount = 3;

    //create and shuffle a 53 card deck
    Deck deck1 = Deck();
    deck1.shuffledeck();

    //ask for number of players and deal out deal to those players

    //std::cout<<"how many players are playing?";
    //std::cin>>playercount;
    //std::cout<<std::endl;

    //if (isdigit(playercount))
    //{
        deck1.deal(playercount);
    //}

    deck1.play();
    
    return 0;
}