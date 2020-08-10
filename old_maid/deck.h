#include <iostream>
#include <vector>
#include "hand.h"

class Deck
{
    public:
    Deck();
    void print();
    void shuffledeck();
    void deal(int playercount);
    void play();
    bool isDone();

    private:
    std::vector<Card> deck;
    std::vector<Hand> players;
    bool loser = false;
    void removeplayer(int index);
};