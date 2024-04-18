#ifndef COFFEE_TESTER_H
#define COFFEE_TESTER_H

#include "CoffeeMaker.h"
#include <iostream>

class CoffeeTester
{
public:
    static void test()
    {
        BlackCoffeeMaker blackCoffeeMaker;
        blackCoffeeMaker.makeCoffee();
        Coffee *blackCoffee = blackCoffeeMaker.getCoffee();
        std::cout << blackCoffee->getDescription() << " - $" << blackCoffee->getPrice() << "\n";

        // WhiteCoffeeMaker whiteCoffeeMaker;
        // whiteCoffeeMaker.makeCoffee();
        // Coffee *whiteCoffee = whiteCoffeeMaker.getCoffee();
        // std::cout << whiteCoffee->getDescription() << " - $" << whiteCoffee->getPrice() << "\n";

        MilkDecorator milkedBlackCoffee(blackCoffee);
        std::cout << milkedBlackCoffee.getDescription() << " - $" << milkedBlackCoffee.getPrice() << "\n";

        // SugarDecorator sugaredWhiteCoffee(whiteCoffee);
        // std::cout << sugaredWhiteCoffee.getDescription() << " - $" << sugaredWhiteCoffee.getPrice() << "\n";
    }
};

#endif // COFFEE_TESTER_H