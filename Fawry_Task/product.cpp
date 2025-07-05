#include "product.h"


Product::Product(const string& name, double price, int quantity)
{
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}
string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

bool Product::isExpired() const {
    return false;  
}

bool Product::requiresShipping() const {
    return false;  
}

double Product::getWeight() const {
    return 0.0;   
}

bool Product::hasStock(int requestedQuantity) const {
    return quantity >= requestedQuantity;
}

void Product::reduceStock(int soldQuantity) {
    if (soldQuantity <= quantity) {
        quantity -= soldQuantity;
    }
}
