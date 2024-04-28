#ifndef HOST_H
#define HOST_H

#include <iostream>
#include <string>
#include "TakeAwayChargeVisitor.h"
#include "Manager.h"
#include "FoodMaker.h"
#include "CoffeeMaker.h"
#include "TeaMaker.h"

class HostFacade
{
private:
    Manager manager;

public:
    void start()
    {
        bool takeaway = false;

        std::cout << "Welcome!\n";
        std::cout << "Do you want to eat in or take away? (Enter 'eat in' or 'take away')\n";
        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "take away")
        {
            takeaway = true;
        }

        Order order(takeaway); // Initialize the order with the takeaway parameter

        while (true)
        {
            std::cout << "1- Add food\n";
            std::cout << "2- Add drink\n";
            if (order.getTotalItems() > 0)
            {
                std::cout << "3- Pay\n";
            }
            std::cout << "4- Exit and delete order\n";

            int option;
            std::cin >> option;

            if (option == 1)
            {
                while (!addFoodToOrder(order, takeaway))
                {
                }
            }
            else if (option == 2)
            {
                while (!addDrinkToOrder(order, takeaway))
                {
                }
            }
            else if (option == 3 && order.getTotalItems() > 0)
            {
                double totalPrice = manager.calculateTotal(order);
                std::cout << "Total price: " << totalPrice << std::endl;
                break;
            }
            else if (option == 4)
            {
                break;
            }
        }
    }

    bool addFoodToOrder(Order &order, bool takeaway)
    {
        std::string foodType;
        std::cout << "Enter food type (sandwich or tiramisu): ";
        std::cin >> foodType;

        if (foodType == "sandwich")
        {
            SandwichMaker *sandwichMaker = new SandwichMaker(takeaway);
            OrderItem *sandwichItem = manager.createOrderItem(sandwichMaker, nullptr);
            if (sandwichItem != nullptr)
            {
                bool itemAdded = manager.addItemToOrder(order, sandwichItem);
                if (!itemAdded)
                {
                    std::cout << "Failed to add sandwich to the order.\n";
                    return false;
                }
                if (takeaway)
                {
                    TakeawayChargeVisitor takeawayVisitor;
                    sandwichItem->accept(&takeawayVisitor);
                }
            }
        }
        else if (foodType == "tiramisu")
        {
            TiramisuMaker *tiramisuMaker = new TiramisuMaker(takeaway);
            OrderItem *tiramisuItem = manager.createOrderItem(tiramisuMaker, nullptr);
            if (tiramisuItem != nullptr)
            {
                bool itemAdded = manager.addItemToOrder(order, tiramisuItem);
                if (!itemAdded)
                {
                    std::cout << "Failed to add tiramisu to the order.\n";
                    return false;
                }
                if (takeaway)
                {
                    TakeawayChargeVisitor takeawayVisitor;
                    tiramisuItem->accept(&takeawayVisitor);
                }
            }
        }
        else
        {
            std::cout << "Invalid food type. Please enter 'sandwich' or 'tiramisu'.\n";
            return false;
        }

        return true;
    }

    bool addDrinkToOrder(Order &order, bool takeaway)
    {
        std::string drinkType;
        std::string teaType;
        std::string coffeeType;
        std::string addMilkInput;
        std::string addSugarInput;
        bool addMilk;
        bool addSugar;

        std::cout << "Enter drink type (tea or coffee): ";
        std::cin >> drinkType;

        if (drinkType == "tea")
        {
            std::cout << "What type of tea (chai or matcha): ";
            std::cin >> teaType;
        }
        else if (drinkType == "coffee")
        {
            std::cout << "What type of coffee (black or white): ";
            std::cin >> coffeeType;
        }
        else
        {
            std::cout << "Invalid drink type. Please enter 'tea' or 'coffee'.\n";
            return false;
        }

        std::cout << "Add milk? (Y/N): ";
        std::cin >> addMilkInput;
        addMilk = (addMilkInput == "Y" || addMilkInput == "y");

        std::cout << "Add sugar? (Y/N): ";
        std::cin >> addSugarInput;
        addSugar = (addSugarInput == "Y" || addSugarInput == "y");

        if (drinkType == "tea")
        {
            TeaMaker *teaMaker = new TeaMaker(teaType, addMilk, addSugar);
            OrderItem *teaItem = manager.createOrderItem(nullptr, teaMaker);
            if (teaItem != nullptr)
            {
                bool itemAdded = manager.addItemToOrder(order, teaItem);
                if (!itemAdded)
                {
                    std::cout << "Failed to add tea to the order.\n";
                    return false;
                }
                if (takeaway)
                {
                    TakeawayChargeVisitor takeawayVisitor;
                    teaItem->accept(&takeawayVisitor);
                }
            }
        }
        else
        {
            CoffeeMaker *coffeeMaker = new CoffeeMaker(coffeeType, addMilk, addSugar, takeaway);
            OrderItem *coffeeItem = manager.createOrderItem(nullptr, coffeeMaker);
            if (coffeeItem != nullptr)
            {
                bool itemAdded = manager.addItemToOrder(order, coffeeItem);
                if (!itemAdded)
                {
                    std::cout << "Failed to add coffee to the order.\n";
                    return false;
                }
                if (takeaway)
                {
                    TakeawayChargeVisitor takeawayVisitor;
                    coffeeItem->accept(&takeawayVisitor);
                }
            }
        }

        return true;
    }
};

#endif