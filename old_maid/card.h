#include <iostream>

class Card
{
    public:
    Card(int num, char st);
    void print();
    int getnum() {return number;}
    char getsuit() {return suit;}

    private:
    int number;
    char suit;
};
