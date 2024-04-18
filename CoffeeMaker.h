#ifndef COFFEE_MAKER_H
#define COFFEE_MAKER_H

#include "Coffee.h"

// Abstract builder class
class CoffeeMaker
{
protected:
    Coffee *coffee;

public:
    CoffeeMaker() : coffee(new Coffee()) {}
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
        std::cout << "Boiling water.\n";
    }

    virtual void grindBeans() const
    {
        std::cout << "Grinding coffee beans.\n";
    }

    virtual void applyFilter() const
    {
        std::cout << "Applying filter.\n";
    }

    virtual void placeCoffeeInFilter() const
    {
        std::cout << "Placing coffee in filter.\n";
    }

    virtual void pourAndWait() const
    {
        std::cout << "Pouring water and waiting.\n";
    }

    virtual void makeCoffee() = 0;
};

// Concrete builder class for Black Coffee
class BlackCoffeeMaker : public CoffeeMaker
{
public:
    BlackCoffeeMaker() : CoffeeMaker() {}

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
    WhiteCoffeeMaker() : CoffeeMaker() {}

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

    ~MilkDecorator()
    {
        delete coffee;
    }

    std::string getDescription() const override
    {
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

    ~SugarDecorator()
    {
        delete coffee;
    }

    std::string getDescription() const override
    {
        return coffee->getDescription() + ", with Sugar";
    }

    double getPrice() const override
    {
        return coffee->getPrice() + 0.3; // Price increase for sugar
    }
};

#endif // COFFEE_MAKER_Hs