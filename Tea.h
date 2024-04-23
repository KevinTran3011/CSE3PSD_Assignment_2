#ifndef TEA_H
#define TEA_H

#include "Drinks.h"
using namespace std;

class Tea : public Drink
{
public:
    virtual ~Tea() {}
};

class MatchaTea : public Tea
{
public:
    MatchaTea()
    {
        setDescription("Matcha Tea");
        setPrice(3.0);
        takeawayAvailable = true;
    }
};

class Chai : public Tea
{
public:
    Chai()
    {
        setDescription("Chai Tea");
        setPrice(2.5);
        takeawayAvailable = false;
    }
};

class TeaFactory
{
public:
    static Tea *createTea(const string &type)
    {
        if (type == "matcha")
            return new MatchaTea();
        else if (type == "chai")
            return new Chai();
        else
            return nullptr;
    }
};

#endif
