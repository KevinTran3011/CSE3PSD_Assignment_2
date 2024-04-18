#ifndef COFFEE_MAKER_H
#define COFFEE_MAKER_H

#include "Coffee.h"

// Abstract decorator class
class CoffeeDecorator : public Coffee
{
protected:
    Coffee *coffee;

public:
    CoffeeDecorator(Coffee *c) : coffee(c) {}
    virtual ~CoffeeDecorator()
    {
        delete coffee;
    }
};

// Concrete decorator class for adding milk
class MilkDecorator : public CoffeeDecorator
{
public:
    MilkDecorator(Coffee *c) : CoffeeDecorator(c) {}

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
class SugarDecorator : public CoffeeDecorator
{
public:
    SugarDecorator(Coffee *c) : CoffeeDecorator(c) {}

    std::string getDescription() const override
    {
        return coffee->getDescription() + ", with Sugar";
    }

    double getPrice() const override
    {
        return coffee->getPrice() + 0.3; // Price increase for sugar
    }
};

#endif // COFFEE_MAKER_H
