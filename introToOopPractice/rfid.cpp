#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Rfid {

    string item;
    int quantity;

public:

    Rfid(string item, int num = 1): item(item), quantity(num) {}

    string getItem() const {return item;}
    int getQuantity() const {return quantity;}
    void incrementQuantity() {quantity++;}
};

class ShippingContainer {

    int id;

public:

    ShippingContainer() {}
    ShippingContainer(int cont): id(cont) {}

    virtual vector<string> getManifest() = 0;
    double getID() const {return id;}
    void setID(int id) {this->id = id;}
};

class ManualShippingContainer: public ShippingContainer {

    vector<string> inventory;

public:

    ManualShippingContainer(): ShippingContainer() {}
    ManualShippingContainer(int contID): ShippingContainer(contID) {}
    ManualShippingContainer(int contID, vector<string> goods): ShippingContainer(contID), inventory(goods) {}

    virtual void addManifest(string manifest) {inventory.push_back(manifest);}
    virtual vector<string> getManifest() {return inventory;}
};

class RfidContainer: public ShippingContainer {

    vector<Rfid> inventory;

public:

    void add(Rfid el);
    virtual vector<string> getManifest();

    friend ostream& operator<<(ostream& o, const RfidContainer& r);
};
void RfidContainer::add(Rfid el) {

    bool alreadyIn = false;

    for (auto rfid: inventory) {

        if (rfid.getItem() == el.getItem()) {
            rfid.incrementQuantity();
            alreadyIn = true;
        }
    }

    if (!alreadyIn) {
        inventory.push_back(el);
    }
}
vector<string> RfidContainer::getManifest() {

    string temp;
    vector<string> manifest;
    for (auto rfid: inventory) {
        temp = to_string(rfid.getQuantity()) + " " + rfid.getItem();
        manifest.push_back(temp);
    }

    return manifest;
}
ostream& operator<<(ostream& o, const RfidContainer& r) {

    for (const auto& el: r.inventory) {
        o << el.getItem() << ": " << el.getQuantity() << endl;
    }

    return o;
}

void openInputFile(ifstream& inFile);

int main () {

    ifstream inFile;
    openInputFile(inFile);
    int quantity;
    string goods;

    RfidContainer everGiven;

    while (inFile >> quantity) {
        inFile.ignore(1);
        getline(inFile, goods);
        Rfid rfid(goods, quantity);
        everGiven.add(rfid);
    }

    inFile.close();

    cout << "Manifests:" << endl;
    vector<string> manifests = everGiven.getManifest();
    for (const auto& el: manifests) {
        cout << el << " " << endl;
    }

    cout << "\nOutput operator:" << endl;
    cout << everGiven;

    return 0;
}

void openInputFile(ifstream& inFile) {
    string filename;
    cout << "Enter the file name:" << endl;
    cin >> filename;
    inFile.open(filename);
    while (!inFile) {
        cout << "Input file failed to open" << endl;
        cout << "Enter the file name:" << endl;
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}