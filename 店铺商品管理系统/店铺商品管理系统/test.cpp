#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// 商品类
class Product {
protected:
    int productId;
    string productName;
    double productPrice;
    int productQuantity;

public:
    Product(int id, string name, double price, int quantity)
        : productId(id), productName(name), productPrice(price), productQuantity(quantity) {}

    int getProductId() const {
        return productId;
    }

    string getProductName() const {
        return productName;
    }

    double getProductPrice() const {
        return productPrice;
    }

    int getProductQuantity() const {
        return productQuantity;
    }

    void setProductName(string name) {
        productName = name;
    }

    void setProductPrice(double price) {
        productPrice = price;
    }

    void setProductQuantity(int quantity) {
        productQuantity = quantity;
    }
};

// 食品类
class FoodProduct : public Product {
public:
    FoodProduct(int id, string name, double price, int quantity)
        : Product(id, name, price, quantity) {}
};

// 化妆品类
class CosmeticsProduct : public Product {
public:
    CosmeticsProduct(int id, string name, double price, int quantity)
        : Product(id, name, price, quantity) {}
};

// 日用品类
class DailyProduct : public Product {
public:
    DailyProduct(int id, string name, double price, int quantity)
        : Product(id, name, price, quantity) {}
};

// 饮料类
class BeverageProduct : public Product {
public:
    BeverageProduct(int id, string name, double price, int quantity)
        : Product(id, name, price, quantity) {}
};

// 用户类
class User {
protected:
    string username;
    string password;

public:
    User(string name, string pwd)
        : username(name), password(pwd) {}

    bool authenticate(string pwd) const {
        return password == pwd;
    }
};

// 卖家类
class Seller : public User {
private:
    string storeName;
    vector<Product*> products;

public:
    Seller(string name, string pwd, string store)
        : User(name, pwd), storeName(store) {}

    void addProduct(Product* product) {
        products.push_back(product);
    }

    void removeProduct(Product* product) {
        products.erase(remove(products.begin(), products.end(), product), products.end());
    }

    void updateProduct(Product* product, string newName, double newPrice, int newQuantity) {
        product->setProductName(newName);
        product->setProductPrice(newPrice);
        product->setProductQuantity(newQuantity);
    }

    void searchProductById(int id) const {
        for (auto& product : products) {
            if (product->getProductId() == id) {
                cout << "商品编号: " << product->getProductId() << endl;
                cout << "商品名称: " << product->getProductName() << endl;
                cout << "商品价格: " << product->getProductPrice() << endl;
                cout << "商品数量: " << product->getProductQuantity() << endl;
                return;
            }
        }
        cout << "未找到匹配的商品。" << endl;
    }

    void searchProductByName(string name) const {
        for (auto& product : products) {
            if (product->getProductName() == name) {
                cout << "商品编号: " << product->getProductId() << endl;
                cout << "商品名称: " << product->getProductName() << endl;
                cout << "商品价格: " << product->getProductPrice() << endl;
                cout << "商品数量: " << product->getProductQuantity() << endl;
                return;
            }
        }
        cout << "未找到匹配的商品。" << endl;
    }

    void searchProductByCategory(int category) const {
        for (auto& product : products) {
            // 根据不同的类别进行判断
            if (product->getProductId() == category) {
                cout << "商品编号: " << product->getProductId() << endl;
                cout << "商品名称: " << product->getProductName() << endl;
                cout << "商品价格: " << product->getProductPrice() << endl;
                cout << "商品数量: " << product->getProductQuantity() << endl;
            }
        }
    }

    void calculateStats() const {
        int totalCount = 0;
        for (auto& product : products) {
            totalCount += product->getProductQuantity();
        }
        cout << "总商品数量: " << totalCount << endl;
    }

    void saveToFile() const {
        ofstream file("store_data.txt");
        if (file.is_open()) {
            file << "店铺名称: " << storeName << endl;
            file << "店铺商品信息:" << endl;
            for (auto& product : products) {
                file << "商品编号: " << product->getProductId() << endl;
                file << "商品名称: " << product->getProductName() << endl;
                file << "商品价格: " << product->getProductPrice() << endl;
                file << "商品数量: " << product->getProductQuantity() << endl;
                file << endl;
            }
            file.close();
            cout << "店铺信息已保存到磁盘。" << endl;
        }
        else {
            cout << "无法保存店铺信息到磁盘。" << endl;
        }
    }
};

// 买家类
class Buyer : public User {
private:
    string name;
    vector<Product*> cart;

public:
    Buyer(string name, string pwd)
        : User(name, pwd), name(name) {}

