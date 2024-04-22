#include <iostream>
#include <string>
using namespace std;

#include "TeaMaker.h"
#include "CoffeeMaker.h"

int main() {
    string drinkType;
    string teaType;
    string coffeeType;
    string addMilkInput;
    string addSugarInput;
    bool addMilk;
    bool addSugar;

    cout << "Enter drink type (tea or coffee): ";
    cin >> drinkType;

    if (drinkType == "tea") {
        cout << "What type of tea (chai or matcha): ";
        cin >> teaType;
    } else if (drinkType == "coffee") {
        cout << "What type of coffee (black or white): ";
        cin >> coffeeType;
    } else {
        cout << "Invalid drink type. Please enter 'tea' or 'coffee'.\n";
        return 1;
    }

    cout << "Add milk? (Y/N): ";
    cin >> addMilkInput;
    addMilk = (addMilkInput == "Y" || addMilkInput == "y");

    cout << "Add sugar? (Y/N): ";
    cin >> addSugarInput;
    addSugar = (addSugarInput == "Y" || addSugarInput == "y");

    if (drinkType == "tea") {
        TeaMaker teaMaker(teaType, addMilk, addSugar);
        teaMaker.makeDrink();
    } else {
        CoffeeMaker coffeeMaker(coffeeType, addMilk, addSugar);
        coffeeMaker.makeDrink();
    }

    return 0;
}