#include <iostream>
#include <string>
using namespace std;

#include "TeaMaker.h"
#include "CoffeeMaker.h"

int main() {
    // Making a Matcha Tea with milk and sugar
    TeaMaker matchaMaker("matcha", true, true);
    matchaMaker.makeDrink();

    // Making a Chai Tea without milk but with sugar
    TeaMaker chaiMaker("chai", false, true);
    chaiMaker.makeDrink();

    // Making a Black Coffee with milk and sugar
    CoffeeMaker blackCoffeeMaker("black", true, true);
    blackCoffeeMaker.makeDrink();

    // Making a White Coffee without milk but with sugar
    CoffeeMaker whiteCoffeeMaker("white", false, true);
    whiteCoffeeMaker.makeDrink();

    return 0;
}
