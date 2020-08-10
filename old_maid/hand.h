#include <iostream>
#include <string>
#include <vector>
#include "card.h"

class Hand
{
    public:
    Hand(int id);
    void addCard(Card next);
    void print();
    void printBack();
    void checkPairs();
    int getID() {return ID;}
    int cardsLeft();
    Card giveCard(int index);

    private:
    int ID;
    std::vector<Card> myhand;
};