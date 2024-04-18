// CoffeeMaker.h
#ifndef COFFEEMAKER_H
#define COFFEEMAKER_H

#include "Coffee.h"

class CoffeeMaker {
private:
    Coffee* coffee;

public:
    CoffeeMaker();
    ~CoffeeMaker(); // Add destructor
    CoffeeMaker& createCoffee(string type);
    CoffeeMaker& addMilk(string milkType);
    CoffeeMaker& addSugar(int sugarAmount);
    Coffee* build();
};

#endif
