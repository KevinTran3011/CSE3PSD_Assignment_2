#ifndef TAKEAWAYCHARGEVISITOR_H
#define TAKEAWAYCHARGEVISITOR_H

#include "Visitor.h"
#include "OrderItem.h"

class TakeawayChargeVisitor : public Visitor
{
public:
    void visit(OrderItem *item)
    {
        if (item)
        {
            if (item->getFoodMaker() && item->getFoodMaker()->getFood())
            {
                Food *food = item->getFoodMaker()->getFood();
                if (food->isTakeawayAvailable())
                {
                    food->setPrice(food->getPrice() * 1.1);
                }
                else
                {
                    cout << "You can't order " << food->getName() << " for takeaway.\n";
                    return;
                }
            }
            else if (item->getDrinkMaker() && item->getDrinkMaker()->getDrink())
            {
                Drink *drink = item->getDrinkMaker()->getDrink();
                if (drink->isTakeawayAvailable())
                {
                    drink->setPrice(drink->getPrice() * 1.1);
                }
                else
                {
                    cout << "You can't order " << drink->getDescription() << " for takeaway.\n";
                    return;
                }
            }
            else
            {
                cout << "Invalid OrderItem.\n";
            }
        }
        else
        {
            cout << "Invalid OrderItem.\n";
        }
    }
};

#endif