#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// 定义元件类
class Component {
public:
    Component();
    Component(string name, string type, string package);
    string getName() const;
    string getType() const;
    string getPackage() const;
private:
    string name_;
    string type_;
    string package_;
};

// 定义入库批次类
class Batch {
public:
    Batch();
    int getQuantity(Component component) const;

    Batch(string id);
    void addComponent(Component component, int quantity);
    void removeComponent(Component component, int quantity);
    void printBatch() const;
    void printComponent(Component component) const;

    string id_;
    vector<Component> components_;
    vector<int> quantities_;
};

// 定义存储位置类
class Storage {
public:
    Storage();
    Storage(string id, int capacity);
    void addBatch(Batch batch);
    void removeBatch(Batch batch);
    void printStorage() const;
    int getQuantity(Component component) const;

    string id_;
    int capacity_;
    vector<Batch> batches_;
};

// 定义元件仓库类
class ComponentWarehouse {
public:
    ComponentWarehouse();
    void addComponent(Component component);
    void removeComponent(Component component);
    void addStorage(Storage storage);
    void removeStorage(Storage storage);
    void addBatch(Batch batch);
    void removeBatch(Batch batch);
    void addRecord(string operation, Component component, int quantity, Batch batch, Storage storage);
    void printComponents() const;
    void printBatches() const;
    void printStorages() const;
    void printRecords() const;

    vector<Component> components_;
    vector<Storage> storages_;
    vector<Batch> batches_;
    vector<string> records_;
};

// 定义文件操作类
class FileOperator {
public:
    FileOperator();
    void exportData(ComponentWarehouse warehouse, string filename) const;
    ComponentWarehouse importData(string filename) const;
};


