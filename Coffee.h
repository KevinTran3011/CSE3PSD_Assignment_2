#ifndef COFFEE_H
#define COFFEE_H

#include <iostream>
#include <string>
using namespace std;
// Base Coffee class
class Coffee
{
protected:
    string description;
    double price;

public:
    virtual ~Coffee() {}
    virtual string getDescription() const { return description; }
    virtual double getPrice() const { return price; }
    virtual void setDescription(const string &desc) { description = desc; }
    virtual void setPrice(double p) { price = p; }
};

// Concrete Coffee class for Black Coffee
class BlackCoffee : public Coffee
{
public:
    BlackCoffee()
    {
        setDescription("Black Coffee");
        setPrice(2.0);
    }
};

// Concrete Coffee class for White Coffee
class WhiteCoffee : public Coffee
{
public:
    WhiteCoffee()
    {
        setDescription("White Coffee");
        setPrice(2.5);
    }
};

// Coffee Factory
class CoffeeFactory
{
public:
    static Coffee *createCoffee(const string &type)
    {
        if (type == "black")
            return new BlackCoffee();
        else if (type == "white")
            return new WhiteCoffee();
        else
            return nullptr;
    }
};

#endif //