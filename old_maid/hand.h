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
    bool isempty();

    private:
    int ID;
    std::vector<Card> myhand;
};