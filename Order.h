#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "DrinkMaker.h"
#include "FoodMaker.h"
#include "Visitor.h"
using namespace std;

class Order
{
private:
    vector<DrinkMaker *> drinks;
    vector<FoodMaker *> foods;
    double totalPrice = 0.0;

public:
    void addDrink(DrinkMaker *drink)
    {
        drinks.push_back(drink);
    }

    void addFood(FoodMaker *food)
    {
        foods.push_back(food);
    }

    void applyTakeawayCharge()
    {
        TakeawayChargeVisitor visitor;
        for (auto drink : drinks)
        {
            drink->accept(&visitor);
        }
        for (auto food : foods)
        {
            food->accept(&visitor);
        }
    }

    double getTotalPrice() const
    {
        double total = 0.0;
        for (auto drink : drinks)
        {
            total += drink->getDrink()->getPrice();
        }
        for (auto food : foods)
        {
            total += food->getFood()->getPrice();
        }
        return total;
    }
};

#endif