#include <iostream>
#include <string>
using namespace std;

class Food{
    private:
        string name; 
        double price;
        string type;

    public:
        Food(string name, double price, string type){
            this -> name = name;
            this -> price = price;
            this -> type = type;
        }

        string getName(){
            return name;
        }

        string getType(){
            return type;
        }

        string setPrice9(double price){
            this -> price = price;
        }

        double getPrice(){
            return price;
        }

};
