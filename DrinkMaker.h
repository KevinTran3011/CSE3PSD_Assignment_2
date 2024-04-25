#ifndef DRINK_MAKER_H
#define DRINK_MAKER_H

#include "Drinks.h"
#include "Tea.h"
#include "Coffee.h"
#include <iostream>
#include <string>
using namespace std;

class Drink;
class Order;

class MilkDecorator : public Drink
{
private:
    Drink *drink;

public:
    MilkDecorator(Drink *drink) : drink(drink)
    {
        this->takeawayAvailable = drink->isTakeawayAvailable();
    }

    double getPrice() const override
    {
        return drink->getPrice() + 0.5;
    }

    string getDescription() const override
    {
        return drink->getDescription() + ", with milk";
    }
};

class SugarDecorator : public Drink
{
private:
    Drink *drink;

public:
    SugarDecorator(Drink *drink) : drink(drink)
    {
        this->takeawayAvailable = drink->isTakeawayAvailable();
    }

    double getPrice() const override
    {
        return drink->getPrice() + 0.2;
    }

    string getDescription() const override
    {
        return drink->getDescription() + ", with sugar";
    }
};

class DrinkFactory
{
public:
    static Drink *createDrink(string drinkType)
    {
        if (drinkType == "coffee")
        {
            return new Coffee();
        }
        else if (drinkType == "tea")
        {
            return new Tea();
        }
        else
        {
            return nullptr;
        }
    }
};

class DrinkMaker
{
protected:
    Drink *drink;

public:
    DrinkMaker(Drink *drink = nullptr, bool addMilk = false, bool addSugar = false) : drink(drink)
    {
        bool takeawayAvailable = drink ? drink->isTakeawayAvailable() : false;

        if (addMilk)
        {
            this->drink = new MilkDecorator(this->drink);
            this->drink->setTakeawayAvailable(takeawayAvailable);
        }
        if (addSugar)
        {
            this->drink = new SugarDecorator(this->drink);
            this->drink->setTakeawayAvailable(takeawayAvailable);
        }
    }

    virtual ~DrinkMaker()
    {
        delete drink;
    }

    Drink *getDrink() const
    {
        return drink;
    }

    virtual string getName() const
    {
        return "Default Drink";
    }

    virtual void makeDrink() = 0;
};

#endif