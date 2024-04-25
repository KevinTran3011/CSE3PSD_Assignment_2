#ifndef TAKEAWAYCHARGEVISITOR_H
#define TAKEAWAYCHARGEVISITOR_H

#include "Visitor.h"
#include "OrderItem.h"

class TakeawayChargeVisitor : public Visitor
{
public:
    void visit(OrderItem *item)
    {
        if (item->getFoodMaker())
        {
            if (item->getFoodMaker()->getFood()->isTakeawayAvailable())
            {
                item->getFoodMaker()->getFood()->setPrice(item->getFoodMaker()->getFood()->getPrice() * 1.1);
            }
            else
            {
                cout << "You can't order " << item->getFoodMaker()->getFood()->getName() << " for takeaway.\n";
            }
        }
        else if (item->getDrinkMaker())
        {
            if (item->getDrinkMaker()->getDrink()->isTakeawayAvailable())
            {
                item->getDrinkMaker()->getDrink()->setPrice(item->getDrinkMaker()->getDrink()->getPrice() * 1.1);
            }
            else
            {
                cout << "You can't order " << item->getDrinkMaker()->getDrink()->getDescription() << " for takeaway.\n";
            }
        }
    }
};

#endif