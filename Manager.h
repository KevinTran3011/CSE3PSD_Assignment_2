#ifndef MANAGER_H
#define MANAGER_H

#include "Order.h"
#include "OrderItem.h"
#include "FoodMaker.h"
#include "DrinkMaker.h"
#include "TakeAwayChargeVisitor.h"

class Order;
class OrderItem;
class TakeawayChargeVisitor;

class Manager
{
public:
    OrderItem *createOrderItem(FoodMaker *foodMaker = nullptr, DrinkMaker *drinkMaker = nullptr)
    {
        return new OrderItem(foodMaker, drinkMaker);
    };
    bool addItemToOrder(Order &order, OrderItem *item)
    {
        return order.addItem(item);
    };
    double calculateTotal(Order &order)
    {
        return order.getTotalPrice();
    };
};

#endif