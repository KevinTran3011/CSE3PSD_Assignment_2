// CoffeeTester.cpp
#include <iostream>
#include "Coffee.cpp"
using namespace std;

class CoffeeTester {
public:
    static void runTests() {
        string coffeeType, milkType;
        int sugarAmount;

        cout << "Enter coffee type (black/white): ";
        cin >> coffeeType;

        Coffee* coffee = Coffee::createCoffee(coffeeType);
        cout << coffee->getName() << ": " << coffee->getPrice() << endl;

        cout << "Enter milk type: ";
        cin >> milkType;
        coffee = new MilkDecorator(coffee, milkType);
        cout << coffee->getName() << ": " << coffee->getPrice() << endl;

        cout << "Enter sugar amount: ";
        cin >> sugarAmount;
        coffee = new SugarDecorator(coffee, sugarAmount);
        cout << coffee->getName() << ": " << coffee->getPrice() << endl;

        delete coffee;
    }
};

int main() {
    CoffeeTester::runTests();
    return 0;
}