#ifndef FOOD
#define FOOD

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
    virtual void setPrice(const double &newPrice){price = newPrice;}



};

class sandWich : public Food{
    public:
    sandWich(){
        setName("Sandwich");
        setDescription("2 slices of bread with scrambled eggs, crispy bacon, melted and lettuce");
        setPrice(5.0);
    }

};

class tiramisu : public Food{
    public:
    tiramisu(){
        setName("Tiramisu");
        setDescription("A coffee-flavoured Italian dessert made from lady finger cookies\n dipped in coffee , with layers of mascapone cheese");
        setPrice(4.0);
    }
};
class foodFactory{
    public:
    static Food *createFood(const string &foodType){
        if(foodType == "sandWich")
            return new sandWich();
        else if(foodType == "tiramisu")
            return new tiramisu();
        else
            cout << " We don't recognize this food type\n" << endl;
            return nullptr;
    }
};

#endif