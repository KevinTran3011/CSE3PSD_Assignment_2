#ifndef COFFEE_H
#define COFFEE_H

#include "Drinks.h"
using namespace std;

class Coffee : public Drink
{
public:
    virtual ~Coffee() {}
};

class BlackCoffee : public Coffee
{
public:
    BlackCoffee()
    {
        setDescription("Black Coffee");
        setPrice(2.0);
        takeawayAvailable = true;
    }
};

class WhiteCoffee : public Coffee
{
public:
    WhiteCoffee()
    {
        setDescription("White Coffee");
        setPrice(2.5);
        takeawayAvailable = true;
    }
};

class CoffeeFactory
{
public:
    static Coffee *createCoffee(const string &type)
    {
        if (type == "black")
            return new BlackCoffee();
        else if (type == "white")
            return new WhiteCoffee();
        else
            return nullptr;
    }
};

#endif
