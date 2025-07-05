#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
using namespace std;

class Product {
protected:
    string name;
    double price;
    int quantity;

public:
    Product(const string& name, double price, int quantity);

    string getName() const;
    double getPrice() const;
    int getQuantity() const;

    virtual bool isExpired() const;
    virtual bool requiresShipping() const;
    virtual double getWeight() const;

    bool hasStock(int requestedQuantity) const;
    void reduceStock(int soldQuantity);


    virtual ~Product() = default;
};

#endif 
