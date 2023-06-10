#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;


#include "Buyer.h"
#include "Product.h"
#include "User.h"
#include "Seller.h"
#include "Product.h"
#include "FoodProduct.h"
#include "CosmeticsProduct.h"
#include "DailyProduct.h"
#include "BeverageProduct.h"

std::vector<Product*> products;
using namespace std;
int main() {
 

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

        bool validLogin = false;
        if (roleChoice == 1) {



      /*      cout << "请输入用户名: ";
            cin >> username;
            cout << "请输入密码: ";
            cin >> password;*/

            // 卖家登录
            Seller seller("seller", "password", "My Store");
            seller.registerAccount();
            validLogin = seller.login();
            //validLogin = seller.authenticate(password);

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
                    cout << "7. 查看商品" << endl;
                    cout << "8. 按名称排序商品" << endl;
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
                    case 7: {
                        seller.viewProducts();
                        break;
                    }
                    case 8: {
                        //排序
                        seller.sortProductsByName();
                        seller.showSortedProducts();
                        break;
                    }
                    default:
                        cout << "无效的选择。" << endl;
                    }
                }
            }
        }
        else if (roleChoice == 2) {
            int buyerLoginChoice;
            cout << "请选择登录方式:" << endl;
            cout << "1. 已有账户登录" << endl;
            cout << "2. 注册新账户" << endl;
            cout << "请输入选择: ";
            cin >> buyerLoginChoice;

            if (buyerLoginChoice == 1) {
                // 已有账户登录          
            }
            else if (buyerLoginChoice == 2) {
             
                // 注册新账户
                string buyerName, buyerPassword;

                cout << "请输入买家姓名: ";
                cin >> buyerName;
                cout << "请输入密码: ";
                cin >> buyerPassword;

                Buyer buyer(buyerName, buyerPassword);
                buyer.registerAccount();

                cout << "买家注册成功！" << endl;
                cout << "请使用新账户登录。" << endl;
            }
            else {
                cout << "无效的选择。" << endl;
            }
            
            
            // 买家登录
            cout << "请输入用户名: ";
            cin >> username;
            cout << "请输入密码: ";
            cin >> password;
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
                    cout << "4. 按商品名称排序" << endl;

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

                    case 4:
                    {
                        //按名称排序
                        buyer.sortCartByName();
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
