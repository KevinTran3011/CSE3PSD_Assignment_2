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
    OrderItem(FoodMaker *foodMaker) : foodMaker(foodMaker), drinkMaker(nullptr) {}
    OrderItem(DrinkMaker *drinkMaker) : foodMaker(nullptr), drinkMaker(drinkMaker) {}

    void accept(Visitor *visitor)
    {
        visitor->visit(this);
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