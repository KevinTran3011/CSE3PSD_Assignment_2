// CoffeeMaker.cpp
#include "CoffeeMaker.h"

CoffeeMaker::CoffeeMaker() : coffee(nullptr) {}

CoffeeMaker::~CoffeeMaker() {
    delete coffee; // Properly release memory
}

CoffeeMaker& CoffeeMaker::createCoffee(string type) {
    Coffee* newCoffee = Coffee::createCoffee(type);
    if (newCoffee) {
        coffee = newCoffee;
    }
    return *this;
}

CoffeeMaker& CoffeeMaker::addMilk(string milkType) {
    if (coffee) {
        coffee = new MilkDecorator(coffee, milkType);
    }
    return *this;
}

CoffeeMaker& CoffeeMaker::addSugar(int sugarAmount) {
    if (coffee) {
        coffee = new SugarDecorator(coffee, sugarAmount);
    }
    return *this;
}

Coffee* CoffeeMaker::build() {
    Coffee* finalCoffee = coffee;
    coffee = nullptr; // Reset the builder
    return finalCoffee;
}
