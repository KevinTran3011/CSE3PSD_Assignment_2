#include <iostream>
#include "HostFacade.h"

class Host
{
private:
    HostFacade hf;

public:
    void startRestaurant()
    {
        hf.start();
    }

    void addFoodToOrder(Order &order, bool takeaway)
    {
        hf.addFoodToOrder(order, takeaway);
    }

    void addDrinkToOrder(Order &order, bool takeaway)
    {
        hf.addDrinkToOrder(order, takeaway);
    }
};

int main()
{
    Host host;
    host.startRestaurant();
    return 0;
}