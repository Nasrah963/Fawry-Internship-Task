#define _CRT_SECURE_NO_WARNINGS

#include "ECommerceSystem.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <fstream>

ECommerceSystem::ECommerceSystem() : nextOrderId(1) {
}

void ECommerceSystem::addProduct(shared_ptr<Product> product) {
    if (product) {
        products.push_back(product);
    }
}

bool ECommerceSystem::removeProduct(const string& productName) {
    auto it = find_if(products.begin(), products.end(),
        [&productName](const shared_ptr<Product>& p) {
            return p->getName() == productName;
        });

    if (it != products.end()) {
        products.erase(it);
        return true;
    }
    return false;
}

void ECommerceSystem::addCustomer(std::shared_ptr<Customer> customer) {
    if (customer) {
        customers.push_back(customer);
    }
}

bool ECommerceSystem::checkout(Customer& customer, Cart& cart) {
    cout << "\nCHECKOUT" << std::endl;

    if (cart.isEmpty()) {
        cout << "Cart is empty" << endl;
        return false;
    }

    if (!validateCartItems(cart)) {
        return false;
    }

    double subtotal = cart.getSubtotal();

    auto shippableItems = collectShippableItems(cart);
    auto quantityMap = createQuantityMap(cart);
    double shippingFee = ShippingService::getShippingFee();
    double totalAmount = subtotal + shippingFee;

    if (!customer.hasEnoughBalance(totalAmount)) {
        cout << "Insufficient balance. Required: " << totalAmount << ", Available: " << customer.getBalance() << endl;
        return false;
    }

    Order newOrder(nextOrderId++, customer.getName());
    newOrder.items = cart.getItems();
    newOrder.subtotal = subtotal;
    newOrder.shippingFee = shippingFee;
    newOrder.totalAmount = totalAmount;
    newOrder.orderDate = getCurrentDateTime();
    newOrder.status = "Confirmed";

    customer.deductBalance(totalAmount);
    for (const auto& item : cart.getItems()) {
        item.product->reduceStock(item.quantity);
    }

    if (!shippableItems.empty()) {
        ShippingService::shipItems(shippableItems, quantityMap);
    }

    cout << "\n **Checkout receipt** " << endl;
    for (const auto& item : cart.getItems()) {
        cout << item.quantity << "x " << item.product->getName()
            << " " << (item.product->getPrice() * item.quantity) << endl;
    }
    cout << "----------------------" << endl;
    cout << "Subtotal " << subtotal << endl;
    cout << "Shipping " << shippingFee << endl;
    cout << "Amount " << totalAmount << endl;


    orders.push_back(newOrder);

    cart.clear();

    return true;
}


string ECommerceSystem::getCurrentDateTime() const {
    auto now = chrono::system_clock::now();
    auto time_t = chrono::system_clock::to_time_t(now);

    stringstream ss;

#ifdef _WIN32
    struct tm timeinfo;
    localtime_s(&timeinfo, &time_t);
    ss << put_time(&timeinfo, "%Y-%m-%d %H:%M:%S");
#else
    struct tm timeinfo;
    localtime_r(&time_t, &timeinfo);
    ss << put_time(&timeinfo, "%Y-%m-%d %H:%M:%S");
#endif

    return ss.str();
}

bool ECommerceSystem::validateCartItems(const Cart& cart) const {
    for (const auto& item : cart.getItems()) {
        if (item.product->isExpired()) {
            cout << "Product " << item.product->getName() << " is expired." << endl;
            return false;
        }

        if (!item.product->hasStock(item.quantity)) {
            cout << "Product " << item.product->getName()
                << " is out of stock. Available: " << item.product->getQuantity()
                << ", Requested: " << item.quantity << endl;
            return false;
        }
    }
    return true;
}

vector<shared_ptr<Shippable>> ECommerceSystem::collectShippableItems(const Cart& cart) const {
    vector<shared_ptr<Shippable>> shippableItems;

    for (const auto& item : cart.getItems()) {
        if (item.product->requiresShipping()) {
            auto shippable = dynamic_pointer_cast<Shippable>(item.product);
            if (shippable) {
                shippableItems.push_back(shippable);
            }
        }
    }

    return shippableItems;
}

map<string, int> ECommerceSystem::createQuantityMap(const Cart& cart) const {
    map<string, int> quantities;

    for (const auto& item : cart.getItems()) {
        if (item.product->requiresShipping()) {
            quantities[item.product->getName()] = item.quantity;
        }
    }

    return quantities;
}