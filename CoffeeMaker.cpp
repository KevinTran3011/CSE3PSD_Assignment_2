#include "CoffeeMaker.h"

CoffeeMaker& CoffeeMaker::createCoffee(string type) {
    this->coffee = Coffee::createCoffee(type);
    return *this;
}

CoffeeMaker& CoffeeMaker::addMilk(string milkType) {
    this->coffee = new MilkDecorator(this->coffee, milkType);
    return *this;
}

CoffeeMaker& CoffeeMaker::addSugar(int sugarAmount) {
    this->coffee = new SugarDecorator(this->coffee, sugarAmount);
    return *this;
}

Coffee* CoffeeMaker::build() {
    Coffee* finalCoffee = this->coffee;
    this->coffee = nullptr; // Reset the builder
    return finalCoffee;
}