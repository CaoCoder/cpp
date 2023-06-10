#ifndef SELLER_H
#define SELLER_H

#include "User.h"
#include "Product.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>



class Seller : public User {
private:
    std::string storeName;
    /*std::vector<Product*> products;*/

public:
    Seller(std::string name, std::string pwd, std::string store);

    void addProduct(Product* product);
    void removeProduct(Product* product);
    void updateProduct(Product* product, std::string newName, double newPrice, int newQuantity);
    void searchProductById(int id) const;
    void searchProductByName(std::string name) const;
    void searchProductByCategory(int category) const;
    void calculateStats() const;
    void saveToFile() const;
    void viewProducts() const;
    void sortProductsByName();
    void showSortedProducts() const;

    bool login();
    void registerAccount();
    void setName(const std::string& username);
    void setPassword(const std::string& password);
};

#endif  // SELLER_H
