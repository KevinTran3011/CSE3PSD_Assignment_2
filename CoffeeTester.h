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
        
        BlackCoffeeMaker blackCoffeeMaker(false, false);
        blackCoffeeMaker.makeCoffee();
        Coffee *blackCoffee = blackCoffeeMaker.getCoffee();
        cout << blackCoffee->getDescription() << " - $" << blackCoffee->getPrice() << "\n";

        
        BlackCoffeeMaker milkedBlackCoffeeMaker(true, false);
        milkedBlackCoffeeMaker.makeCoffee();
        Coffee *milkedBlackCoffee = milkedBlackCoffeeMaker.getCoffee();
        cout << milkedBlackCoffee->getDescription() << " - $" << milkedBlackCoffee->getPrice() << "\n";

        
        BlackCoffeeMaker sugaredBlackCoffeeMaker(false, true);
        sugaredBlackCoffeeMaker.makeCoffee();
        Coffee *sugaredBlackCoffee = sugaredBlackCoffeeMaker.getCoffee();
        cout << sugaredBlackCoffee->getDescription() << " - $" << sugaredBlackCoffee->getPrice() << "\n";

       
        BlackCoffeeMaker milkedSugaredBlackCoffeeMaker(true, true);
        milkedSugaredBlackCoffeeMaker.makeCoffee();
        Coffee *milkedSugaredBlackCoffee = milkedSugaredBlackCoffeeMaker.getCoffee();
        cout << milkedSugaredBlackCoffee->getDescription() << " - $" << milkedSugaredBlackCoffee->getPrice() << "\n";

        
    }
};

#endif 
