#ifndef COSMETICSPRODUCT_H
#define COSMETICSPRODUCT_H

#include "Product.h"

class CosmeticsProduct : public Product {
public:
    CosmeticsProduct(int id, std::string name, double price, int quantity);
};

#endif  // COSMETICSPRODUCT_H
