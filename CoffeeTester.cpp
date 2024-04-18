// CoffeeTester.cpp
#include <iostream>
#include "Coffee.h"
#include "CoffeeMaker.h"
using namespace std;




class CoffeeTester {
public:
    static void runTests() {
        string coffeeType, milkType;
        int sugarAmount;

        cout << "Enter the coffee type (Black/White): ";
        cin >> coffeeType;

        cout << "Enter milk type: ";
        cin >> milkType; 

        cout << "Enter sugar amount: ";
        cin >> sugarAmount;

        CoffeeMaker coffeeMaker;
        Coffee* coffee = coffeeMaker.createCoffee(coffeeType).addMilk(milkType).addSugar(sugarAmount).build();

        cout << coffee->getName() << ": " << coffee->getPrice() << endl;

        delete coffee;
    }
};

int main() {
    CoffeeTester::runTests();
    return 0;
}