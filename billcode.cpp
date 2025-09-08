#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Item {
public:
    int id;
    string name;
    double price;
    int stock;

    Item(int id, string name, double price, int stock)
        : id(id), name(name), price(price), stock(stock) {}
};

class Bill {
public:
    int billID;
    string customerName;
    double total = 0;
    vector<string> details;

    Bill(int id, string name) : billID(id), customerName(name) {}

    void addItem(Item &item, int qty) {
        if (qty <= 0) {
            throw runtime_error("Quantity must be greater than 0.");
        }
        if (qty > item.stock) {
            throw runtime_error("Not enough stock.");
        }

        item.stock -= qty;
        double itemTotal = item.price * qty;
        total += itemTotal;

        details.push_back(item.name + " x " + to_string(qty) + " = Rs." + to_string(itemTotal));
    }

    void display() {
        cout << "\n--- Bill #" << billID << " ---\n";
        cout << "Customer: " << customerName << "\n";
        for (auto &d : details) {
            cout << d << endl;
        }
        cout << "Total: Rs." << total << "\n";
    }

    void saveToFile() {
        ofstream fout("customer_bills.txt", ios::app);
        fout << "Bill #" << billID << " | Customer: " << customerName << " | Total: Rs." << total << "\n";
        fout.close();
    }
};

void viewPreviousBills() {
    ifstream fin("customer_bills.txt");
    if (!fin) {
        cout << "No previous bills found.\n";
        return;
    }

    string line;
    cout << "\n--- Previous Bills ---\n";
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

int main() {
    try {
        viewPreviousBills();

        vector<Item> inventory = {
            {1, "Pen", 20, 10},
            {2, "Pencil", 10, 5},
            {3, "Notebook", 50, 3}
        };

        cout << "\nAvailable Items:\n";
        for (auto &item : inventory) {
            cout << item.id << ". " << item.name << " (Rs." << item.price << ", Stock: " << item.stock << ")\n";
        }

        Bill bill(1, "Prathamesh");

        while (true) {
            int itemId, quantity;

            cout << "\nEnter item ID to buy (0 to finish): ";
            cin >> itemId;

            if (itemId == 0) break;

            cout << "Enter quantity: ";
            cin >> quantity;

            bool found = false;
            for (auto &item : inventory) {
                if (item.id == itemId) {
                    bill.addItem(item, quantity);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Item not found. Please try again.\n";
            }
        }

        if (bill.total == 0) {
            cout << "No items were purchased.\n";
        } else {
            bill.display();
            bill.saveToFile();
            cout << "Bill saved to file.\n";
        }

    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
