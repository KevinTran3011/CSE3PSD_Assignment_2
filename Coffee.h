#ifndef COFFEE_H
#define COFFEE_H

#include "Drinks.h"
using namespace std;

class Coffee : public Drink
{
protected:
    bool takeawayAvailable;

public:
    virtual ~Coffee() {}
    virtual bool isTakeawayAvailable() const override { return takeawayAvailable; }
};

class BlackCoffee : public Coffee
{
public:
    BlackCoffee(bool isTakeaway)
    {
        setName("Black Coffee");
        setDescription("Black coffee");
        setPrice(2.0);
        takeawayAvailable = isTakeaway ? true : true;
    }
};

class WhiteCoffee : public Coffee
{
public:
    WhiteCoffee(bool isTakeaway)
    {
        setName("White Coffee");
        setDescription("White Coffee");
        setPrice(2.5);
        takeawayAvailable = isTakeaway ? false : true;
    }
};

class CoffeeFactory
{
public:
    static Coffee *createCoffee(const string &type, bool isTakeaway)
    {
        if (type == "black")
            return new BlackCoffee(isTakeaway);
        else if (type == "white")
            return new WhiteCoffee(isTakeaway);
        else
            return nullptr;
    }
};

#endif
