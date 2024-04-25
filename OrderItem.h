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
    OrderItem(FoodMaker *foodMaker) : foodMaker(foodMaker), drinkMaker(nullptr)
    {
        if (foodMaker == nullptr)
        {
            throw std::invalid_argument("OrderItem must have a FoodMaker");
        }
        if (!foodMaker->getFood()->isTakeawayAvailable())
        {
            cout << "You can't order " << foodMaker->getFood()->getDescription() << " for takeaway.\n";
            foodMaker = nullptr; // set foodMaker to nullptr
        }
    }
    OrderItem(DrinkMaker *drinkMaker) : foodMaker(nullptr), drinkMaker(drinkMaker)
    {
        if (drinkMaker == nullptr)
        {
            throw std::invalid_argument("OrderItem must have a DrinkMaker");
        }
        if (!drinkMaker->getDrink()->isTakeawayAvailable())
        {
            cout << "You can't order " << drinkMaker->getDrink()->getDescription() << " for takeaway.\n";
            drinkMaker = nullptr; // set drinkMaker to nullptr
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