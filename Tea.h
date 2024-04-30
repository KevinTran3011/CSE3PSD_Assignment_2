#ifndef TEA_H
#define TEA_H

#include "Drinks.h"
using namespace std;

class Tea : public Drink
{

    protected:
    bool takeawayAvailable;
public:
    virtual ~Tea() {}
        virtual bool isTakeawayAvailable() const override { return takeawayAvailable; }

};

class MatchaTea : public Tea
{
public:
    MatchaTea(bool isTakeaway)
    {
        setName("Matcha Tea");
        setDescription("Matcha  green  Tea");
        setPrice(3.0);
takeawayAvailable = isTakeaway ? true : true;    }
};

class Chai : public Tea
{
public:
    Chai(bool isTakeaway)
    {
        setName("Chai");
        setDescription("Chai");
        setPrice(2.5);
        takeawayAvailable = isTakeaway ? false : true;
    }
};

class TeaFactory
{
public:
    static Tea *createTea(const string &type, bool isTakeaway)
    {
        if (type == "matcha")
            return new MatchaTea(isTakeaway);
        else if (type == "chai")
            return new Chai(isTakeaway);
        else
            return nullptr;
    }
};

#endif