#include "Visitor.h"
#include "DrinkMaker.h"
#include "FoodMaker.h"

void TakeawayChargeVisitor::visit(DrinkMaker *drink)
{
    if (!drink->getDrink()->isTakeawayAvailable())
    {
        drink->getDrink()->setPrice(drink->getDrink()->getPrice() * 1.1);
    }
}

void TakeawayChargeVisitor::visit(FoodMaker *food)
{
    if (!food->getFood()->isTakeawayAvailable())
    {
        food->getFood()->setPrice(food->getFood()->getPrice() * 1.1);
    }
}