#ifndef COFFEEMAKER_H
#define COFFEEMAKER_H

#include "Coffee.h"

class CoffeeMaker {
private:
    Coffee* coffee;

public:
    CoffeeMaker& createCoffee(string type);
    CoffeeMaker& addMilk(string milkType);
    CoffeeMaker& addSugar(int sugarAmount);
    Coffee* build();
};

#endif