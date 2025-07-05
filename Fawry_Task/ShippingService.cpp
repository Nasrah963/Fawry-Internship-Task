#include "ShippingService.h"
#include <iostream>
#include <iomanip>
#include <random>
#include <sstream>

double ShippingService::baseShippingFee = 5.0;

void ShippingService::shipItems(const vector<shared_ptr<Shippable>>& shippableItems, const map<string, int>& quantities) {
    if (shippableItems.empty()) {
        return;
    }
    double totalWeight = 0.0;

    for (const auto& item : shippableItems) {
        auto it = quantities.find(item->getName());
        if (it != quantities.end()) {
            int qty = it->second;
            double itemWeight = item->getWeight() * qty;
            totalWeight += itemWeight;

            cout << qty << "x " << item->getName() << " "
                << static_cast<int>(itemWeight * 1000) << "g" << endl;
        }
    }

    cout << "Total package weight " << fixed << setprecision(1) << totalWeight << "kg" << endl;


}

double ShippingService::getShippingFee()
{
    return baseShippingFee;
}


double ShippingService::calculateTotalWeight(const vector<shared_ptr<Shippable>>& shippableItems,
    const map<string, int>& quantities) {
    double totalWeight = 0.0;

    for (const auto& item : shippableItems) {
        auto it = quantities.find(item->getName());
        if (it != quantities.end()) {
            int qty = it->second;
            totalWeight += item->getWeight() * qty;
        }
    }

    return totalWeight;
}