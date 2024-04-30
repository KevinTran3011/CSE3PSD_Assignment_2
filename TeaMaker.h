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
    TeaMaker(string teaType, bool addMilk, bool addSugar ,bool isTakeaway)
        : DrinkMaker(nullptr)
    {
        Tea *tea = TeaFactory::createTea(teaType, isTakeaway);
        if (tea == nullptr)
        {
            throw std::invalid_argument("Invalid tea type");
        }
        drink = tea;
        if (addMilk)
        {
            this->drink = new MilkDecorator(this->drink);
        }
        if (addSugar)
        {
            this->drink = new SugarDecorator(this->drink);
        }
    }

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
    MatchaTeaMaker(bool addMilk, bool addSugar, bool isTakeaway) : TeaMaker("matcha", addMilk, addSugar,isTakeaway) {}
};

class ChaiMaker : public TeaMaker
{
public:
    ChaiMaker(bool addMilk, bool addSugar, bool isTakeaway) : TeaMaker("chai", addMilk, addSugar, isTakeaway) {}
};

#endif