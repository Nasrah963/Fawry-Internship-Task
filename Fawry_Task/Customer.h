#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
using namespace std;

class Cart;

class Customer {
private:
    string name;
    string email;
    string address;
    double balance;

public:
    Customer(const string& name, double initialBalance);
    Customer(const string& name, const string& email,
        const string& address, double initialBalance);

    string getName() const;
    double getBalance() const;

    bool hasEnoughBalance(double amount) const;
    void deductBalance(double amount);
    void addBalance(double amount);

    ~Customer() = default;
};

#endif 