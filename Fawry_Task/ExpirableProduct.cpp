#define _CRT_SECURE_NO_WARNINGS

#include "ExpirableProduct.h"
#include <iomanip>
#include <ctime>

ExpirableProduct::ExpirableProduct(const string& name, double price, int quantity,double weight, chrono::system_clock::time_point expDate)
    : Product(name, price, quantity){
    this->weight = weight;
    this->expirationDate = expDate;
}

bool ExpirableProduct::isExpired() const {
    return chrono::system_clock::now() > expirationDate;
}

bool ExpirableProduct::requiresShipping() const {
    return false;  
}

double ExpirableProduct::getWeight() const {
    return weight;
}


string ExpirableProduct::getName() const {
    return Product::getName();  
}

chrono::system_clock::time_point ExpirableProduct::getExpirationDate() const {
    return expirationDate;
}

void ExpirableProduct::setExpirationDate(const chrono::system_clock::time_point& expDate) {
    expirationDate = expDate;
}