    void searchProductById(const vector<Product*>& products, int id) const {
        for (auto& product : products) {
            if (product->getProductId() == id) {
                cout << "商品编号: " << product->getProductId() << endl;
                cout << "商品名称: " << product->getProductName() << endl;
                cout << "商品价格: " << product->getProductPrice() << endl;
                cout << "商品数量: " << product->getProductQuantity() << endl;
                return;
            }
        }
        cout << "未找到匹配的商品。" << endl;
    }

    void searchProductByName(const vector<Product*>& products, string name) const {
        for (auto& product : products) {
            if (product->getProductName() == name) {
                cout << "商品编号: " << product->getProductId() << endl;
                cout << "商品名称: " << product->getProductName() << endl;
                cout << "商品价格: " << product->getProductPrice() << endl;
                cout << "商品数量: " << product->getProductQuantity() << endl;
                return;
            }
        }
        cout << "未找到匹配的商品。" << endl;
    }

    void searchProductByCategory(const vector<Product*>& products, int category) const {
        for (auto& product : products) {
            // 根据不同的类别进行判断
            if (product->getProductId() == category) {
                cout << "商品编号: " << product->getProductId() << endl;
                cout << "商品名称: " << product->getProductName() << endl;
                cout << "商品价格: " << product->getProductPrice() << endl;
                cout << "商品数量: " << product->getProductQuantity() << endl;
            }
        }
    }

    void addToCart(Product* product) {
        if (product->getProductQuantity() > 0) {
            cart.push_back(product);
            product->setProductQuantity(product->getProductQuantity() - 1);
            cout << "商品已添加到购物车。" << endl;
        }
        else {
            cout << "商品库存不足，无法添加到购物车。" << endl;
        }
    }

    void showCart() const {
        if (cart.empty()) {
            cout << "购物车为空。" << endl;
        }
        else {
            cout << "购物车中的商品:" << endl;
            for (auto& product : cart) {
                cout << "商品编号: " << product->getProductId() << endl;
                cout << "商品名称: " << product->getProductName() << endl;
                cout << "商品价格: " << product->getProductPrice() << endl;
                cout << endl;
            }
        }
    }
};

