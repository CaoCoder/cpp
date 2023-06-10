#ifndef BUYER_H
#define BUYER_H

#include "User.h"
#include "Product.h"
#include <vector>
#include <iostream>

class Buyer : public User {
private:
    std::string name;
    std::vector<Product*> cart;

public:
    Buyer(std::string name, std::string pwd);

    void searchProductById(const std::vector<Product*>& products, int id) const;
    void searchProductByName(const std::vector<Product*>& products, std::string name) const;
    void searchProductByCategory(const std::vector<Product*>& products, int category) const;
    void addToCart(Product* product);
    void showCart() const;
    void sortCartByName();//≈≈–Ú
    void registerAccount();
};

#endif  // BUYER_H
