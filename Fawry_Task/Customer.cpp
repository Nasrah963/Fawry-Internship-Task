#include "Customer.h"
#include "Customer.h"
#include <iostream>
#include <iomanip>

Customer::Customer(const std::string& name, double initialBalance)
{
    this->name = name;
    this->email = "";
    this->address = "";
    this->balance = initialBalance;
}

Customer::Customer(const string& name, const string& email , const string& address, double initialBalance)
{
    this->name = name;
    this->email = email;
    this->address = address;
    this->balance = initialBalance;
}


string Customer::getName() const {
    return name;
}


double Customer::getBalance() const {
    return balance;
}


bool Customer::hasEnoughBalance(double amount) const {
    return balance >= amount;
}

void Customer::deductBalance(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    }
}

void Customer::addBalance(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}
