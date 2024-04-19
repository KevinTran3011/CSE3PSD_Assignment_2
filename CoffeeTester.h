#ifndef COFFEE_TESTER_H
#define COFFEE_TESTER_H

#include "CoffeeMaker.h"
#include <iostream>

class CoffeeTester
{
public:
    static void test()
    {
        // Test Black Coffee without milk and sugar
        BlackCoffeeMaker blackCoffeeMaker(false, false);
        blackCoffeeMaker.makeCoffee();
        Coffee *blackCoffee = blackCoffeeMaker.getCoffee();
        std::cout << blackCoffee->getDescription() << " - $" << blackCoffee->getPrice() << "\n";

        // Test Black Coffee with milk
        BlackCoffeeMaker milkedBlackCoffeeMaker(true, false);
        milkedBlackCoffeeMaker.makeCoffee();
        Coffee *milkedBlackCoffee = milkedBlackCoffeeMaker.getCoffee();
        std::cout << milkedBlackCoffee->getDescription() << " - $" << milkedBlackCoffee->getPrice() << "\n";

        // Test Black Coffee with sugar
        BlackCoffeeMaker sugaredBlackCoffeeMaker(false, true);
        sugaredBlackCoffeeMaker.makeCoffee();
        Coffee *sugaredBlackCoffee = sugaredBlackCoffeeMaker.getCoffee();
        std::cout << sugaredBlackCoffee->getDescription() << " - $" << sugaredBlackCoffee->getPrice() << "\n";

        // Test Black Coffee with milk and sugar
        BlackCoffeeMaker milkedSugaredBlackCoffeeMaker(true, true);
        milkedSugaredBlackCoffeeMaker.makeCoffee();
        Coffee *milkedSugaredBlackCoffee = milkedSugaredBlackCoffeeMaker.getCoffee();
        std::cout << milkedSugaredBlackCoffee->getDescription() << " - $" << milkedSugaredBlackCoffee->getPrice() << "\n";

        // Similarly, you can test White Coffee in the same way if needed.
    }
};

#endif // COFFEE_TESTER_H
