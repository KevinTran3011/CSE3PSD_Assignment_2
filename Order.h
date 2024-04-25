#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>
#include "OrderItem.h"
#include "TakeawayChargeVisitor.h"
#include "FoodMaker.h"
#include "DrinkMaker.h"

class Order
{
private:
    std::vector<OrderItem *> items;

public:
    void addItem(OrderItem *item)
    {
        items.push_back(item);
    }

    void applyTakeawayCharge()
    {
        TakeawayChargeVisitor visitor;
        for (auto item : items)
        {
            item->accept(&visitor);
        }
    }

    double getTotalPrice() const
    {
        double total = 0.0;
        for (auto item : items)
        {
            if (item->getFoodMaker())
            {
                total += item->getFoodMaker()->getFood()->getPrice();
            }
            else if (item->getDrinkMaker())
            {
                total += item->getDrinkMaker()->getDrink()->getPrice();
            }
        }
        return total;
    }
};

#endif