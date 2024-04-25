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
        if (item->getFoodMaker() && item->getFoodMaker()->getFood()->isTakeawayAvailable())
        {
            items.push_back(item);
        }
        else if (item->getDrinkMaker() && item->getDrinkMaker()->getDrink()->isTakeawayAvailable())
        {
            items.push_back(item);
        }
        else
        {
            cout << "This item is not available for takeaway and will not be added to the order.\n";
            delete item;
        }
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
                std::cout << "   You have ordered: " << item->getFoodMaker()->getFood()->getName()
                          << "  Price: " << item->getFoodMaker()->getFood()->getPrice()
                          << "  Takeaway Available: " << (item->getFoodMaker()->getFood()->isTakeawayAvailable() ? "Yes" : "No")
                          << std::endl;
            }
            else if (item->getDrinkMaker())
            {
                total += item->getDrinkMaker()->getDrink()->getPrice();
                std::cout << "   You have ordered: " << item->getDrinkMaker()->getDrink()->getDescription()
                          << "  Price: " << item->getDrinkMaker()->getDrink()->getPrice()
                          << "  Takeaway Available: " << (item->getDrinkMaker()->getDrink()->isTakeawayAvailable() ? "Yes" : "No")
                          << std::endl;
            }
        }
        return total;
    }
};

#endif;