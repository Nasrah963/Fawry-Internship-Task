#pragma once
#include <string>
#include <iostream>
using namespace std;

class Shippable
{
public:
    virtual string getName() const = 0;
    virtual double getWeight() const = 0;
    virtual ~Shippable() = default;
};

