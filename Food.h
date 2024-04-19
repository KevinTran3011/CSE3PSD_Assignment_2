#include <iostream>
#include <string>
using namespace std;

class Food{
    private:
        string name; 
        double price;
        string description;

    public:
    virtual ~Food(){};
    virtual string getName() const {return name;}
    virtual string getDescription() const {return description;}
    virtual double getPrice() const {return price;}
    virtual void setDescription(const string &desc ){description = desc;}
    virtual void setName(const string &newName){name = newName; }
    


};
