#ifndef BEVERAGEPRODUCT_H
#define BEVERAGEPRODUCT_H

#include "Product.h"

class BeverageProduct : public Product {
public:
    BeverageProduct(int id, std::string name, double price, int quantity);
};

#endif  // BEVERAGEPRODUCT_H
