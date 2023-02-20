
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// 定义元件类
class Component {
public:
    string name; // 元件名称
    string type; // 元件类型
    string package; // 元件封装类型
    int quantity; // 库存量

    Component(string n, string t, string p, int q) { // 构造函数
        name = n;
        type = t;
        package = p;
        quantity = q;
    }
};

// 定义库存类
class Inventory {
public:
    string location; // 存储位置
    int capacity; // 最大容量
    int quantity; // 当前库存量

    Inventory(string l, int c, int q) { // 构造函数
        location = l;
        capacity = c;
        quantity = q;
    }
};

// 定义出入库记录类
class Record {
public:
    string component_name; // 元件名称
    string location; // 存储位置
    int quantity; // 出入库数量
    string type; // 出入库类型（入库或出库）
    string batch_number; // 批次号

    Record(string n, string l, int q, string t, string b) { // 构造函数
        component_name = n;
        location = l;
        quantity = q;
        type = t;
        batch_number = b;
    }
};

vector<Component> components; // 元件列表
vector<Inventory> inventories; // 库存列表
vector<Record> records; // 出入库记录列表

void addComponent(); // 新增元件
void removeComponent(); // 删除元件
void addInventory(); // 新增库存
void removeInventory(); // 删除库存
void updateInventoryCapacity(); // 修改库存最大容量
void addStock(); // 入库
void removeStock(); // 出库
void displayRecords(); // 显示出入库记录
void searchComponents(); // 查询元件
void exportData(); // 导出数据
void importData(); // 导入数据
void menu()
{
    // 显示主菜单
    printf("*******     1.新增元件        *******\n");
    printf("*******     2.删除元件        *******\n");
    printf("*******     3.新增库存        *******\n");
    printf("*******     4.新库存        *******\n");
    printf("*******     5.修改库存最大容量*******\n");
    printf("*******     6.元件入库        *******\n");
    printf("*******     7.元件出库        *******\n");
    printf("*******     8.显示出入库记录  *******\n");
    printf("*******     9.查询元件信息    *******\n");
    printf("*******     10.导出数据       *******\n");
    printf("*******     11.导入数据       *******\n");
    printf("请选择操作:");

 
}
// 新增元件
void addComponent() {
    string name, type, package;
    int quantity;
    cout << "请输入元件名称：";
    cin >> name;
    cout << "请输入元件类型：";
    cin >> type;
    cout << "请输入元件封装类型：";
    cin >> package;
    cout << "请输入库存量：";
    cin >> quantity;
    Component component(name, type, package, quantity);
    components.push_back(component);
    cout << "新增元件成功！" << endl;
}
// 删除元件
void removeComponent() {
    string name;
    cout << "请输入要删除的元件名称：";
    cin >> name;
    for (auto iter = components.begin(); iter != components.end(); iter++) {
        if (iter->name == name) {
            components.erase(iter);
            cout << "元件删除成功！" << endl;
            return;
        }
    }
    cout << "元件不存在！" << endl;
}
// 新增库存
void addInventory() {
    string location;
    int capacity, quantity;
    cout << "请输入库存存储位置：";
    cin >> location;
    cout << "请输入库存最大容量：";
    cin >> capacity;
    cout << "请输入库存当前库存量：";
    cin >> quantity;
    Inventory inventory(location, capacity, quantity);
    inventories.push_back(inventory);
    cout << "新增库存成功！" << endl;
}
void removeInventory() {
    string location;
    cout << "请输入要删除的库存的存储位置：" << endl;
    cin >> location;

    // 查找库存位置是否存在
    bool found = false;
    int index = 0;
    for (int i = 0; i < inventories.size(); i++) {
        if (inventories[i].location == location) {
            found = true;
            index = i;
            break;
        }
    }

    // 如果库存位置不存在，输出错误提示信息
    if (!found) {
        cout << "库存位置不存在，请重新输入！" << endl;
        return;
    }

    // 删除库存
    inventories.erase(inventories.begin() + index);

    // 输出成功删除信息
    cout << "库存删除成功！" << endl;
}

