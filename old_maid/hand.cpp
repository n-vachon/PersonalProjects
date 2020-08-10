#include "hand.h"
#include <algorithm>
#include <functional>

Hand::Hand(int id)
{
    ID = id;
}

void Hand::addCard(Card next)
{
    myhand.push_back(next);
}

//print player's ID and their current hand
void Hand::print()
{
    std::cout<<"player ";
    std::cout<<ID;
    std::cout<<": ";
    for (int i=0; i<myhand.size(); i++)
    {
        myhand[i].print();
    }
    std::cout<<std::endl;
}

//print player's ID and the number of cards in their current hand as Xs
void Hand::printBack()
{
    std::cout<<"player ";
    std::cout<<ID;
    std::cout<<": ";
    for (int i=0; i<myhand.size(); i++)
    {
        std::cout<<"X ";
    }
    std::cout<<std::endl;
}

//search current hand for mathcing numbers and remove from hand if found
void Hand::checkPairs()
{
    int i = 0;
    while (i < myhand.size())
    {
        int j = i+1;
        while (j<myhand.size())
        {
            if (myhand[i].getnum() == myhand[j].getnum())
            {
                //erase j first because j>i
                myhand.erase(myhand.begin()+j); 
                myhand.erase(myhand.begin()+i);
                //restart j as the card in position i has changed
                j=i+1;  
            }
            else
            {
                j++;
            } 
        }
        i++;
    }
}

int Hand::cardsLeft()
{
    return myhand.size();
}

Card Hand::giveCard(int index)
{
    Card togive = myhand[index];
    myhand.erase(myhand.begin()+index);
    return togive;
}