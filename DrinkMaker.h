#ifndef DRINK_MAKER_H
#define DRINK_MAKER_H

#include "Drinks.h"
#include "Tea.h"
#include "Coffee.h"
#include "Visitor.h"
#include <iostream>
#include <string>
using namespace std;

class Drink;
class Order;
class Visitor;

class MilkDecorator : public Drink
{
private:
    Drink *drink;

public:
    MilkDecorator(Drink *drink) : drink(drink) {}

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
    SugarDecorator(Drink *drink) : drink(drink) {}

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
    DrinkMaker(Drink *drink, bool addMilk, bool addSugar) : drink(drink)
    {
        if (addMilk)
        {
            this->drink = new MilkDecorator(this->drink);
        }
        if (addSugar)
        {
            this->drink = new SugarDecorator(this->drink);
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

    virtual void makeDrink() = 0;

    virtual void accept(Visitor *visitor)
    {
        visitor->visit(this);
    }
};

#include "Visitor.h"

#endif