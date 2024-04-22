#ifndef DRINKS_H
#define DRINKS_H

#include <iostream>
#include <string>
using namespace std;

class Drink{

public:
    virtual ~Drink() {}
    virtual string getDescription() const = 0;
    virtual double getPrice() const = 0;
    virtual void setDescription(const string &desc) = 0;
    virtual void setPrice(double p) = 0;


};

#endif