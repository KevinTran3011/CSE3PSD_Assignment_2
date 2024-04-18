#ifndef COFFEE_H
#define COFFEE_H

#include <iostream>
#include <string>

// Base Coffee class
class Coffee
{
public:
    virtual ~Coffee() {}
    virtual std::string getDescription() const = 0;
    virtual double getPrice() const = 0;
};

// Concrete Coffee class for Black Coffee
class BlackCoffee : public Coffee
{
public:
    std::string getDescription() const override
    {
        return "Black Coffee";
    }

    double getPrice() const override
    {
        return 2.0;
    }
};

// Concrete Coffee class for White Coffee
class WhiteCoffee : public Coffee
{
public:
    std::string getDescription() const override
    {
        return "White Coffee";
    }

    double getPrice() const override
    {
        return 2.5;
    }
};

// Coffee Factory
class CoffeeFactory
{
public:
    static Coffee *createCoffee(const std::string &type)
    {
        if (type == "black")
            return new BlackCoffee();
        else if (type == "white")
            return new WhiteCoffee();
        else
            return nullptr;
    }
};

#endif // COFFEE_H
