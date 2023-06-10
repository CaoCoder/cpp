#include "Seller.h"
extern std::vector<Product*> products;  // 声明全局变量
// 在 Seller 类的构造函数中
Seller::Seller(std::string name, std::string pwd, std::string store)
    : User(name, pwd), storeName(store) {}


void Seller::addProduct(Product* product) {
    products.push_back(product);
}

void Seller::removeProduct(Product* product) {
    products.erase(std::remove(products.begin(), products.end(), product), products.end());
}

void Seller::updateProduct(Product* product, std::string newName, double newPrice, int newQuantity) {
    product->setProductName(newName);
    product->setProductPrice(newPrice);
    product->setProductQuantity(newQuantity);
}

void Seller::searchProductById(int id) const {
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

void Seller::searchProductByName(std::string name) const {
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

void Seller::searchProductByCategory(int category) const {
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

void Seller::calculateStats() const {
    int totalCount = 0;
    for (auto& product : products) {
        totalCount += product->getProductQuantity();
    }
    std::cout << "总商品数量: " << totalCount << std::endl;
}

void Seller::saveToFile() const {
    std::ofstream file("store_data.txt");
    if (file.is_open()) {
        file << "店铺名称: " << storeName << std::endl;
        file << "店铺商品信息:" << std::endl;
        for (auto& product : products) {
            file << "商品编号: " << product->getProductId() << std::endl;
            file << "商品名称: " << product->getProductName() << std::endl;
            file << "商品价格: " << product->getProductPrice() << std::endl;
            file << "商品数量: " << product->getProductQuantity() << std::endl;
            file << std::endl;
        }
        file.close();
        std::cout << "店铺信息已保存到磁盘。" << std::endl;
    }
    else {
        std::cout << "无法保存店铺信息到磁盘。" << std::endl;
    }
}




void Seller::viewProducts() const {
    if (products.empty()) {
        std::cout << "暂无商品。" << std::endl;
    }
    else {
        std::cout << "当前商品列表:" << std::endl;
        for (auto& product : products) {
            std::cout << "商品编号: " << product->getProductId() << std::endl;
            std::cout << "商品名称: " << product->getProductName() << std::endl;
            std::cout << "商品价格: " << product->getProductPrice() << std::endl;
            std::cout << "商品数量: " << product->getProductQuantity() << std::endl;
            std::cout << std::endl;
        }
    }
}

void Seller::sortProductsByName() {
    std::sort(products.begin(), products.end(), [](Product* a, Product* b) {
        return a->getProductName() < b->getProductName();
        });
}

void Seller::showSortedProducts() const {
    if (products.empty()) {
        std::cout << "暂无商品。" << std::endl;
    }
    else {
        std::cout << "按商品名称排序后的商品列表:" << std::endl;
        for (auto& product : products) {
            std::cout << "商品编号: " << product->getProductId() << std::endl;
            std::cout << "商品名称: " << product->getProductName() << std::endl;
            std::cout << "商品价格: " << product->getProductPrice() << std::endl;
            std::cout << "商品数量: " << product->getProductQuantity() << std::endl;
            std::cout << std::endl;
        }
    }
}
void Seller::setName(const std::string& username) {
    // 设置卖家的用户名
    this->username = username;
}

void Seller::setPassword(const std::string& password) {
    // 设置卖家的密码
    this->password = password;
}

// 注册卖家账户
void Seller::registerAccount() {
    std::string a;
    std::getline(std::cin, a);
    std::string username, password;

    std::cout << "请输入卖家用户名: " ;
    std::getline(std::cin, username);

    std::cout << "请输入密码: " ;
    std::getline(std::cin, password);

    std::ofstream outfile("sellers.txt", std::ios::app);  // 打开文件以追加方式写入

    if (outfile.is_open()) {
        outfile << username << " " << password << std::endl;
        outfile.close();
    }
    else {
        std::cout << "无法打开文件。" << std::endl;
    }

    setName(username);
    setPassword(password);

    std::cout << "卖家账户注册成功！" << std::endl;
}

// 卖家登录
bool Seller::login() {
    std::string username, password;

    std::cout << "请输入卖家用户名: ";
    std::getline(std::cin, username);

    std::cout << "请输入密码: ";
    std::getline(std::cin, password);

  

    std::ifstream infile("sellers.txt");  // 打开文件以读取密码

    if (infile.is_open()) {
        std::string storedUsername, storedPassword;
        bool found = false;

        while (infile >> storedUsername >> storedPassword) {
            if (username == storedUsername && password == storedPassword) {
                found = true;
                break;
            }
        }

        infile.close();

        if (found) {
            std::cout << "登录成功！" << std::endl;
            return true;
        }
        else {
            std::cout << "登录失败！" << std::endl;
            return false;
        }
    }
    else {
        std::cout << "无法打开文件。" << std::endl;
        return false;
    }
}