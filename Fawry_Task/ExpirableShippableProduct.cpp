#define _CRT_SECURE_NO_WARNINGS

#include "ExpirableShippableProduct.h"
#include <iomanip>
#include <ctime>

ExpirableShippableProduct::ExpirableShippableProduct(const string& name, double price, int quantity, double weight, chrono::system_clock::time_point expDate)
    : Product(name, price, quantity) {
    this->weight = weight;
    this->expirationDate = expDate;
}

bool ExpirableShippableProduct::isExpired() const {
    return chrono::system_clock::now() > expirationDate;
}

bool ExpirableShippableProduct::requiresShipping() const {
    return true;  
}

double ExpirableShippableProduct::getWeight() const {
    return weight;
}


string ExpirableShippableProduct::getName() const {
    return Product::getName();  
}

chrono::system_clock::time_point ExpirableShippableProduct::getExpirationDate() const {
    return expirationDate;
}

void ExpirableShippableProduct::setExpirationDate(const chrono::system_clock::time_point& expDate) {
    expirationDate = expDate;
}

