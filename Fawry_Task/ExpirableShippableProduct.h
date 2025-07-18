#ifndef EXPIRABLE_SHIPPABLE_PRODUCT_H
#define EXPIRABLE_SHIPPABLE_PRODUCT_H

#include "Product.h"
#include "Shippable.h"
#include <chrono>

class ExpirableShippableProduct : public Product, public Shippable {
private:
    chrono::system_clock::time_point expirationDate;
    double weight;

public:
    ExpirableShippableProduct(const string& name, double price, int quantity,double weight, chrono::system_clock::time_point expDate);

    bool isExpired() const override;
    bool requiresShipping() const override;
    double getWeight() const override;

    string getName() const override;

    chrono::system_clock::time_point getExpirationDate() const;
    void setExpirationDate(const chrono::system_clock::time_point& expDate);


    virtual ~ExpirableShippableProduct() = default;
};

#endif 