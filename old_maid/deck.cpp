#include "deck.h"
#include <random> //std::default_random_engine
#include <algorithm> //std::shuffle
#include <chrono> //std::chrono::system_clock
#include <string>
#include <sstream> 

using namespace std;

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
bool Deck::isDone()
{
    if (players.size() == 1)
    {
        //if there's only one player left, said message
        loser = true;
        std::cout<<"Congradulations player ";
        std::cout<<players[0].getID();
        std::cout<<", you have the old maid so you lose! \n";
    }
    return loser;
}

void Deck::removeplayer(int index)
{
    players.erase(players.begin()+index);
}

void Deck::play()
{
    string input = "";
    //while no loser has been determined and game is not done
    while (!isDone())
    {
        //for each player still playing
        for (int i=0; i<players.size(); i++)
        {
            int nextplayer = (i+1)%players.size();
            int cardselect;
            //show player to left's cards as Xs
            players[nextplayer].printBack();
            //print current player's hand
            players[i].print();
            //ask player to pick card from player to left
            //found on cplusplus.com
            while (true) {
                std::cout<<"pick one card from the other player's hand (1 - ";
                std::cout<<players[nextplayer].cardsLeft();
                std::cout<<") \n";
                getline(std::cin, input);

                // This code converts from string to number safely.
                stringstream myStream(input);
                if (myStream >> cardselect)
                {
                    if (cardselect > 0 && cardselect <= players[nextplayer].cardsLeft())
                        break;
                }
                cout << "Invalid number, please try again" << endl;
            }
            //move that card to current player's hand
            // the giveCard function also removes the card from that player's hand
            players[i].addCard(players[nextplayer].giveCard(cardselect-1));
            //check for pairs
            players[i].checkPairs();

            //to test
            players[i].print();

            //check if empty and possibly remove from players vector
            if (players[i].cardsLeft() == 0)
            {
                removeplayer(i);
            }
            if (players[nextplayer].cardsLeft() == 0)
            {
                removeplayer(nextplayer);
            }
        }
    }
}

