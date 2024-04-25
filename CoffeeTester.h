#ifndef COFFEE_TESTER_H
#define COFFEE_TESTER_H

#include "CoffeeMaker.h"
#include <iostream>
using namespace std;

class CoffeeTester
{
public:
    static void test()
    {

        // Create a Coffee object using the CoffeeFactory
        Coffee *coffee = CoffeeFactory::createCoffee("white");
        if (coffee != nullptr)
        {
            // Call isTakeawayAvailable() and print the result
            cout << "Is takeaway available for white coffee? " << (coffee->isTakeawayAvailable() ? "Yes" : "No") << endl;
            delete coffee;
        }

        coffee = CoffeeFactory::createCoffee("black");
        if (coffee != nullptr)
        {
            cout << "Is takeaway available for black coffee? " << (coffee->isTakeawayAvailable() ? "Yes" : "No") << endl;
            delete coffee;
        }
    }
};

#endif
