// Coffee.h
#ifndef COFFEE_H
#define COFFEE_H

#include <string>
using namespace std;

class Coffee {
protected:
    string name;
    double price;
    string size;

public:
    Coffee(string name, double price, string size);
    virtual ~Coffee(); // Add virtual destructor
    virtual string getName();
    virtual void setPrice(double price);
    virtual double getPrice();
    virtual string getSize();
    static Coffee* createCoffee(string type);
};

class MilkDecorator : public Coffee {
private:
    string milkType;

public:
    MilkDecorator(Coffee* coffee, string milkType);
    ~MilkDecorator(); // Add destructor
};

class SugarDecorator : public Coffee {
private:
    int sugarAmount;

public:
    SugarDecorator(Coffee* coffee, int sugarAmount);
    ~SugarDecorator(); // Add destructor
};

#endif
