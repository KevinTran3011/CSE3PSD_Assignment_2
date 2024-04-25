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
        setName("Matcha Tea");
        setDescription("Matcha  green  Tea");
        setPrice(3.0);
        setTakeawayAvailable(false);
    }
};

class Chai : public Tea
{
public:
    Chai()
    {
        setName("Chai");
        setDescription("Chai");
        setPrice(2.5);
        setTakeawayAvailable(true);
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