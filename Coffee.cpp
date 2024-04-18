// Coffee.cpp
#include <string>
using namespace std;

class Coffee {
protected:
    string name;
    double price;
    string size;

public:
    Coffee(string name, double price, string size) : name(name), price(price), size(size) {}

    virtual string getName() {
        return name;
    }

    virtual void setPrice(double price) {
        this->price = price;
    }

    virtual double getPrice() {
        return price;
    }

    virtual string getSize() {
        return size;
    }

    static Coffee* createCoffee(string type);
};

class MilkDecorator : public Coffee {
private:
    string milkType;

public:
    MilkDecorator(Coffee* coffee, string milkType) : Coffee(coffee->getName(), coffee->getPrice(), coffee->getSize()), milkType(milkType) {
        this->name += " with " + milkType + " milk";
    }
};

class SugarDecorator : public Coffee {
private:
    int sugarAmount;

public:
    SugarDecorator(Coffee* coffee, int sugarAmount) : Coffee(coffee->getName(), coffee->getPrice(), coffee->getSize()), sugarAmount(sugarAmount) {
        this->name += " with " + to_string(sugarAmount) + " sugar";
        this->price += 0.1 * sugarAmount; // Assuming each sugar costs 0.1
    }
};

Coffee* Coffee::createCoffee(string type) {
    if (type == "black") {
        return new Coffee("Black Coffee", 2.0, "Medium");
    } else if (type == "white") {
        return new Coffee("White Coffee", 2.5, "Medium");
    } else {
        return nullptr;
    }
}