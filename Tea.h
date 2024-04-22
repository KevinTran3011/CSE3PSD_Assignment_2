// #ifndef TEA_H
// #define TEA_H

// #include <iostream>
// #include <string>
// #include "Drinks.h"
// using namespace std;

// class Tea: public Drink
// {

// protected:
//     string description;
//     double price;

// public:
//     virtual ~Tea() {}
//     virtual string getDescription() const { return description; }
//     virtual double getPrice() const { return price; }
//     virtual void setDescription(const string &desc) { description = desc; }
//     virtual void setPrice(double p) { price = p; }
// };

// // Concrete Tea class for Black Tea
// class BlackTea : public Tea
// {
// public:
//     BlackTea()
//     {
//         setDescription("Black Tea");
//         setPrice(2.0);
//     }
// };

// // Concrete Tea class for White Tea
// class WhiteTea : public Tea
// {
// public:
//     WhiteTea()
//     {
//         setDescription("White Tea");
//         setPrice(2.5);
//     }
// };

// class TeaFactory
// {
// public:
//     static Tea *createTea(const string &type)
//     {
//         if (type == "black")
//             return new BlackTea();
//         else if (type == "white")
//             return new WhiteTea();
//         else
//             return nullptr;
//     }
// };

// #endif


#ifndef TEA_H
#define TEA_H

#include "Drinks.h"
using namespace std;

class Tea: public Drink
{
public:
    virtual ~Tea() {}
};

class MatchaTea : public Tea
{
public:
    MatchaTea()
    {
        setDescription("Matcha Tea");
        setPrice(3.0);
    }
};

class Chai : public Tea
{
public:
    Chai()
    {
        setDescription("Chai Tea");
        setPrice(2.5);
    }
};

class TeaFactory
{
public:
    static Tea *createTea(const string &type)
    {
        if (type == "matcha")
            return new MatchaTea();
        else if (type == "chai")
            return new Chai();
        else
            return nullptr;
    }
};

#endif