#include "deck.h"
#include <random> //std::default_random_engine
#include <algorithm> //std::shuffle
#include <chrono> //std::chrono::system_clock

//create a 53 card deck where the last card is 0J standing for Joker
Deck::Deck()
{
    char suits[] = {'S','C','H','D'};
    for (int i=1; i<14; i++)
    {
        for (int j=0; j<4; j++)
        {
            Card newcard = Card(i, suits[j]);
            deck.push_back(newcard);
        }
    }
    Card joker = Card(0,'J');
    deck.push_back(joker);
}

//used for testing, should be deleted
void Deck::print()
{
    for (int i=0; i<deck.size(); i++)
    {
        deck[i].print();
    }
}

//use a shuffle function to reorder the deck randomly
void Deck::shuffledeck()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // found on cplusplus.com
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}

//create playcount number of hands then deal all cards between these hands, then check for pairs
void Deck::deal(int playercount)
{
    //create number of hands
    for (int i=0; i<playercount; i++)
    {
        Hand newhand = Hand(i);
        players.push_back(newhand);
    }
    
    //deal starting from player 0 and increment within the number of players using module
    for (int i=0; i<deck.size(); i++)
    {
        players[i%players.size()].addCard(deck[i]); 
    }

    // check for pairs before start playing
    for (int i=0; i<players.size(); i++)
    {
        players[i].checkPairs();
    }
}

//check if only one player is remaining in the game
void Deck::isDone()
{
    if (players.size() == 1)
    {
        //if there's only one player left, said message
        loser = true;
        std::cout<<"Congradulations player ";
        std::cout<<players[0].getID();
        std::cout<<", you have the old maid so you lose! \n";
    }
}

void Deck::removeplayer(int index)
{
    players.erase(players.begin()+index);
}

void Deck::play()
{
    //while no loser has been determined
    while (!loser)
    {
        //for each player still playing
        for (int i=0; i<players.size(); i++)
        {
            //show player to left's cards as Xs
            players[(i+1)%players.size()].printBack();
            //print current player's hand
            players[i].print();
            //ask player to pick card from player to left
            //move that card to current player's hand
            //check for pairs
            //check if empty and possibly remove from players vector
        }
    }
}

