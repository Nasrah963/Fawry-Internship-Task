#ifndef SHIPPABLE_PRODUCT_H
#define SHIPPABLE_PRODUCT_H

#include "Product.h"
#include "Shippable.h"

class ShippableProduct : public Product, public Shippable {
private:
    double weight;

public:
    ShippableProduct(const std::string& name, double price, int quantity, double weight);

    bool requiresShipping() const override;
    double getWeight() const override;

    string getName() const override;
    virtual ~ShippableProduct() = default;

};

#endif 