int main() {
    ComponentWarehouse warehouse;
    FileOperator fileOperator;

    int choice = 0;
    while (true) {
        cout << "Please select an operation: " << endl;
        cout << "1. Add component" << endl;
        cout << "2. Remove component" << endl;
        cout << "3. Add storage" << endl;
        cout << "4. Remove storage" << endl;
        cout << "5. Add batch" << endl;
        cout << "6. Remove batch" << endl;
        cout << "7. Print components" << endl;
        cout << "8. Print storages" << endl;
        cout << "9. Print batches" << endl;
        cout << "10. Print records" << endl;
        cout << "0. Exit" << endl;

        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Goodbye!" << endl;
            return 0;
        case 1: {
            string name, type, package;
            cout << "Enter component name: ";
            cin >> name;
            cout << "Enter component type: ";
            cin >> type;
            cout << "Enter component package: ";
            cin >> package;
            Component component(name, type, package);
            warehouse.addComponent(component);
            cout << "Component added successfully!" << endl;
            break;
        }
        case 2: {
            string name, type, package;
            cout << "Enter component name: ";
            cin >> name;
            cout << "Enter component type: ";
            cin >> type;
            cout << "Enter component package: ";
            cin >> package;
            Component component(name, type, package);
            warehouse.removeComponent(component);
            cout << "Component removed successfully!" << endl;
            break;
        }
        case 3: {
            string id;
            int capacity;
            cout << "Enter storage id: ";
            cin >> id;
            cout << "Enter storage capacity: ";
            cin >> capacity;
            Storage storage(id, capacity);
            warehouse.addStorage(storage);
            cout << "Storage added successfully!" << endl;
            break;
        }
        case 4: {
            string id;
            int capacity;
            cout << "Enter storage id: ";
            cin >> id;
            cout << "Enter storage capacity: ";
            cin >> capacity;
            Storage storage(id, capacity);
            warehouse.removeStorage(storage);
            cout << "Storage removed successfully!" << endl;
            break;
        }
        case 5: {
            string id;
            cout << "Enter batch id: ";
            cin >> id;
            Batch batch(id);

            string component_name, component_type, component_package;
            int quantity;
            cout << "Enter component name: ";
            cin >> component_name;
            cout << "Enter component type: ";
            cin >> component_type;
            cout << "Enter component package: ";
            cin >> component_package;
            cout << "Enter component quantity: ";
            cin >> quantity;
            Component component(component_name, component_type, component_package);

            string storage_id;
            cout << "Enter storage id: ";
            cin >> storage_id;
            Storage storage(storage_id, 0);

            batch.addComponent(component, quantity);
            warehouse.addBatch(batch);
            warehouse.addRecord("Add batch", component, quantity, batch, storage);
            cout << "Batch added successfully!" << endl;
            break;
        }
        case 6:{
            // 出库
            string id;
            cout << "Enter batch id: ";
            cin >> id;
            Batch batch(id);

            string component_name, component_type, component_package;
            int quantity;
            cout << "Enter component name:" << endl;
            cin >> component_name;
            cout << "Enter component type:" << endl;
            cin >> component_type;
            cout << "Enter component package:" << endl;
            cin >> component_package;
            Component component(component_name, component_type, component_package);
            cout << "Enter component quantity:" << endl;
            cin >> quantity;
            for (Storage& storage : warehouse.storages_) {
                int currentQuantity = storage.getQuantity(component);
                if (currentQuantity >= quantity) {
                    for (Batch& batch : storage.batches_) {
                        int batchQuantity = batch.getQuantity(component);
                        if (batchQuantity > 0) {
                            int toRemove = min(batchQuantity, quantity);
                            batch.removeComponent(component, toRemove);
                            quantity -= toRemove;
                            if (quantity == 0) {
                                cout << "Batch removed successfully!" << endl;
                                warehouse.addRecord("Remove batch", component, toRemove, batch, storage);
                                return 0;
                            }
                        }
                    }
                }
            }
            cout << "Batch removed unsuccessfully!" << endl;
            break;
        }
        case 7: {
            cout << "Please enter the batch ID: ";
            string batchId;
            cin >> batchId;
            Batch batch(batchId);
            cout << "Please enter the component name: ";
            string componentName;
            cin >> componentName;
            cout << "Please enter the component type: ";
            string componentType;
            cin >> componentType;
            cout << "Please enter the component package: ";
            string componentPackage;
            cin >> componentPackage;
            Component component(componentName, componentType, componentPackage);
            int quantity;
            cout << "Please enter the quantity of the component: ";
            cin >> quantity;
            batch.addComponent(component, quantity);
            warehouse.addBatch(batch);
            warehouse.addRecord("Add Batch", component, quantity, batch, Storage());
            break;
        }
        case 8: {
            cout << "Please enter the batch ID: ";
            string batchId;
            cin >> batchId;
            Batch batch(batchId);
            cout << "Please enter the component name: ";
            string componentName;
            cin >> componentName;
            cout << "Please enter the component type: ";
            string componentType;
            cin >> componentType;
            cout << "Please enter the component package: ";
            string componentPackage;
            cin >> componentPackage;
            Component component(componentName, componentType, componentPackage);
            int quantity;
            cout << "Please enter the quantity of the component: ";
            cin >> quantity;
            batch.removeComponent(component, quantity);
            warehouse.removeBatch(batch);
            warehouse.addRecord("Remove Batch", component, quantity, batch, Storage());
            break;
        }
        case 9: {
            cout << "Please enter the component name: ";
            string componentName;
            cin >> componentName;
            cout << "Please enter the component type: ";
            string componentType;
            cin >> componentType;
            cout << "Please enter the component package: ";
            string componentPackage;
            cin >> componentPackage;
            Component component(componentName, componentType, componentPackage);
            cout << "Please enter the storage ID: ";
            string storageId;
            cin >> storageId;
            Storage storage(storageId, 0);
            cout << "Please enter the capacity of the storage: ";
            int capacity;
            cin >> capacity;
            storage = Storage(storageId, capacity);
            warehouse.addStorage(storage);
            warehouse.addRecord("Add Storage", component, 0, Batch(""), storage);
            break;
        }
        case 10: {
            cout << "Please enter the storage ID: ";
            string storageId;
            cin >> storageId;
            Storage storage(storageId, 0);
            warehouse.removeStorage(storage);
            warehouse.addRecord("Remove Storage", Component("", "", ""), 0, Batch(""), storage);
            break;
        }
        default:
            cout << "Error！Please re-enter" << endl;
            break;
        }
    }
}
