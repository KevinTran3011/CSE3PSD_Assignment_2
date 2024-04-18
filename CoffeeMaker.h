#ifndef COFFEE_MAKER_H
#define COFFEE_MAKER_H

#include "Coffee.h"
using namespace std;

// Abstract builder class
class CoffeeMaker
{
protected:
    Coffee *coffee;

public:
    CoffeeMaker() : coffee(nullptr) {}
    virtual ~CoffeeMaker()
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

    virtual void makeCoffee() = 0;
};

// Concrete builder class for Black Coffee
class BlackCoffeeMaker : public CoffeeMaker
{
public:
    BlackCoffeeMaker() : CoffeeMaker() { coffee = new BlackCoffee(); }

    void makeCoffee() override
    {
        boilWater();
        grindBeans();
        applyFilter();
        placeCoffeeInFilter();
        pourAndWait();
        coffee->setDescription("Black Coffee");
        coffee->setPrice(2.0);
    }
};

// Concrete builder class for White Coffee
class WhiteCoffeeMaker : public CoffeeMaker
{
public:
    WhiteCoffeeMaker() : CoffeeMaker() { coffee = new WhiteCoffee(); }

    void makeCoffee() override
    {
        boilWater();
        grindBeans();
        applyFilter();
        placeCoffeeInFilter();
        pourAndWait();
        coffee->setDescription("White Coffee");
        coffee->setPrice(2.5);
    }
};

// Concrete decorator class for adding milk
class MilkDecorator : public Coffee
{
protected:
    Coffee *coffee;

public:
    MilkDecorator(Coffee *c) : coffee(c) {}

    // Destructor does not delete coffee object
    ~MilkDecorator() {}

    string getDescription() const override
    {
        cout << "Adding milk\n"
             << endl;
        return coffee->getDescription() + ", with Milk";
    }

    double getPrice() const override
    {
        return coffee->getPrice() + 0.5; // Price increase for milk
    }
};

// Concrete decorator class for adding sugar
class SugarDecorator : public Coffee
{
protected:
    Coffee *coffee;

public:
    SugarDecorator(Coffee *c) : coffee(c) {}

    // Destructor does not delete coffee object
    ~SugarDecorator() {}

    string getDescription() const override
    {
        cout << "Adding sugar\n"
             << endl;
        return coffee->getDescription() + ", with Sugar";
    }

    double getPrice() const override
    {
        return coffee->getPrice() + 0.3; // Price increase for sugar
    }
};

#endif // COFFEE_MAKER_H