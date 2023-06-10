#ifndef FOODPRODUCT_H
#define FOODPRODUCT_H

#include "Product.h"

class FoodProduct : public Product {
public:
    FoodProduct(int id, std::string name, double price, int quantity);
};

#endif  // FOODPRODUCT_H
