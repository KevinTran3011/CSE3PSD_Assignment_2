// #ifndef COFFEE_H
// #define COFFEE_H

// #include <iostream>
// #include <string>
// #include "Drinks.h"
// using namespace std;



// class Coffee: public Drink
// {
// protected:
//     string description;
//     double price;

// public:
//     virtual ~Coffee() {}
//     virtual string getDescription() const { return description; }
//     virtual double getPrice() const { return price; }
//     virtual void setDescription(const string &desc) { description = desc; }
//     virtual void setPrice(double p) { price = p; }
// };

// // Concrete Coffee class for Black Coffee
// class BlackCoffee : public Coffee
// {
// public:
//     BlackCoffee()
//     {
//         setDescription("Black Coffee");
//         setPrice(2.0);
//     }
// };

// // Concrete Coffee class for White Coffee
// class WhiteCoffee : public Coffee
// {
// public:
//     WhiteCoffee()
//     {
//         setDescription("White Coffee");
//         setPrice(2.5);
//     }
// };

// // Coffee Factory
// class CoffeeFactory
// {
// public:
//     static Coffee *createCoffee(const string &type)
//     {
//         if (type == "black")
//             return new BlackCoffee();
//         else if (type == "white")
//             return new WhiteCoffee();
//         else
//             return nullptr;
//     }
// };

// #endif //




#ifndef COFFEE_H
#define COFFEE_H

#include "Drinks.h"
using namespace std;

class Coffee: public Drink
{
public:
    virtual ~Coffee() {}
};

class BlackCoffee : public Coffee
{
public:
    BlackCoffee()
    {
        setDescription("Black Coffee");
        setPrice(2.0);
    }
};

class WhiteCoffee : public Coffee
{
public:
    WhiteCoffee()
    {
        setDescription("White Coffee");
        setPrice(2.5);
    }
};

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

#endif