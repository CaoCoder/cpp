#include "Product.h"

Product::Product(int id, std::string name, double price, int quantity)
    : productId(id), productName(name), productPrice(price), productQuantity(quantity) {}

int Product::getProductId() const {
    return productId;
}

std::string Product::getProductName() const {
    return productName;
}

double Product::getProductPrice() const {
    return productPrice;
}

int Product::getProductQuantity() const {
    return productQuantity;
}

void Product::setProductName(std::string name) {
    productName = name;
}

void Product::setProductPrice(double price) {
    productPrice = price;
}

void Product::setProductQuantity(int quantity) {
    productQuantity = quantity;
}
