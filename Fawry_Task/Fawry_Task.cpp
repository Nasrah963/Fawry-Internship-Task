#include "ECommerceSystem.h"
#include "Product.h"
#include "ExpirableShippableProduct.h"
#include "ShippableProduct.h"
#include "Customer.h"
#include "Cart.h"
#include <chrono>
#include <iostream>
#include <memory>

int main() {
    std::cout << "=== E-COMMERCE SYSTEM TEST ===" << std::endl;

    // create new products using shared_ptr 
    auto cheese = make_shared<ExpirableShippableProduct>("Cheese", 100.0, 10, 0.4,
        chrono::system_clock::now() + chrono::hours(24 * 30)); 

    auto biscuits = make_shared<ExpirableShippableProduct>("Biscuits", 150.0, 5, 0.7,
        chrono::system_clock::now() + chrono::hours(24 * 60)); 

    auto scratchCard = make_shared<Product>("Mobile Scratch Card", 25.0, 100);

    Customer customer("John Doe", 1000.0);
    Cart cart;

    cout << "\nAdding items to cart:" << std::endl;
    cart.add(cheese, 2);
    cart.add(biscuits, 1);
    cart.add(scratchCard, 1);


    ECommerceSystem system;
    system.addProduct(cheese);
    system.addProduct(biscuits);
    system.addProduct(scratchCard);
    system.addCustomer(make_shared<Customer>(customer));

    cout << "\ncheckout(customer, cart);" << endl;

    bool success = system.checkout(customer, cart);

    if (success) {
        cout << "\n successful operation" << endl;
    }
    else {
        std::cout << "\nError" << endl;
    }
    return 0;
}