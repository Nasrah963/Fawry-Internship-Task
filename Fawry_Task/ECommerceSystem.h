#ifndef ECOMMERCE_SYSTEM_H
#define ECOMMERCE_SYSTEM_H

#include "Product.h"
#include "Cart.h"
#include "Customer.h"
#include "ShippingService.h"
#include <vector>
#include <memory>
#include <string>
#include <map>

struct Order {
    int orderId;
    string customerName;
    vector<CartItem> items;
    double subtotal;
    double shippingFee;
    double totalAmount;
    string orderDate;
    string status;

    Order(int id, const string& custName) {
        this->orderId = id;
        this->customerName = custName;
        this->subtotal = 0.0;
        this->shippingFee = 0.0;
        this->totalAmount = 0.0;
        this->status = "Processing";
    }
};

class ECommerceSystem {
private:
    vector<shared_ptr<Product>> products;
    vector<shared_ptr<Customer>> customers;
    vector<Order> orders;
    int nextOrderId;

    string getCurrentDateTime() const;
    bool validateCartItems(const Cart& cart) const;
    vector<shared_ptr<Shippable>> collectShippableItems(const Cart& cart) const;
    map<string, int> createQuantityMap(const Cart& cart) const;

public:
    ECommerceSystem();

    void addProduct(shared_ptr<Product> product);
    bool removeProduct(const string& productName);

    void addCustomer(shared_ptr<Customer> customer);

    bool checkout(Customer& customer, Cart& cart);

    ~ECommerceSystem() = default;

};

#endif 