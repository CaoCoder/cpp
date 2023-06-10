#include "Buyer.h"
#include <algorithm>
extern std::vector<Product*> products;  // ����ȫ�ֱ���
Buyer::Buyer(std::string name, std::string pwd)
    : User(name, pwd), name(name) {}

void Buyer::searchProductById(const std::vector<Product*>& products, int id) const {
    for (auto& product : products) {
        if (product->getProductId() == id) {
            std::cout << "��Ʒ���: " << product->getProductId() << std::endl;
            std::cout << "��Ʒ����: " << product->getProductName() << std::endl;
            std::cout << "��Ʒ�۸�: " << product->getProductPrice() << std::endl;
            std::cout << "��Ʒ����: " << product->getProductQuantity() << std::endl;
            return;
        }
    }
    std::cout << "δ�ҵ�ƥ�����Ʒ��" << std::endl;
}

void Buyer::searchProductByName(const std::vector<Product*>& products, std::string name) const {
    for (auto& product : products) {
        if (product->getProductName() == name) {
            std::cout << "��Ʒ���: " << product->getProductId() << std::endl;
            std::cout << "��Ʒ����: " << product->getProductName() << std::endl;
            std::cout << "��Ʒ�۸�: " << product->getProductPrice() << std::endl;
            std::cout << "��Ʒ����: " << product->getProductQuantity() << std::endl;
            return;
        }
    }
    std::cout << "δ�ҵ�ƥ�����Ʒ��" << std::endl;
}

void Buyer::searchProductByCategory(const std::vector<Product*>& products, int category) const {
    for (auto& product : products) {
        // ���ݲ�ͬ���������ж�
        if (product->getProductId() == category) {
            std::cout << "��Ʒ���: " << product->getProductId() << std::endl;
            std::cout << "��Ʒ����: " << product->getProductName() << std::endl;
            std::cout << "��Ʒ�۸�: " << product->getProductPrice() << std::endl;
            std::cout << "��Ʒ����: " << product->getProductQuantity() << std::endl;
        }
    }
}

void Buyer::addToCart(Product* product) {
    if (product->getProductQuantity() > 0) {
        cart.push_back(product);
        product->setProductQuantity(product->getProductQuantity() - 1);
        std::cout << "��Ʒ����ӵ����ﳵ��" << std::endl;
    }
    else {
        std::cout << "��Ʒ��治�㣬�޷���ӵ����ﳵ��" << std::endl;
    }
}

void Buyer::showCart() const {
    if (cart.empty()) {
        std::cout << "���ﳵΪ�ա�" << std::endl;
    }
    else {
        std::cout << "���ﳵ�е���Ʒ:" << std::endl;
        for (auto& product : cart) {
            std::cout << "��Ʒ���: " << product->getProductId() << std::endl;
            std::cout << "��Ʒ����: " << product->getProductName() << std::endl;
            std::cout << "��Ʒ�۸�: " << product->getProductPrice() << std::endl;
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
    std::ofstream outfile("buyers.txt", std::ios::app);  // ���ļ���׷�ӷ�ʽд��

    if (outfile.is_open()) {
        outfile << name << " " << getPassword() << std::endl;
        outfile.close();
    }
    else {
        std::cout << "�޷����ļ���" << std::endl;
    }
}