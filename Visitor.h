#ifndef VISITOR_H
#define VISITOR_H

class OrderItem;

class Visitor
{
public:
    virtual void visit(OrderItem *item) = 0;
};

#endif