#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
using namespace std;

class Food
{
protected:
    string name;
    double price;
    string description;
    bool takeawayAvailable;

public:
    virtual ~Food() {}
    virtual string getName() const { return name; }
    virtual string getDescription() const { return description; }
    virtual double getPrice() const { return price; }
    virtual bool isTakeawayAvailable() const { return takeawayAvailable; }
    virtual void setDescription(const string &desc) { description = desc; }
    virtual void setName(const string &newName) { name = newName; }
    virtual void setPrice(double p) { price = p; }
};

class Sandwich : public Food
{
public:
    Sandwich(bool isTakeaway)
    {
        setName("Sandwich");
        setDescription("2 slices of bread with scrambled eggs, crispy bacon, melted cheese, and lettuce");
        setPrice(5.0);
        takeawayAvailable = isTakeaway ? true : false; // Sandwiches are available for takeaway
    }
};

class Tiramisu : public Food
{
public:
    Tiramisu(bool isTakeaway)
    {
        setName("Tiramisu");
        setDescription("A coffee-flavored Italian dessert made from ladyfinger cookies dipped in coffee, with layers of mascarpone cheese");
        setPrice(4.0);
        takeawayAvailable = isTakeaway ? false : true; // Tiramisu is not available for takeaway
    }
};

class FoodFactory
{
public:
    static Food *createFood(const string &foodType, bool isTakeaway)
    {
        if (foodType == "sandwich")
            return new Sandwich(isTakeaway);
        else if (foodType == "tiramisu")

            return new Tiramisu(isTakeaway);
        else
        {
            cout << "We don't recognize this food type" << endl;
            return nullptr;
        }
    }
};

#endif
