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

public:
    OrderItem(FoodMaker *foodMaker = nullptr, DrinkMaker *drinkMaker = nullptr)
        : foodMaker(foodMaker), drinkMaker(drinkMaker)
    {
        if (foodMaker == nullptr && drinkMaker == nullptr)
        {
            throw std::invalid_argument("OrderItem must have a FoodMaker or a DrinkMaker");
        }
        if (foodMaker && !foodMaker->getFood()->isTakeawayAvailable())
        {
            cout << "You can't order " << foodMaker->getFood()->getDescription() << " for takeaway.\n";
            this->foodMaker = nullptr; // set foodMaker to nullptr
        }
        if (drinkMaker && !drinkMaker->getDrink()->isTakeawayAvailable())
        {
            cout << "You can't order " << drinkMaker->getDrink()->getDescription() << " for takeaway.\n";
            this->drinkMaker = nullptr; // set drinkMaker to nullptr
        }
    }

    void accept(Visitor *visitor)
    {
        if (foodMaker || drinkMaker) // only accept visitor if foodMaker or drinkMaker is not nullptr
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

#endif