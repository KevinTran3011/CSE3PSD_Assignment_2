#ifndef VISITOR_H
#define VISITOR_H

class DrinkMaker;
class FoodMaker;

class Visitor
{
public:
    virtual void visit(DrinkMaker *drink) = 0;
    virtual void visit(FoodMaker *food) = 0;
};

class TakeawayChargeVisitor : public Visitor
{
public:
    void visit(DrinkMaker *drink) override;
    void visit(FoodMaker *food) override;
};

#endif