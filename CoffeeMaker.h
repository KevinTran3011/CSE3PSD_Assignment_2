#ifndef COFFEE_MAKER_H
#define COFFEE_MAKER_H

#include "Coffee.h"
#include <iostream>
#include <string>
using namespace std;


class Coffee;


class MilkDecorator : public Coffee
{
protected:
    Coffee *coffee;

public:
    MilkDecorator(Coffee *c) : coffee(c) {}

    ~MilkDecorator() {}

    string getDescription() const override
    {
        cout << "Adding milk\n" << endl;
        return coffee->getDescription() + ", with Milk";
    }

    double getPrice() const override
    {
        return coffee->getPrice() + 0.5; 
    }
};


class SugarDecorator : public Coffee
{
protected:
    Coffee *coffee;

public:
    SugarDecorator(Coffee *c) : coffee(c) {}

    ~SugarDecorator() {}

    string getDescription() const override
    {
        cout << "Adding sugar\n" << endl;
        return coffee->getDescription() + ", with Sugar";
    }

    double getPrice() const override
    {
        return coffee->getPrice() + 0.3;
    }
};


class CoffeeMaker
{
protected:
    Coffee *coffee;

public:
    CoffeeMaker(string coffeeType, bool addMilk, bool addSugar) : coffee(nullptr)
    {
        if (coffeeType == "Black") {
            coffee = new BlackCoffee();
        } else if (coffeeType == "White") {
            coffee = new WhiteCoffee();
        }
        
        if (addMilk) {
            coffee = new MilkDecorator(coffee);
        }
        if (addSugar) {
            coffee = new SugarDecorator(coffee);
        }
    }

    ~CoffeeMaker()
    {
        delete coffee;
    }

    Coffee *getCoffee() const
    {
        return coffee;
    }

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

    virtual void placeCoffeeInFilter() const
    {
        cout << "Placing coffee in filter.\n";
    }

    virtual void pourAndWait() const
    {
        cout << "Pouring water and waiting.\n";
    }

    void makeCoffee()
    {
        boilWater();
        grindBeans();
        applyFilter();
        placeCoffeeInFilter();
        pourAndWait();
        cout << "Final Description: " << coffee->getDescription() << endl;
        cout << "Final Price: " << coffee->getPrice() << endl;
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