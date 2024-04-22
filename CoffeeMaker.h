#ifndef COFFEE_MAKER_H
#define COFFEE_MAKER_H

#include "Coffee.h"
#include "DrinkMaker.h"
#include <iostream>
#include <string>
using namespace std;

class CoffeeMaker : public DrinkMaker
{
public:
    CoffeeMaker(string coffeeType, bool addMilk, bool addSugar) 
        : DrinkMaker(CoffeeFactory::createCoffee(coffeeType), addMilk, addSugar) {}

    virtual void boilWater() const
    {
        cout << "Boiling water.\n";
    }

    virtual void grindBeans() const
    {
        cout << "Grinding coffee beans.\n";
    }

    virtual void applyFilter() const
    {
        cout << "Applying filter.\n";
    }

    void makeDrink() override
    {
        boilWater();
        grindBeans();
        applyFilter();
        cout << "Final Description: " << getDrink()->getDescription() << endl;
        cout << "Final Price: " << getDrink()->getPrice() << endl;
    }
};

class BlackCoffeeMaker : public CoffeeMaker
{
public:
    BlackCoffeeMaker(bool addMilk, bool addSugar) : CoffeeMaker("Black", addMilk, addSugar) {}
};

class WhiteCoffeeMaker : public CoffeeMaker
{
public:
    WhiteCoffeeMaker(bool addMilk, bool addSugar) : CoffeeMaker("White", addMilk, addSugar) {}
};

#endif