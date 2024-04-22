#ifndef TEA_MAKER_H
#define TEA_MAKER_H

#include "Tea.h"
#include <iostream>
#include <string>
using namespace std;


class Tea;

class MilkDecorator : public Tea
{
protected:
    Tea *tea;

public: 
    MilkDecorator(Tea *t) : tea(t) {}

    ~MilkDecorator() {}

    string getDescription() const override
    {
        cout << "Adding milk\n" << endl;
        return tea->getDescription() + ", with Milk";
    }

    double getPrice() const override
    {
        return tea->getPrice() + 0.5;
    }
  };


class SugarDecorator : public Tea{
protected:
    Tea *tea;
    public:
    SugarDecorator(Tea *t) : tea(t) {}
    ~SugarDecorator() {}

    string getDescription() const override
    {
        cout << "Adding sugar\n" << endl;
        return tea->getDescription() + ", with Sugar";
    }

    double getPrice() const override
    {
        return tea->getPrice() + 0.3;
    }
};


class TeaMaker
{
protected:
    Tea *tea;

public:
    TeaMaker(string teaType, bool addMilk, bool addSugar) : tea(nullptr)
    {
        if (teaType == "black") {
            tea = new BlackTea();
        } else if (teaType == "white") {
            tea = new WhiteTea();
        }
        
        if (addMilk) {
            tea = new MilkDecorator(tea);
        }
        if (addSugar) {
            tea = new SugarDecorator(tea);
        }
    }

    virtual ~TeaMaker()
    {
        delete tea;
    }

    Tea *getTea() const
    {
        return tea;
    }

    virtual void boilWater() const
    {
        cout << "Boiling water.\n";
    }

    virtual void steepTea() const
    {
        cout << "Steeping tea.\n";
    }

    virtual void addLemon() const
    {
        cout << "Adding lemon.\n";
    }

    void makeTea()
    {
        boilWater();
        steepTea();
        addLemon();
        cout << "Final Description: " << tea->getDescription() << endl;
        cout << "Final Price: " << tea->getPrice() << endl;
    }
};

class BlackTeaMaker : public TeaMaker
{
public:
    BlackTeaMaker(bool addMilk, bool addSugar) : TeaMaker("black", addMilk, addSugar) {}
};

class WhiteTeaMaker : public TeaMaker
{
public:
    WhiteTeaMaker(bool addMilk, bool addSugar) : TeaMaker("white", addMilk, addSugar) {}
};
#endif