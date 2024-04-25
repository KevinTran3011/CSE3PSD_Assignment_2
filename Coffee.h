#ifndef COFFEE_H
#define COFFEE_H

#include "Drinks.h"
using namespace std;

class Coffee : public Drink
{
public:
    virtual ~Coffee() {}
    bool isTakeawayAvailable() const override
    {
        // Set breakpoint here
        return takeawayAvailable;
    }
};

class BlackCoffee : public Coffee
{
public:
    BlackCoffee()
    {
        setName("Black Coffee");
        setDescription("Black coffee ");
        setPrice(2.0);
        setTakeawayAvailable(true);
    }
};

class WhiteCoffee : public Coffee
{
public:
    WhiteCoffee()
    {
        setName("White Coffee");
        setDescription("White Coffee");
        setPrice(2.5);
        setTakeawayAvailable(true);
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