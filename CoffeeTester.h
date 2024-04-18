#ifndef COFFEE_TESTER_H
#define COFFEE_TESTER_H

#include <iostream>
#include "Coffee.h"
#include "CoffeeMaker.h"

// Tester class
class CoffeeTester
{
public:
    static void test()
    {
        // Test Black Coffee
        Coffee *myCoffee = CoffeeFactory::createCoffee("black");
        std::cout << "Description: " << myCoffee->getDescription() << std::endl;
        std::cout << "Price: $" << myCoffee->getPrice() << std::endl;
        delete myCoffee;

        // Test White Coffee with Milk
        Coffee *whiteCoffee = CoffeeFactory::createCoffee("white");
        whiteCoffee = new MilkDecorator(whiteCoffee);
        std::cout << "Description: " << whiteCoffee->getDescription() << std::endl;
        std::cout << "Price: $" << whiteCoffee->getPrice() << std::endl;
        delete whiteCoffee;

        // Test White Coffee with Sugar
        Coffee *whiteCoffeeSugar = CoffeeFactory::createCoffee("white");
        whiteCoffeeSugar = new SugarDecorator(whiteCoffeeSugar);
        std::cout << "Description: " << whiteCoffeeSugar->getDescription() << std::endl;
        std::cout << "Price: $" << whiteCoffeeSugar->getPrice() << std::endl;
        delete whiteCoffeeSugar;
    }
};

#endif // COFFEE_TESTER_H
