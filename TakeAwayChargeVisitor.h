#ifndef TAKEAWAYCHARGEVISITOR_H
#define TAKEAWAYCHARGEVISITOR_H

#include "Visitor.h"
#include "OrderItem.h"

class TakeawayChargeVisitor : public Visitor
{
public:
    void visit(OrderItem *item)
    {
        if (item && item->getFoodMaker())
        {
            Food *food = item->getFoodMaker()->getFood();
            if (food)
            {
                if (food->isTakeawayAvailable())
                {
                    food->setPrice(food->getPrice() * 1.1);
                }
                else
                {
                    cout << "You can't order " << food->getName() << " for takeaway.\n";
                }
            }
            else
            {
                cout << "Food is not available.\n";
            }
        }
        else if (item && item->getDrinkMaker())
        {
            Drink *drink = item->getDrinkMaker()->getDrink();
            if (drink)
            {
                if (drink->isTakeawayAvailable())
                {
                    drink->setPrice(drink->getPrice() * 1.1);
                }
                else
                {
                    cout << "You can't order " << drink->getDescription() << " for takeaway.\n";
                }
            }
            else
            {
                cout << "Drink is not available.\n";
            }
        }
    }
};

#endif