int main() {
    vector<Product*> products;

    // 添加一些示例商品
    products.push_back(new FoodProduct(1, "苹果", 5.99, 10));
    products.push_back(new CosmeticsProduct(2, "洗面奶", 29.99, 5));
    products.push_back(new DailyProduct(3, "牙刷", 4.5, 20));
    products.push_back(new BeverageProduct(4, "可乐", 3.99, 15));

    string username, password;
    int roleChoice;

    // 进入一级菜单
    while (true) {
        cout << "欢迎使用店铺商品管理系统！" << endl;
        cout << "请选择角色:" << endl;
        cout << "1. 卖家" << endl;
        cout << "2. 买家" << endl;
        cout << "0. 退出系统" << endl;
        cout << "请输入选择: ";
        cin >> roleChoice;

        if (roleChoice == 0) {
            break;
        }

        cout << "请输入用户名: ";
        cin >> username;
        cout << "请输入密码: ";
        cin >> password;

        bool validLogin = false;
        if (roleChoice == 1) {
            // 卖家登录
            Seller seller("seller", "password", "My Store");
            validLogin = seller.authenticate(password);

            if (validLogin) {
                cout << "卖家登录成功！" << endl;

                int sellerChoice;
                while (true) {
                    cout << "请选择操作:" << endl;
                    cout << "1. 添加商品" << endl;
                    cout << "2. 删除商品" << endl;
                    cout << "3. 修改商品" << endl;
                    cout << "4. 查询商品" << endl;
                    cout << "5. 统计商品" << endl;
                    cout << "6. 保存到磁盘" << endl;
                    cout << "0. 退出系统" << endl;
                    cout << "请输入选择: ";
                    cin >> sellerChoice;

                    if (sellerChoice == 0) {
                        break;
                    }

                    int productId;
                    string productName;
                    double productPrice;
                    int productQuantity;

                    switch (sellerChoice) {
                    case 1: {
                        // 添加商品
                        cout << "请输入商品编号: ";
                        cin >> productId;
                        cout << "请输入商品名称: ";
                        cin >> productName;
                        cout << "请输入商品价格: ";
                        cin >> productPrice;
                        cout << "请输入商品数量: ";
                        cin >> productQuantity;

                        products.push_back(new Product(productId, productName, productPrice, productQuantity));
                        cout << "商品已添加。" << endl;
                        break;
                    }
                    case 2: {
                        // 删除商品
                        cout << "请输入要删除的商品编号: ";
                        cin >> productId;

                        for (auto& product : products) {
                            if (product->getProductId() == productId) {
                                delete product;
                                products.erase(remove(products.begin(), products.end(), product), products.end());
                                cout << "商品已删除。" << endl;
                                break;
                            }
                        }
                        break;
                    }
                    case 3: {
                        // 修改商品
                        cout << "请输入要修改的商品编号: ";
                        cin >> productId;

                        for (auto& product : products) {
                            if (product->getProductId() == productId) {
                                cout << "请输入新的商品名称: ";
                                cin >> productName;
                                cout << "请输入新的商品价格: ";
                                cin >> productPrice;
                                cout << "请输入新的商品数量: ";
                                cin >> productQuantity;

                                seller.updateProduct(product, productName, productPrice, productQuantity);
                                cout << "商品已修改。" << endl;
                                break;
                            }
                        }
                        break;
                    }
                    case 4: {
                        // 查询商品
                        int searchChoice;
                        cout << "请选择查询方式:" << endl;
                        cout << "1. 按商品编号查询" << endl;
                        cout << "2. 按商品名称查询" << endl;
                        cout << "3. 按商品类别查询" << endl;
                        cout << "请输入选择: ";
                        cin >> searchChoice;

                        if (searchChoice == 1) {
                            // 按商品编号查询
                            cout << "请输入要查询的商品编号: ";
                            cin >> productId;
                            seller.searchProductById(productId);
                        }
                        else if (searchChoice == 2) {
                            // 按商品名称查询
                            cout << "请输入要查询的商品名称: ";
                            cin >> productName;
                            seller.searchProductByName(productName);
                        }
                        else if (searchChoice == 3) {
                            // 按商品类别查询
                            int category;
                            cout << "请选择商品类别:" << endl;
                            cout << "1. 食品" << endl;
                            cout << "2. 化妆品" << endl;
                            cout << "3. 日用品" << endl;
                            cout << "4. 饮料" << endl;
                            cout << "请输入选择: ";
                            cin >> category;
                            seller.searchProductByCategory(category);
                        }
                        break;
                    }
                    case 5: {
                        // 统计商品
                        seller.calculateStats();
                        break;
                    }
                    case 6: {
                        // 保存到磁盘
                        seller.saveToFile();
                        break;
                    }
                    default:
                        cout << "无效的选择。" << endl;
                    }
                }
            }
        }
        else if (roleChoice == 2) {
            // 买家登录
            Buyer buyer("buyer", "password");
            validLogin = buyer.authenticate(password);

            if (validLogin) {
                cout << "买家登录成功！" << endl;

                int buyerChoice;
                while (true) {
                    cout << "请选择操作:" << endl;
                    cout << "1. 查询商品" << endl;
                    cout << "2. 加入购物车" << endl;
                    cout << "3. 查看购物车" << endl;
                    cout << "0. 退出系统" << endl;
                    cout << "请输入选择: ";
                    cin >> buyerChoice;

                    if (buyerChoice == 0) {
                        break;
                    }

                    int productId;
                    string productName;

                    switch (buyerChoice) {
                    case 1: {
                        // 查询商品
                        int searchChoice;
                        cout << "请选择查询方式:" << endl;
                        cout << "1. 按商品编号查询" << endl;
                        cout << "2. 按商品名称查询" << endl;
                        cout << "3. 按商品类别查询" << endl;
                        cout << "请输入选择: ";
                        cin >> searchChoice;

                        if (searchChoice == 1) {
                            // 按商品编号查询
                            cout << "请输入要查询的商品编号: ";
                            cin >> productId;
                            buyer.searchProductById(products, productId);
                        }
                        else if (searchChoice == 2) {
                            // 按商品名称查询
                            cout << "请输入要查询的商品名称: ";
                            cin >> productName;
                            buyer.searchProductByName(products, productName);
                        }
                        else if (searchChoice == 3) {
                            // 按商品类别查询
                            int category;
                            cout << "请选择商品类别:" << endl;
                            cout << "1. 食品" << endl;
                            cout << "2. 化妆品" << endl;
                            cout << "3. 日用品" << endl;
                            cout << "4. 饮料" << endl;
                            cout << "请输入选择: ";
                            cin >> category;
                            buyer.searchProductByCategory(products, category);
                        }
                        break;
                    }
                    case 2: {
                        // 加入购物车
                        cout << "请输入要加入购物车的商品编号: ";
                        cin >> productId;

                        for (auto& product : products) {
                            if (product->getProductId() == productId) {
                                buyer.addToCart(product);
                                break;
                            }
                        }
                        break;
                    }
                    case 3: {
                        // 查看购物车
                        buyer.showCart();
                        break;
                    }
                    default:
                        cout << "无效的选择。" << endl;
                    }
                }
            }
        }

        if (!validLogin) {
            cout << "用户名或密码错误，请重试。" << endl;
        }
    }

    // 释放动态分配的商品对象
    for (auto& product : products) {
        delete product;
    }

    return 0;
}
