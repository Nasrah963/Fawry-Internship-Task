#ifndef CART_H
#define CART_H

#include "Product.h"
#include <vector>
#include <memory>

struct CartItem {
    shared_ptr<Product> product;
    int quantity;

    CartItem(shared_ptr<Product> prod, int qty);
};

class Cart {
private:
    // create a container for all cart items
    vector<CartItem> items;

public:
    Cart();

    void add(shared_ptr<Product> product, int quantity);

    bool remove(const string& productName);
    bool remove(const string& productName, int quantity);

    bool updateQuantity(const string& productName, int newQuantity);

    bool isEmpty() const;
    double getSubtotal() const;

    const std::vector<CartItem>& getItems() const;
    void clear();


    ~Cart() = default;
};

#endif 