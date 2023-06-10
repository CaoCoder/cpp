#include "Buyer.h"
#include <algorithm>
extern std::vector<Product*> products;  // 声明全局变量
Buyer::Buyer(std::string name, std::string pwd)
    : User(name, pwd), name(name) {}

void Buyer::searchProductById(const std::vector<Product*>& products, int id) const {
    for (auto& product : products) {
        if (product->getProductId() == id) {
            std::cout << "商品编号: " << product->getProductId() << std::endl;
            std::cout << "商品名称: " << product->getProductName() << std::endl;
            std::cout << "商品价格: " << product->getProductPrice() << std::endl;
            std::cout << "商品数量: " << product->getProductQuantity() << std::endl;
            return;
        }
    }
    std::cout << "未找到匹配的商品。" << std::endl;
}

void Buyer::searchProductByName(const std::vector<Product*>& products, std::string name) const {
    for (auto& product : products) {
        if (product->getProductName() == name) {
            std::cout << "商品编号: " << product->getProductId() << std::endl;
            std::cout << "商品名称: " << product->getProductName() << std::endl;
            std::cout << "商品价格: " << product->getProductPrice() << std::endl;
            std::cout << "商品数量: " << product->getProductQuantity() << std::endl;
            return;
        }
    }
    std::cout << "未找到匹配的商品。" << std::endl;
}

void Buyer::searchProductByCategory(const std::vector<Product*>& products, int category) const {
    for (auto& product : products) {
        // 根据不同的类别进行判断
        if (product->getProductId() == category) {
            std::cout << "商品编号: " << product->getProductId() << std::endl;
            std::cout << "商品名称: " << product->getProductName() << std::endl;
            std::cout << "商品价格: " << product->getProductPrice() << std::endl;
            std::cout << "商品数量: " << product->getProductQuantity() << std::endl;
        }
    }
}

void Buyer::addToCart(Product* product) {
    if (product->getProductQuantity() > 0) {
        cart.push_back(product);
        product->setProductQuantity(product->getProductQuantity() - 1);
        std::cout << "商品已添加到购物车。" << std::endl;
    }
    else {
        std::cout << "商品库存不足，无法添加到购物车。" << std::endl;
    }
}

void Buyer::showCart() const {
    if (cart.empty()) {
        std::cout << "购物车为空。" << std::endl;
    }
    else {
        std::cout << "购物车中的商品:" << std::endl;
        for (auto& product : cart) {
            std::cout << "商品编号: " << product->getProductId() << std::endl;
            std::cout << "商品名称: " << product->getProductName() << std::endl;
            std::cout << "商品价格: " << product->getProductPrice() << std::endl;
            std::cout << std::endl;
        }
    }
}

void Buyer::sortCartByName() {
    std::sort(cart.begin(), cart.end(), [](Product* a, Product* b) {
        return a->getProductName() < b->getProductName();
        });
}
#include <fstream>
void Buyer::registerAccount() {
    std::ofstream outfile("buyers.txt", std::ios::app);  // 打开文件以追加方式写入

    if (outfile.is_open()) {
        outfile << name << " " << getPassword() << std::endl;
        outfile.close();
    }
    else {
        std::cout << "无法打开文件。" << std::endl;
    }
}