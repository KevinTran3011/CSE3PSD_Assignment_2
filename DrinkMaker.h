#ifndef DRINK_MAKER_H
#define DRINK_MAKER_H

#include <iostream>
#include <string>
#include <cctype> 
#include "Coffee.h"
#include "CoffeeMaker.h"
#include "Tea.h" // Assuming you have a Tea class similar to Coffee

using namespace std;

class Drink;

class DrinkFactory {
public:
    static Drink* createDrink(const std::string& type, bool addMilk, bool addSugar) {
        if (type == "coffee") {
            CoffeeMaker* coffeeMaker = new CoffeeMaker("Black", addMilk, addSugar); // Modify parameters as needed
            return coffeeMaker->getCoffee();
        // } else if (type == "tea") {
        //     return new TeaMaker("Green", addMilk); // Modify parameters as needed
        } else {
            return nullptr;
        }
    }
};

class DrinkMaker {
protected:
    Drink *drink;

public:
    DrinkMaker(const std::string& drinkType, bool addMilk, bool addSugar) {
        drink = DrinkFactory::createDrink(drinkType, addMilk, addSugar);
    }

    ~DrinkMaker() {
        delete drink;
    }

        Drink* getDrink() const {
        return drink;
    }

   
};

#endif