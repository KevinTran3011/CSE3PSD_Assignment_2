#ifndef ORDER_TESTER_H
#define ORDER_TESTER_H

#include "Order.h"
#include "TeaMaker.h"
#include "CoffeeMaker.h"
#include "FoodMaker.h"
class OrderTester
{
public:
    static void testOrder()
    {
        // Create an order
        Order order;

        // Make some drinks
        TeaMaker matchaMaker("matcha", true, true);
        TeaMaker chaiMaker("chai", false, true);
        CoffeeMaker blackCoffeeMaker("black", true, true);
        CoffeeMaker whiteCoffeeMaker("white", false, true);

        // Make some food
        SandwichMaker sandwichMaker;
        TiramisuMaker tiramisuMaker;

        // Add drinks to the order
        order.addDrink(&matchaMaker);
        order.addDrink(&chaiMaker);
        order.addDrink(&blackCoffeeMaker);
        order.addDrink(&whiteCoffeeMaker);

        // Add food to the order
        order.addFood(&sandwichMaker);
        order.addFood(&tiramisuMaker);

        // Apply takeaway charge
        // order.applyTakeawayCharge();

        // Display total price
        cout << "Total price: $" << order.getTotalPrice() << endl;
    }
};

#endif
