#ifndef DRINK_H
#define DRINK_H

#include <string>
using namespace std;

class Drink
{
protected:
    string name;
    string description;
    double price;
    bool takeawayAvailable;

public:
    virtual ~Drink() {}
    virtual string getName() const { return name; }
    virtual string getDescription() const { return description; }
    virtual double getPrice() const { return price; }
    virtual bool isTakeawayAvailable() const { return takeawayAvailable; }

    void setName(const string &name) { this->name = name; }
    void setDescription(const string &description) { this->description = description; }
    void setPrice(double price) { this->price = price; }
    virtual void setTakeawayAvailable(bool available) { this->takeawayAvailable = available; }
};

#endif