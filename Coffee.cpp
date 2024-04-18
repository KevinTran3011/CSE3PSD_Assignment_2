// Coffee.cpp
#include "Coffee.h"

Coffee::Coffee(string name, double price, string size) : name(name), price(price), size(size) {}

Coffee::~Coffee() {} // Define destructor

string Coffee::getName() {
    return name;
}

void Coffee::setPrice(double price) {
    this->price = price;
}

double Coffee::getPrice() {
    return price;
}

string Coffee::getSize() {
    return size;
}

Coffee* Coffee::createCoffee(string type) {
    if (type == "black") {
        return new Coffee("Black Coffee", 2.0, "Medium");
    } else if (type == "white") {
        return new Coffee("White Coffee", 2.5, "Medium");
    } else {
        return nullptr;
    }
}

MilkDecorator::MilkDecorator(Coffee* coffee, string milkType) 
    : Coffee(coffee->getName(), coffee->getPrice(), coffee->getSize()), milkType(milkType) {
    this->name += " with " + milkType + " milk";
}

SugarDecorator::SugarDecorator(Coffee* coffee, int sugarAmount) 
    : Coffee(coffee->getName(), coffee->getPrice(), coffee->getSize()), sugarAmount(sugarAmount) {
    this->name += " with " + to_string(sugarAmount) + " sugar";
    this->price += 0.1 * sugarAmount; // Assuming each sugar costs 0.1
}
