
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// ����Ԫ����
class Component {
public:
    string name; // Ԫ������
    string type; // Ԫ������
    string package; // Ԫ����װ����
    int quantity; // �����

    Component(string n, string t, string p, int q) { // ���캯��
        name = n;
        type = t;
        package = p;
        quantity = q;
    }
};

// ��������
class Inventory {
public:
    string location; // �洢λ��
    int capacity; // �������
    int quantity; // ��ǰ�����

    Inventory(string l, int c, int q) { // ���캯��
        location = l;
        capacity = c;
        quantity = q;
    }
};

// ���������¼��
class Record {
public:
    string component_name; // Ԫ������
    string location; // �洢λ��
    int quantity; // ���������
    string type; // ��������ͣ�������⣩
    string batch_number; // ���κ�

    Record(string n, string l, int q, string t, string b) { // ���캯��
        component_name = n;
        location = l;
        quantity = q;
        type = t;
        batch_number = b;
    }
};

vector<Component> components; // Ԫ���б�
vector<Inventory> inventories; // ����б�
vector<Record> records; // ������¼�б�

void addComponent(); // ����Ԫ��
void removeComponent(); // ɾ��Ԫ��
void addInventory(); // �������
void removeInventory(); // ɾ�����
void updateInventoryCapacity(); // �޸Ŀ���������
void addStock(); // ���
void removeStock(); // ����
void displayRecords(); // ��ʾ������¼
void searchComponents(); // ��ѯԪ��
void exportData(); // ��������
void importData(); // ��������
void menu()
{
    // ��ʾ���˵�
    printf("*******     1.����Ԫ��        *******\n");
    printf("*******     2.ɾ��Ԫ��        *******\n");
    printf("*******     3.�������        *******\n");
    printf("*******     4.�¿��        *******\n");
    printf("*******     5.�޸Ŀ���������*******\n");
    printf("*******     6.Ԫ�����        *******\n");
    printf("*******     7.Ԫ������        *******\n");
    printf("*******     8.��ʾ������¼  *******\n");
    printf("*******     9.��ѯԪ����Ϣ    *******\n");
    printf("*******     10.��������       *******\n");
    printf("*******     11.��������       *******\n");
    printf("��ѡ�����:");

 
}
// ����Ԫ��
void addComponent() {
    string name, type, package;
    int quantity;
    cout << "������Ԫ�����ƣ�";
    cin >> name;
    cout << "������Ԫ�����ͣ�";
    cin >> type;
    cout << "������Ԫ����װ���ͣ�";
    cin >> package;
    cout << "������������";
    cin >> quantity;
    Component component(name, type, package, quantity);
    components.push_back(component);
    cout << "����Ԫ���ɹ���" << endl;
}
// ɾ��Ԫ��
void removeComponent() {
    string name;
    cout << "������Ҫɾ����Ԫ�����ƣ�";
    cin >> name;
    for (auto iter = components.begin(); iter != components.end(); iter++) {
        if (iter->name == name) {
            components.erase(iter);
            cout << "Ԫ��ɾ���ɹ���" << endl;
            return;
        }
    }
    cout << "Ԫ�������ڣ�" << endl;
}
// �������
void addInventory() {
    string location;
    int capacity, quantity;
    cout << "��������洢λ�ã�";
    cin >> location;
    cout << "�����������������";
    cin >> capacity;
    cout << "�������浱ǰ�������";
    cin >> quantity;
    Inventory inventory(location, capacity, quantity);
    inventories.push_back(inventory);
    cout << "�������ɹ���" << endl;
}
void removeInventory() {
    string location;
    cout << "������Ҫɾ���Ŀ��Ĵ洢λ�ã�" << endl;
    cin >> location;

    // ���ҿ��λ���Ƿ����
    bool found = false;
    int index = 0;
    for (int i = 0; i < inventories.size(); i++) {
        if (inventories[i].location == location) {
            found = true;
            index = i;
            break;
        }
    }

    // ������λ�ò����ڣ����������ʾ��Ϣ
    if (!found) {
        cout << "���λ�ò����ڣ����������룡" << endl;
        return;
    }

    // ɾ�����
    inventories.erase(inventories.begin() + index);

    // ����ɹ�ɾ����Ϣ
    cout << "���ɾ���ɹ���" << endl;
}

