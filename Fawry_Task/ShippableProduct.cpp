#include "ShippableProduct.h"

ShippableProduct::ShippableProduct(const std::string& name, double price, int quantity, double weight)
    : Product(name, price, quantity) {
    this->weight = weight;
}

bool ShippableProduct::requiresShipping() const {
    return true;  
}

double ShippableProduct::getWeight() const {
    return weight;
}



string ShippableProduct::getName() const {
    return Product::getName();  
}

