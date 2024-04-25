#ifndef FOOD_MAKER_H
#define FOOD_MAKER_H

#include <iostream>
#include <string>
#include "Food.h"
using namespace std;

class FoodMaker
{
protected:
    Food *food;

public:
    FoodMaker(string foodType) : food(nullptr)
    {
        food = FoodFactory::createFood(foodType);
    }

    virtual ~FoodMaker()
    {
        if (food)
        {
            delete food;
        }
    }

    Food *getFood()
    {
        return food;
    }

    virtual void getIngredients() const
    {
        cout << "Ingredients: " << food->getDescription() << endl;
    };
};

class SandwichMaker : public FoodMaker
{
public:
    SandwichMaker() : FoodMaker("sandwich") {}
};

class TiramisuMaker : public FoodMaker
{
public:
    TiramisuMaker() : FoodMaker("tiramisu") {}
};

#endif