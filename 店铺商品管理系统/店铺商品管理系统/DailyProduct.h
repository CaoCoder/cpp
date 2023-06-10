#ifndef DAILYPRODUCT_H
#define DAILYPRODUCT_H

#include "Product.h"

class DailyProduct : public Product {
public:
    DailyProduct(int id, std::string name, double price, int quantity);
};

#endif  // DAILYPRODUCT_H
