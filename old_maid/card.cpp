#include "card.h"

Card::Card(int num, char st)
{
    number = num;
    suit = st;
}

void Card::print() 
{
    std::cout<<number;
    std::cout<<suit;
    std::cout<<' ';
}