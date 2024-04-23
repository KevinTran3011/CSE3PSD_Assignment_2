#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "DrinkMaker.h"
#include "FoodMaker.h"

class Visitor {
public:
    virtual void visit(DrinkMaker* drink) = 0;
    virtual void visit(foodMaker* food) = 0;
};

class TakeawayChargeVisitor : public Visitor {
public:
    void visit(DrinkMaker* drink) override {
        drink->getDrink()->setPrice(drink->getDrink()->getPrice() * 1.1);
    }

    void visit(foodMaker* food) override {
        food->getFood()->setPrice(food->getFood()->getPrice() * 1.1);
    }
};

class Order {
private:
    std::vector<DrinkMaker*> drinks;
    std::vector<foodMaker*> foods;

public:
    void addDrink(DrinkMaker* drink) {
        drinks.push_back(drink);
    }

    void addFood(foodMaker* food) {
        foods.push_back(food);
    }

    void applyTakeawayCharge() {
        TakeawayChargeVisitor visitor;
        for (auto& drink : drinks) {
            drink->accept(&visitor);
        }
        for (auto& food : foods) {
            food->accept(&visitor);
        }
    }
};

#endif