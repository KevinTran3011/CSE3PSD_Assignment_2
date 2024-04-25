
#include <iostream>
#include "OrderTester.h"
#include "FoodMaker.h"
#include "CoffeeMaker.h"
#include "TeaMaker.h"
#include "OrderItem.h"

void OrderTester::runTests()
{
    Order order;

    // 1 food that is valid for take Away
    FoodMaker *sandwichMaker = new SandwichMaker();
    OrderItem *sandwichItem = new OrderItem(sandwichMaker);
    order.addItem(sandwichItem);

    // 1 food that is not
    FoodMaker *tiramisuMaker = new TiramisuMaker();
    OrderItem *tiramisuItem = new OrderItem(tiramisuMaker);
    order.addItem(tiramisuItem);

    // 1 black coffee with milk no sugar
    CoffeeMaker *blackCoffeeMaker = new BlackCoffeeMaker(true, false);
    OrderItem *coffeeItem = new OrderItem(blackCoffeeMaker);
    order.addItem(coffeeItem);

    // // 1 matcha with no milk no sugar
    TeaMaker *matchaTeaMaker = new MatchaTeaMaker(true, false);
    OrderItem *teaItem = new OrderItem(matchaTeaMaker);
    order.addItem(teaItem);

    // Apply takeaway charge
    order.applyTakeawayCharge();

    // Print total price
    cout << "Total price: " << order.getTotalPrice() << endl;

    // Clean up
    delete sandwichMaker;
    delete tiramisuMaker;
    delete blackCoffeeMaker;
    delete matchaTeaMaker;
}

int main()
{
    OrderTester tester;
    tester.runTests();
    return 0;
}