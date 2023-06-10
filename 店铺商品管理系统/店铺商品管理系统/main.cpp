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
 

    // ���һЩʾ����Ʒ
    products.push_back(new FoodProduct(1, "ƻ��", 5.99, 10));
    products.push_back(new CosmeticsProduct(2, "ϴ����", 29.99, 5));
    products.push_back(new DailyProduct(3, "��ˢ", 4.5, 20));
    products.push_back(new BeverageProduct(4, "����", 3.99, 15));


    string username, password;
    int roleChoice;

    // ����һ���˵�
    while (true) {
        cout << "��ӭʹ�õ�����Ʒ����ϵͳ��" << endl;
        cout << "��ѡ���ɫ:" << endl;
        cout << "1. ����" << endl;
        cout << "2. ���" << endl;
        cout << "0. �˳�ϵͳ" << endl;
        cout << "������ѡ��: ";
        cin >> roleChoice;

        if (roleChoice == 0) {
            break;
        }

        bool validLogin = false;
        if (roleChoice == 1) {



      /*      cout << "�������û���: ";
            cin >> username;
            cout << "����������: ";
            cin >> password;*/

            // ���ҵ�¼
            Seller seller("seller", "password", "My Store");
            seller.registerAccount();
            validLogin = seller.login();
            //validLogin = seller.authenticate(password);

            if (validLogin) {
                cout << "���ҵ�¼�ɹ���" << endl;

                int sellerChoice;
                while (true) {
                    cout << "��ѡ�����:" << endl;
                    cout << "1. �����Ʒ" << endl;
                    cout << "2. ɾ����Ʒ" << endl;
                    cout << "3. �޸���Ʒ" << endl;
                    cout << "4. ��ѯ��Ʒ" << endl;
                    cout << "5. ͳ����Ʒ" << endl;
                    cout << "6. ���浽����" << endl;
                    cout << "7. �鿴��Ʒ" << endl;
                    cout << "8. ������������Ʒ" << endl;
                    cout << "0. �˳�ϵͳ" << endl;
                    cout << "������ѡ��: ";
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
                        // �����Ʒ
                        cout << "��������Ʒ���: ";
                        cin >> productId;
                        cout << "��������Ʒ����: ";
                        cin >> productName;
                        cout << "��������Ʒ�۸�: ";
                        cin >> productPrice;
                        cout << "��������Ʒ����: ";
                        cin >> productQuantity;

                        products.push_back(new Product(productId, productName, productPrice, productQuantity));
                        cout << "��Ʒ����ӡ�" << endl;
                        break;
                    }
                    case 2: {
                        // ɾ����Ʒ
                        cout << "������Ҫɾ������Ʒ���: ";
                        cin >> productId;

                        for (auto& product : products) {
                            if (product->getProductId() == productId) {
                                delete product;
                                products.erase(remove(products.begin(), products.end(), product), products.end());
                                cout << "��Ʒ��ɾ����" << endl;
                                break;
                            }
                        }
                        break;
                    }
                    case 3: {
                        // �޸���Ʒ
                        cout << "������Ҫ�޸ĵ���Ʒ���: ";
                        cin >> productId;

                        for (auto& product : products) {
                            if (product->getProductId() == productId) {
                                cout << "�������µ���Ʒ����: ";
                                cin >> productName;
                                cout << "�������µ���Ʒ�۸�: ";
                                cin >> productPrice;
                                cout << "�������µ���Ʒ����: ";
                                cin >> productQuantity;

                                seller.updateProduct(product, productName, productPrice, productQuantity);
                                cout << "��Ʒ���޸ġ�" << endl;
                                break;
                            }
                        }
                        break;
                    }
                    case 4: {
                        // ��ѯ��Ʒ
                        int searchChoice;
                        cout << "��ѡ���ѯ��ʽ:" << endl;
                        cout << "1. ����Ʒ��Ų�ѯ" << endl;
                        cout << "2. ����Ʒ���Ʋ�ѯ" << endl;
                        cout << "3. ����Ʒ����ѯ" << endl;
                        cout << "������ѡ��: ";
                        cin >> searchChoice;

                        if (searchChoice == 1) {
                            // ����Ʒ��Ų�ѯ
                            cout << "������Ҫ��ѯ����Ʒ���: ";
                            cin >> productId;
                            seller.searchProductById(productId);
                        }
                        else if (searchChoice == 2) {
                            // ����Ʒ���Ʋ�ѯ
                            cout << "������Ҫ��ѯ����Ʒ����: ";
                            cin >> productName;
                            seller.searchProductByName(productName);
                        }
                        else if (searchChoice == 3) {
                            // ����Ʒ����ѯ
                            int category;
                            cout << "��ѡ����Ʒ���:" << endl;
                            cout << "1. ʳƷ" << endl;
                            cout << "2. ��ױƷ" << endl;
                            cout << "3. ����Ʒ" << endl;
                            cout << "4. ����" << endl;
                            cout << "������ѡ��: ";
                            cin >> category;
                            seller.searchProductByCategory(category);
                        }
                        break;
                    }
                    case 5: {
                        // ͳ����Ʒ
                        seller.calculateStats();
                        break;
                    }
                    case 6: {
                        // ���浽����
                        seller.saveToFile();
                        break;
                    }
                    case 7: {
                        seller.viewProducts();
                        break;
                    }
                    case 8: {
                        //����
                        seller.sortProductsByName();
                        seller.showSortedProducts();
                        break;
                    }
                    default:
                        cout << "��Ч��ѡ��" << endl;
                    }
                }
            }
        }
        else if (roleChoice == 2) {
            int buyerLoginChoice;
            cout << "��ѡ���¼��ʽ:" << endl;
            cout << "1. �����˻���¼" << endl;
            cout << "2. ע�����˻�" << endl;
            cout << "������ѡ��: ";
            cin >> buyerLoginChoice;

            if (buyerLoginChoice == 1) {
                // �����˻���¼          
            }
            else if (buyerLoginChoice == 2) {
             
                // ע�����˻�
                string buyerName, buyerPassword;

                cout << "�������������: ";
                cin >> buyerName;
                cout << "����������: ";
                cin >> buyerPassword;

                Buyer buyer(buyerName, buyerPassword);
                buyer.registerAccount();

                cout << "���ע��ɹ���" << endl;
                cout << "��ʹ�����˻���¼��" << endl;
            }
            else {
                cout << "��Ч��ѡ��" << endl;
            }
            
            
            // ��ҵ�¼
            cout << "�������û���: ";
            cin >> username;
            cout << "����������: ";
            cin >> password;
            Buyer buyer("buyer", "password");
            validLogin = buyer.authenticate(password);

            if (validLogin) {
                cout << "��ҵ�¼�ɹ���" << endl;

                int buyerChoice;
                while (true) {
                    cout << "��ѡ�����:" << endl;
                    cout << "1. ��ѯ��Ʒ" << endl;
                    cout << "2. ���빺�ﳵ" << endl;
                    cout << "3. �鿴���ﳵ" << endl;
                    cout << "4. ����Ʒ��������" << endl;

                    cout << "0. �˳�ϵͳ" << endl;
                    cout << "������ѡ��: ";
                    cin >> buyerChoice;

                    if (buyerChoice == 0) {
                        break;
                    }

                    int productId;
                    string productName;

                    switch (buyerChoice) {
                    case 1: {
                        // ��ѯ��Ʒ
                        int searchChoice;
                        cout << "��ѡ���ѯ��ʽ:" << endl;
                        cout << "1. ����Ʒ��Ų�ѯ" << endl;
                        cout << "2. ����Ʒ���Ʋ�ѯ" << endl;
                        cout << "3. ����Ʒ����ѯ" << endl;
                        cout << "������ѡ��: ";
                        cin >> searchChoice;

                        if (searchChoice == 1) {
                            // ����Ʒ��Ų�ѯ
                            cout << "������Ҫ��ѯ����Ʒ���: ";
                            cin >> productId;
                            buyer.searchProductById(products, productId);
                        }
                        else if (searchChoice == 2) {
                            // ����Ʒ���Ʋ�ѯ
                            cout << "������Ҫ��ѯ����Ʒ����: ";
                            cin >> productName;
                            buyer.searchProductByName(products, productName);
                        }
                        else if (searchChoice == 3) {
                            // ����Ʒ����ѯ
                            int category;
                            cout << "��ѡ����Ʒ���:" << endl;
                            cout << "1. ʳƷ" << endl;
                            cout << "2. ��ױƷ" << endl;
                            cout << "3. ����Ʒ" << endl;
                            cout << "4. ����" << endl;
                            cout << "������ѡ��: ";
                            cin >> category;
                            buyer.searchProductByCategory(products, category);
                        }
                        break;
                    }
                    case 2: {
                        // ���빺�ﳵ
                        cout << "������Ҫ���빺�ﳵ����Ʒ���: ";
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
                        // �鿴���ﳵ
                        buyer.showCart();
                        break;
                    }

                    case 4:
                    {
                        //����������
                        buyer.sortCartByName();
                        buyer.showCart();
                        break;
                    }
                    default:
                        cout << "��Ч��ѡ��" << endl;
                    }
                }
            }
        }

        if (!validLogin) {
            cout << "�û�����������������ԡ�" << endl;
        }
    }

    // �ͷŶ�̬�������Ʒ����
    for (auto& product : products) {
        delete product;
    }

    return 0;
}