// �޸Ŀ���������
void updateInventoryCapacity() {
    // ��ʾ����б�
    cout << "��ѡ��Ҫ�޸������Ŀ�棺" << endl;
    for (int i = 0; i < inventories.size(); i++) {
        cout << i + 1 << ". " << inventories[i].location << "����ǰ������" << inventories[i].capacity << "��" << endl;
    }

    int choice;
    cin >> choice;

    if (choice < 1 || choice > inventories.size()) {
        cout << "��Ч��ѡ�" << endl;
        return;
    }

    // �޸Ŀ���������
    cout << "�������µĿ��������" << endl;
    int new_capacity;
    cin >> new_capacity;

    if (new_capacity < inventories[choice - 1].quantity) {
        cout << "��������Ѿ��������µ�������" << endl;
        return;
    }

    inventories[choice - 1].capacity = new_capacity;
    cout << "��������ѳɹ��޸�Ϊ " << new_capacity << "��" << endl;
}

void addStock() {
    string component_name, location, batch_number;
    int quantity;

    // ����������Ϣ
    cout << "������Ԫ�����ƣ�" << endl;
    cin >> component_name;

    cout << "������洢λ�ã�" << endl;
    cin >> location;

    cout << "���������κţ�" << endl;
    cin >> batch_number;

    cout << "���������������" << endl;
    cin >> quantity;

    // ����Ԫ���Ƿ����
    bool found = false;
    for (auto& component : components) {
        if (component.name == component_name) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Ԫ�������ڣ�" << endl;
        return;
    }

    // ���ҿ��λ��
    found = false;
    Inventory* inventory = nullptr;
    for (auto& inv : inventories) {
        if (inv.location == location) {
            found = true;
            inventory = &inv;
            break;
        }
    }

    // ������λ�ò����ڣ����½����λ��
    if (!found) {
        int capacity;
        cout << "���������������" << endl;
        cin >> capacity;

        Inventory new_inventory(location, capacity, 0);
        inventories.push_back(new_inventory);
        inventory = &inventories.back();
    }

    // ����������Ƿ��㹻
    if (inventory->quantity + quantity > inventory->capacity) {
        cout << "����������㣡" << endl;
        return;
    }

    // ���¿������
    inventory->quantity += quantity;

    // ��¼����¼
    Record record(component_name, location, quantity, "���", batch_number);
    records.push_back(record);

    // ����Ԫ���������
    for (auto& component : components) {
        if (component.name == component_name) {
            component.quantity += quantity;
            break;
        }
    }

    cout << "���ɹ���" << endl;
}
void removeStock() {
    string component_name, location, batch_number;
    int quantity;
    // ��ȡ�û�����
    cout << "���������Ԫ�������ƣ�";
    cin >> component_name;
    cout << "������洢λ�ã�";
    cin >> location;
    cout << "���������κţ�";
    cin >> batch_number;
    cout << "���������������";
    cin >> quantity;

    // ���ҿ��
    int index = -1;
    for (int i = 0; i < inventories.size(); i++) {
        if (inventories[i].location == location) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "δ�ҵ���棬��ȷ�ϴ洢λ���Ƿ���ȷ��" << endl;
        return;
    }

    // ���������
    if (inventories[index].quantity < quantity) {
        cout << "��治�㣬��ȷ�ϳ��������Ƿ���ȷ��" << endl;
        return;
    }

    // ���¿������
    inventories[index].quantity -= quantity;

    // ��ӳ����¼
    Record record(component_name, location, quantity, "����", batch_number);
    records.push_back(record);

    cout << "�����¼����ӡ�" << endl;

}
//������¼
void displayRecords() {
    // ��ȡ�û������Ԫ�����ƺͿ��λ��
    string component_name, location;
    cout << "������Ԫ�����ƺͿ��λ�ã��ÿո�ָ���" << endl;
    cin >> component_name >> location;

    // ����������¼�б��ҵ���ӦԪ���Ϳ��ļ�¼
    bool found = false;
    for (const Record& record : records) {
        if (record.component_name == component_name && record.location == location) {
            found = true;
            cout << record.component_name << "\t" << record.location << "\t" << record.quantity << "\t" << record.type << "\t" << record.batch_number << endl;
        }
    }

    // �����ʾ��Ϣ
    if (!found) {
        cout << "�Ҳ�����Ԫ���ڸÿ���еĳ�����¼��" << endl;
    }
}
//����
void searchComponents() {
    int choice;
    cout << "��ѡ���ѯ������" << endl;
    cout << "1. Ԫ�����ͺͷ�װ����" << endl;
    cout << "2. �������κ�" << endl;
    cout << "3. ���Ĵ洢λ��" << endl;
    cin >> choice;

    switch (choice) {
    case 1: {
        string component_type, component_package;
        cout << "������Ԫ�����ͺͷ�װ���ͣ��ÿո�ָ���" << endl;
        cin >> component_type >> component_package;
        cout << "Ԫ���б�" << endl;
        for (const auto& component : components) {
            if (component.type == component_type && component.package == component_package) {
                cout << component.name << " " << component.type << " " << component.package << " " << component.quantity << endl;
            }
        }
        break;
    }
    case 2: {
        string batch_number;
        cout << "�������������κţ�" << endl;
        cin >> batch_number;
        cout << "Ԫ���б�" << endl;
        for (const auto& record : records) {
            if (record.batch_number == batch_number) {
                for (const auto& component : components) {
                    if (component.name == record.component_name) {
                        cout << component.name << " " << component.type << " " << component.package << " " << component.quantity << endl;
                        break;
                    }
                }
                break;
            }
        }
        break;
    }
    case 3: {
        string location;
        cout << "��������Ĵ洢λ�ã�" << endl;
        cin >> location;
        cout << "Ԫ���б�" << endl;
        for (const auto& inventory : inventories) {
            if (inventory.location == location) {
                for (const auto& component : components) {
                    if (component.package == inventory.location) {
                        cout << component.name << " " << component.type << " " << component.package << " " << component.quantity << endl;
                    }
                }
            }
        }
        break;
    }
    default:
        cout << "����������������롣" << endl;
        break;
    }
}
//������д��data.txt��
void exportData() {
    ofstream outfile("data.txt"); // ������ļ���
    if (!outfile) { // �ļ���ʧ��
        cout << "�޷����ļ�" << endl;
        return;
    }

    // д��Ԫ���б�
    outfile << "Ԫ���б�" << endl;
    outfile << "Ԫ������\tԪ������\tԪ����װ����\t�����" << endl;
    for (const auto& component : components) {
        outfile << component.name << "\t" << component.type << "\t" << component.package << "\t" << component.quantity << endl;
    }
    outfile << endl;

    // д�����б�
    outfile << "����б�" << endl;
    outfile << "�洢λ��\t�������\t��ǰ�����" << endl;
    for (const auto& inventory : inventories) {
        outfile << inventory.location << "\t" << inventory.capacity << "\t" << inventory.quantity << endl;
    }
    outfile << endl;

    // д�������¼�б�
    outfile << "������¼�б�" << endl;
    outfile << "Ԫ������\t�洢λ��\t���������\t���������\t���κ�" << endl;
    for (const auto& record : records) {
        outfile << record.component_name << "\t" << record.location << "\t" << record.quantity << "\t" << record.type << "\t" << record.batch_number << endl;
    }
    outfile << endl;

    // �ر�����ļ���
    outfile.close();
    cout << "�����ѳɹ��������ļ�data.txt" << endl;
}
void importData() {
    ifstream infile("data.txt"); // �������ļ���
    if (!infile) { // �ļ���ʧ��
        cout << "�޷����ļ�" << endl;
        return;
    }

    // ��ȡԪ���б�
    string line;
    getline(infile, line); // ����������
    while (getline(infile, line)) {
        istringstream iss(line);
        string name, type, package;
        int quantity;
        iss >> name >> type >> package >> quantity;
        components.push_back({ name, type, package, quantity });
    }

    // ��ȡ����б�
    getline(infile, line); // ����������
    while (getline(infile, line)) {
        istringstream iss(line);
        string location;
        int capacity, quantity;
        iss >> location >> capacity >> quantity;
        inventories.push_back({ location, capacity, quantity });
    }

    // ��ȡ������¼�б�
    getline(infile, line); // ����������
    while (getline(infile, line)) {
        istringstream iss(line);
        string component_name, location, type, batch_number;
        int quantity;
        iss >> component_name >> location >> quantity >> type >> batch_number;
        records.push_back({ component_name, location, quantity, type, batch_number });
    }

    // �ر������ļ���
    infile.close();
    cout << "�����ѳɹ����뵽������" << endl;
}

int main() {
    int choice;
    do {
        menu();

        cin >> choice;

        switch (choice) {
        case 1:
            addComponent();
            break;
        case 2:
            removeComponent();
            break;
        case 3:
            addInventory();
            break;
        case 4:
            removeInventory();
            break;
        case 5:
            updateInventoryCapacity();
            break;
        case 6:
            addStock();
            break;
        case 7:
            removeStock();
            break;
        case 8:
            displayRecords();
            break;
        case 9:
            searchComponents();
            break;
        case 10:
            exportData();
        case 11:
            importData();
            break;
        default :
            cout << "������������³��룺";
            break;
        }

    } while (choice);

}