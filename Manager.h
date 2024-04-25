#ifndef MANAGER_H
#define MANAGER_H

#include "Order.h"
#include "OrderItem.h"
#include "FoodMaker.h"
#include "DrinkMaker.h"

class Order;
class OrderItem;

class Manager
{
public:
    OrderItem *createOrderItem(FoodMaker *foodMaker = nullptr, DrinkMaker *drinkMaker = nullptr)
    {
        return new OrderItem(foodMaker, drinkMaker);
    };
    void addItemToOrder(Order &order, OrderItem *item)
    {
        order.addItem(item);
    };
    double calculateTotal(Order &order)
    {
        return order.getTotalPrice();
    };
};

#endif