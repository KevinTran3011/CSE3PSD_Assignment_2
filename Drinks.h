#ifndef DRINKS_H
#define DRINKS_H

#include <iostream>
#include <string>
using namespace std;

class Drink {
protected:
    string description;
    double price;

public:
    virtual ~Drink() {}
    virtual string getDescription() const { return description; }
    virtual double getPrice() const { return price; }
    virtual void setDescription(const string &desc) { description = desc; }
    virtual void setPrice(double p) { price = p; }
};

#endif