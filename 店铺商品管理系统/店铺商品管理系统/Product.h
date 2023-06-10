#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
protected:
    int productId;
    std::string productName;
    double productPrice;
    int productQuantity;

public:
    Product(int id, std::string name, double price, int quantity);

    int getProductId() const;
    std::string getProductName() const;
    double getProductPrice() const;
    int getProductQuantity() const;

    void setProductName(std::string name);
    void setProductPrice(double price);
    void setProductQuantity(int quantity);
};

#endif  // PRODUCT_H