// 修改库存最大容量
void updateInventoryCapacity() {
    // 显示库存列表
    cout << "请选择要修改容量的库存：" << endl;
    for (int i = 0; i < inventories.size(); i++) {
        cout << i + 1 << ". " << inventories[i].location << "（当前容量：" << inventories[i].capacity << "）" << endl;
    }

    int choice;
    cin >> choice;

    if (choice < 1 || choice > inventories.size()) {
        cout << "无效的选项。" << endl;
        return;
    }

    // 修改库存最大容量
    cout << "请输入新的库存容量：" << endl;
    int new_capacity;
    cin >> new_capacity;

    if (new_capacity < inventories[choice - 1].quantity) {
        cout << "库存数量已经超过了新的容量。" << endl;
        return;
    }

    inventories[choice - 1].capacity = new_capacity;
    cout << "库存容量已成功修改为 " << new_capacity << "。" << endl;
}

void addStock() {
    string component_name, location, batch_number;
    int quantity;

    // 输入出入库信息
    cout << "请输入元件名称：" << endl;
    cin >> component_name;

    cout << "请输入存储位置：" << endl;
    cin >> location;

    cout << "请输入批次号：" << endl;
    cin >> batch_number;

    cout << "请输入入库数量：" << endl;
    cin >> quantity;

    // 查找元件是否存在
    bool found = false;
    for (auto& component : components) {
        if (component.name == component_name) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "元件不存在！" << endl;
        return;
    }

    // 查找库存位置
    found = false;
    Inventory* inventory = nullptr;
    for (auto& inv : inventories) {
        if (inv.location == location) {
            found = true;
            inventory = &inv;
            break;
        }
    }

    // 如果库存位置不存在，则新建库存位置
    if (!found) {
        int capacity;
        cout << "请输入最大容量：" << endl;
        cin >> capacity;

        Inventory new_inventory(location, capacity, 0);
        inventories.push_back(new_inventory);
        inventory = &inventories.back();
    }

    // 检查库存容量是否足够
    if (inventory->quantity + quantity > inventory->capacity) {
        cout << "库存容量不足！" << endl;
        return;
    }

    // 更新库存数量
    inventory->quantity += quantity;

    // 记录入库记录
    Record record(component_name, location, quantity, "入库", batch_number);
    records.push_back(record);

    // 更新元件库存数量
    for (auto& component : components) {
        if (component.name == component_name) {
            component.quantity += quantity;
            break;
        }
    }

    cout << "入库成功！" << endl;
}
void removeStock() {
    string component_name, location, batch_number;
    int quantity;
    // 获取用户输入
    cout << "请输入出库元件的名称：";
    cin >> component_name;
    cout << "请输入存储位置：";
    cin >> location;
    cout << "请输入批次号：";
    cin >> batch_number;
    cout << "请输入出库数量：";
    cin >> quantity;

    // 查找库存
    int index = -1;
    for (int i = 0; i < inventories.size(); i++) {
        if (inventories[i].location == location) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "未找到库存，请确认存储位置是否正确。" << endl;
        return;
    }

    // 检查库存数量
    if (inventories[index].quantity < quantity) {
        cout << "库存不足，请确认出库数量是否正确。" << endl;
        return;
    }

    // 更新库存数量
    inventories[index].quantity -= quantity;

    // 添加出库记录
    Record record(component_name, location, quantity, "出库", batch_number);
    records.push_back(record);

    cout << "出库记录已添加。" << endl;

}
//出入库记录
void displayRecords() {
    // 获取用户输入的元件名称和库存位置
    string component_name, location;
    cout << "请输入元件名称和库存位置，用空格分隔：" << endl;
    cin >> component_name >> location;

    // 遍历出入库记录列表，找到对应元件和库存的记录
    bool found = false;
    for (const Record& record : records) {
        if (record.component_name == component_name && record.location == location) {
            found = true;
            cout << record.component_name << "\t" << record.location << "\t" << record.quantity << "\t" << record.type << "\t" << record.batch_number << endl;
        }
    }

    // 输出提示信息
    if (!found) {
        cout << "找不到该元件在该库存中的出入库记录。" << endl;
    }
}
//查找
void searchComponents() {
    int choice;
    cout << "请选择查询条件：" << endl;
    cout << "1. 元件类型和封装类型" << endl;
    cout << "2. 入库的批次号" << endl;
    cout << "3. 库存的存储位置" << endl;
    cin >> choice;

    switch (choice) {
    case 1: {
        string component_type, component_package;
        cout << "请输入元件类型和封装类型，用空格分隔：" << endl;
        cin >> component_type >> component_package;
        cout << "元件列表：" << endl;
        for (const auto& component : components) {
            if (component.type == component_type && component.package == component_package) {
                cout << component.name << " " << component.type << " " << component.package << " " << component.quantity << endl;
            }
        }
        break;
    }
    case 2: {
        string batch_number;
        cout << "请输入入库的批次号：" << endl;
        cin >> batch_number;
        cout << "元件列表：" << endl;
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
        cout << "请输入库存的存储位置：" << endl;
        cin >> location;
        cout << "元件列表：" << endl;
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
        cout << "输入错误，请重新输入。" << endl;
        break;
    }
}
//将数据写入data.txt中
void exportData() {
    ofstream outfile("data.txt"); // 打开输出文件流
    if (!outfile) { // 文件打开失败
        cout << "无法打开文件" << endl;
        return;
    }

    // 写入元件列表
    outfile << "元件列表" << endl;
    outfile << "元件名称\t元件类型\t元件封装类型\t库存量" << endl;
    for (const auto& component : components) {
        outfile << component.name << "\t" << component.type << "\t" << component.package << "\t" << component.quantity << endl;
    }
    outfile << endl;

    // 写入库存列表
    outfile << "库存列表" << endl;
    outfile << "存储位置\t最大容量\t当前库存量" << endl;
    for (const auto& inventory : inventories) {
        outfile << inventory.location << "\t" << inventory.capacity << "\t" << inventory.quantity << endl;
    }
    outfile << endl;

    // 写入出入库记录列表
    outfile << "出入库记录列表" << endl;
    outfile << "元件名称\t存储位置\t出入库数量\t出入库类型\t批次号" << endl;
    for (const auto& record : records) {
        outfile << record.component_name << "\t" << record.location << "\t" << record.quantity << "\t" << record.type << "\t" << record.batch_number << endl;
    }
    outfile << endl;

    // 关闭输出文件流
    outfile.close();
    cout << "数据已成功导出到文件data.txt" << endl;
}
void importData() {
    ifstream infile("data.txt"); // 打开输入文件流
    if (!infile) { // 文件打开失败
        cout << "无法打开文件" << endl;
        return;
    }

    // 读取元件列表
    string line;
    getline(infile, line); // 跳过标题行
    while (getline(infile, line)) {
        istringstream iss(line);
        string name, type, package;
        int quantity;
        iss >> name >> type >> package >> quantity;
        components.push_back({ name, type, package, quantity });
    }

    // 读取库存列表
    getline(infile, line); // 跳过标题行
    while (getline(infile, line)) {
        istringstream iss(line);
        string location;
        int capacity, quantity;
        iss >> location >> capacity >> quantity;
        inventories.push_back({ location, capacity, quantity });
    }

    // 读取出入库记录列表
    getline(infile, line); // 跳过标题行
    while (getline(infile, line)) {
        istringstream iss(line);
        string component_name, location, type, batch_number;
        int quantity;
        iss >> component_name >> location >> quantity >> type >> batch_number;
        records.push_back({ component_name, location, quantity, type, batch_number });
    }

    // 关闭输入文件流
    infile.close();
    cout << "数据已成功导入到程序中" << endl;
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
            cout << "输入错误请重新出入：";
            break;
        }

    } while (choice);

}