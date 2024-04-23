#ifndef TEA_MAKER_H
#define TEA_MAKER_H

#include "Tea.h"
#include "DrinkMaker.h"
#include <iostream>
#include <string>
using namespace std;

class TeaMaker : public DrinkMaker
{
public:
    TeaMaker(string teaType, bool addMilk, bool addSugar)
        : DrinkMaker(TeaFactory::createTea(teaType), addMilk, addSugar) {}

    virtual void boilWater() const
    {
        cout << "Boiling water.\n";
    }

    virtual void steepTea() const
    {
        cout << "Steeping tea.\n";
    }

    virtual void addLemon() const
    {
        cout << "Adding lemon.\n";
    }

    void makeDrink() override
    {
        boilWater();
        steepTea();
        addLemon();
        cout << "Final Description: " << getDrink()->getDescription() << endl;
        cout << "Final Price: " << getDrink()->getPrice() << endl;
    }
};

class MatchaTeaMaker : public TeaMaker
{
public:
    MatchaTeaMaker(bool addMilk, bool addSugar) : TeaMaker("matcha", addMilk, addSugar) {}
};

class ChaiMaker : public TeaMaker
{
public:
    ChaiMaker(bool addMilk, bool addSugar) : TeaMaker("chai", addMilk, addSugar) {}
};

#endif
