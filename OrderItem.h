#ifndef ORDERITEM_H
#define ORDERITEM_H

#include "FoodMaker.h"
#include "DrinkMaker.h"
#include "Visitor.h"

class OrderItem
{
private:
    FoodMaker *foodMaker;
    DrinkMaker *drinkMaker;
    bool isTakeawayAvailable;

public:
    OrderItem(FoodMaker *foodMaker = nullptr, DrinkMaker *drinkMaker = nullptr)
        : foodMaker(foodMaker), drinkMaker(drinkMaker), isTakeawayAvailable(true)
    {
        if (foodMaker == nullptr && drinkMaker == nullptr)
        {
            throw std::invalid_argument("OrderItem must have a FoodMaker or a DrinkMaker");
        }
        if (foodMaker && foodMaker->getFood() && !foodMaker->getFood()->isTakeawayAvailable())
        {
            cout << "You can't order " << foodMaker->getFood()->getName() << " for takeaway.\n";
            isTakeawayAvailable = false;
        }
        if (drinkMaker && drinkMaker->getDrink() && !drinkMaker->getDrink()->isTakeawayAvailable())
        {
            cout << "You can't order " << drinkMaker->getDrink()->getDescription() << " for takeaway.\n";
            isTakeawayAvailable = false;
        }
    }

    void accept(Visitor *visitor)
    {
        if (isTakeawayAvailable && (foodMaker || drinkMaker)) // only accept visitor if foodMaker or drinkMaker is not nullptr and the item is available for takeaway
        {
            visitor->visit(this);
        }
    }

    FoodMaker *getFoodMaker() const
    {
        return foodMaker;
    }

    DrinkMaker *getDrinkMaker() const
    {
        return drinkMaker;
    }
};

#endif // ORDERITEM_H