#include "Seller.h"
extern std::vector<Product*> products;  // ����ȫ�ֱ���
// �� Seller ��Ĺ��캯����
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
            std::cout << "��Ʒ���: " << product->getProductId() << std::endl;
            std::cout << "��Ʒ����: " << product->getProductName() << std::endl;
            std::cout << "��Ʒ�۸�: " << product->getProductPrice() << std::endl;
            std::cout << "��Ʒ����: " << product->getProductQuantity() << std::endl;
            return;
        }
    }
    std::cout << "δ�ҵ�ƥ�����Ʒ��" << std::endl;
}

void Seller::searchProductByName(std::string name) const {
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

void Seller::searchProductByCategory(int category) const {
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

void Seller::calculateStats() const {
    int totalCount = 0;
    for (auto& product : products) {
        totalCount += product->getProductQuantity();
    }
    std::cout << "����Ʒ����: " << totalCount << std::endl;
}

void Seller::saveToFile() const {
    std::ofstream file("store_data.txt");
    if (file.is_open()) {
        file << "��������: " << storeName << std::endl;
        file << "������Ʒ��Ϣ:" << std::endl;
        for (auto& product : products) {
            file << "��Ʒ���: " << product->getProductId() << std::endl;
            file << "��Ʒ����: " << product->getProductName() << std::endl;
            file << "��Ʒ�۸�: " << product->getProductPrice() << std::endl;
            file << "��Ʒ����: " << product->getProductQuantity() << std::endl;
            file << std::endl;
        }
        file.close();
        std::cout << "������Ϣ�ѱ��浽���̡�" << std::endl;
    }
    else {
        std::cout << "�޷����������Ϣ�����̡�" << std::endl;
    }
}




void Seller::viewProducts() const {
    if (products.empty()) {
        std::cout << "������Ʒ��" << std::endl;
    }
    else {
        std::cout << "��ǰ��Ʒ�б�:" << std::endl;
        for (auto& product : products) {
            std::cout << "��Ʒ���: " << product->getProductId() << std::endl;
            std::cout << "��Ʒ����: " << product->getProductName() << std::endl;
            std::cout << "��Ʒ�۸�: " << product->getProductPrice() << std::endl;
            std::cout << "��Ʒ����: " << product->getProductQuantity() << std::endl;
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
        std::cout << "������Ʒ��" << std::endl;
    }
    else {
        std::cout << "����Ʒ������������Ʒ�б�:" << std::endl;
        for (auto& product : products) {
            std::cout << "��Ʒ���: " << product->getProductId() << std::endl;
            std::cout << "��Ʒ����: " << product->getProductName() << std::endl;
            std::cout << "��Ʒ�۸�: " << product->getProductPrice() << std::endl;
            std::cout << "��Ʒ����: " << product->getProductQuantity() << std::endl;
            std::cout << std::endl;
        }
    }
}
void Seller::setName(const std::string& username) {
    // �������ҵ��û���
    this->username = username;
}

void Seller::setPassword(const std::string& password) {
    // �������ҵ�����
    this->password = password;
}

// ע�������˻�
void Seller::registerAccount() {
    std::string a;
    std::getline(std::cin, a);
    std::string username, password;

    std::cout << "�����������û���: " ;
    std::getline(std::cin, username);

    std::cout << "����������: " ;
    std::getline(std::cin, password);

    std::ofstream outfile("sellers.txt", std::ios::app);  // ���ļ���׷�ӷ�ʽд��

    if (outfile.is_open()) {
        outfile << username << " " << password << std::endl;
        outfile.close();
    }
    else {
        std::cout << "�޷����ļ���" << std::endl;
    }

    setName(username);
    setPassword(password);

    std::cout << "�����˻�ע��ɹ���" << std::endl;
}

// ���ҵ�¼
bool Seller::login() {
    std::string username, password;

    std::cout << "�����������û���: ";
    std::getline(std::cin, username);

    std::cout << "����������: ";
    std::getline(std::cin, password);

  

    std::ifstream infile("sellers.txt");  // ���ļ��Զ�ȡ����

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
            std::cout << "��¼�ɹ���" << std::endl;
            return true;
        }
        else {
            std::cout << "��¼ʧ�ܣ�" << std::endl;
            return false;
        }
    }
    else {
        std::cout << "�޷����ļ���" << std::endl;
        return false;
    }
}