#ifndef SHIPPING_SERVICE_H
#define SHIPPING_SERVICE_H

#include <vector>
#include <memory>
#include <string>
#include <map>
#include "Shippable.h"

class ShippingService {
private:
    static double baseShippingFee;
public:
    static void shipItems(const vector<shared_ptr<Shippable>>& shippableItems,const map<string, int>& quantities);

    static double getShippingFee();

    static double calculateTotalWeight(const vector<shared_ptr<Shippable>>& shippableItems,const map<string, int>& quantities);
};

#endif 