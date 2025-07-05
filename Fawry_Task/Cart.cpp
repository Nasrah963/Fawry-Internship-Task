#include "Cart.h"
#include <iostream>
#include <iomanip>

CartItem::CartItem(shared_ptr<Product> prod, int qty)
{
    this->product = prod;
    this->quantity = qty;
}

Cart::Cart() {}

void Cart::add(shared_ptr<Product> product, int quantity) {
    if (!product || quantity <= 0)//check if it is empty
    {
        return;
    }

    for (auto& item : items)//increament on an already existed product
    {
        if (item.product->getName() == product->getName()) {
            item.quantity += quantity;
            return;
        }
    }

    // Add new product to the container
    items.emplace_back(product, quantity);
}

bool Cart::remove(const string& productName) { //remove the whole product
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->product->getName() == productName) {
            items.erase(it); //requires the index of the item to be removed from the container
            return true;
        }
    }
    return false;
}

bool Cart::remove(const string& productName, int quantity) { //decrement its count
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->product->getName() == productName) {
            if (it->quantity <= quantity) {
                items.erase(it);
            }
            else {
                it->quantity -= quantity;
            }
            return true;
        }
    }
    return false;
}

bool Cart::updateQuantity(const string& productName, int newQuantity) {
    if (newQuantity <= 0) {
        return remove(productName);
    }

    for (auto& item : items) {
        if (item.product->getName() == productName) {
            item.quantity = newQuantity;
            return true;
        }
    }
    return false;
}

bool Cart::isEmpty() const {
    return items.empty();
}


double Cart::getSubtotal() const {
    double subtotal = 0.0;
    for (const auto& item : items) {
        subtotal += item.product->getPrice() * item.quantity;
    }
    return subtotal;
}

const vector<CartItem>& Cart::getItems() const {
    return items;
}


void Cart::clear() {
    items.clear();
}

