#ifndef FOOD_MAKER_H
#define FOOD_MAKER_H

#include <iostream>
#include <string>
#include "Food.h"
using namespace std;

class Food;

class foodMaker{
    protected:
    Food *food;

    public:
    foodMaker(string foodType) : food(nullptr){
        if(foodType == "sandWich"){
            food = new sandWich();
        }
        else if(foodType == "tiramisu"){
            food = new tiramisu();
        }
    }

    virtual ~foodMaker(){
        if(food){
            delete food;
        }
    }   

    Food *getFood(){
        return food;
    }

    virtual void getIngredients() const{
        cout << "Ingredients: " << food->getDescription() << endl;
    };

    virtual void assembleFood() const{
        cout << "Assembling " << food->getName() << endl;
    }

    void makeFood(){
        getIngredients();
        assembleFood();

        cout << "Final food" << food->getName() << " - $" << food->getPrice() << endl;
    }

};

class SandWichMaker : public foodMaker{
    public:
    SandWichMaker() : foodMaker("sandWich"){}
};

class TiramisuMaker : public foodMaker{
    public:
    TiramisuMaker() : foodMaker("tiramisu"){}
};



#endif