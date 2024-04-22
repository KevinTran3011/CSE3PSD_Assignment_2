#ifndef TEA_TESTER_H
#define TEA_TESTER_H

#include "TeaMaker.h"
#include <iostream>
using namespace std;

class TeaTester
{
public:
    static void test()
    {
        BlackTeaMaker blackTeaMaker(false, false);
        blackTeaMaker.makeTea();
        Tea *blackTea = blackTeaMaker.getTea();
        cout << blackTea->getDescription() << " - $" << blackTea->getPrice() << "\n";

        BlackTeaMaker milkedBlackTeaMaker(true, false);
        milkedBlackTeaMaker.makeTea();
        Tea *milkedBlackTea = milkedBlackTeaMaker.getTea();
        cout << milkedBlackTea->getDescription() << " - $" << milkedBlackTea->getPrice() << "\n";

        BlackTeaMaker sugaredBlackTeaMaker(false, true);
        sugaredBlackTeaMaker.makeTea();
        Tea *sugaredBlackTea = sugaredBlackTeaMaker.getTea();
        cout << sugaredBlackTea->getDescription() << " - $" << sugaredBlackTea->getPrice() << "\n";

        BlackTeaMaker milkedSugaredBlackTeaMaker(true, true);
        milkedSugaredBlackTeaMaker.makeTea();
        Tea *milkedSugaredBlackTea = milkedSugaredBlackTeaMaker.getTea();
        cout << milkedSugaredBlackTea->getDescription() << " - $" << milkedSugaredBlackTea->getPrice() << "\n";
    }
};

#endif 