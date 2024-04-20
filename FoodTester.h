#ifndef FOOD_TESTER_H
#define FOOD_TESTER_H

#include "FoodMaker.h"
#include <iostream>
using namespace std;


class FoodTester{
    public:
    static void foodTest(){
        SandWichMaker sandWichMaker;
        sandWichMaker.makeFood();
        Food *sandwich = sandWichMaker.getFood();
        cout << sandwich->getDescription() << " - $" << sandwich->getPrice() << "\n";

        TiramisuMaker tiramisuMaker;
        tiramisuMaker.makeFood();
        Food *tiramisu = tiramisuMaker.getFood();
        cout << tiramisu->getDescription() << " - $" << tiramisu->getPrice() << "\n";
    }


};


#endif //FOOD_TESTER_H