#include <iostream>
#include "Manager.h"
#include "FoodMaker.h"
#include "CoffeeMaker.h"
#include "TeaMaker.h"

class ManagerTester
{
public:
    void runTests()
    {
        Manager manager;
        Order order;

        // 1 food that is valid for take Away
        FoodMaker *sandwichMaker = new SandwichMaker();
        OrderItem *sandwichItem = manager.createOrderItem(sandwichMaker, nullptr);
        manager.addItemToOrder(order, sandwichItem);

        // 1 food that is not
        FoodMaker *tiramisuMaker = new TiramisuMaker();
        OrderItem *tiramisuItem = manager.createOrderItem(tiramisuMaker, nullptr);
        manager.addItemToOrder(order, tiramisuItem);

        // 1 black coffee with milk no sugar
        CoffeeMaker *blackCoffeeMaker = new BlackCoffeeMaker(true, true);
        OrderItem *coffeeItem = manager.createOrderItem(nullptr, blackCoffeeMaker);
        manager.addItemToOrder(order, coffeeItem);

        // 1 matcha with no milk no sugar
        TeaMaker *matchaTeaMaker = new MatchaTeaMaker(true, false);
        OrderItem *teaItem = manager.createOrderItem(nullptr, matchaTeaMaker);
        manager.addItemToOrder(order, teaItem);

        // Calculate total price
        double totalPrice = manager.calculateTotal(order);
        std::cout << "Total price: " << totalPrice << std::endl;

        // Clean up
        delete sandwichMaker;
        delete tiramisuMaker;
        delete blackCoffeeMaker;
        delete matchaTeaMaker;
    }
};

int main()
{
    ManagerTester tester;
    tester.runTests();
    return 0;
}