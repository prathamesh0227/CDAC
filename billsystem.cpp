#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

const int MAX_ITEMS = 100;
const string BILL_FILE = "bills.txt";

// Item class definition
class Item
{
public:
    int itemID;
    string itemName;
    double price;
    int stockQuantity;

    Item(int id = 0, string name = "", double p = 0.0, int quantity = 0)
    {
        if (p < 0)
            throw invalid_argument("Price cannot be negative.");
        if (quantity < 0)
            throw invalid_argument("Quantity cannot be negative.");
        itemID = id;
        itemName = name;
        price = p;
        stockQuantity = quantity;
    }

    void displayItem() const
    {
        cout << "Item ID: " << itemID << ", Name: " << itemName
             << ", Price: $" << price << ", Quantity: " << stockQuantity << endl;
    }

    // Serialize item as string
    string serialize() const
    {
        return to_string(itemID) + "," + itemName + "," + to_string(price) + "," + to_string(stockQuantity);
    }

    // Deserialize from string
    static Item deserialize(const string &data)
    {
        istringstream iss(data);
        string token;
        int id;
        string name;
        double price;
        int quantity;

        getline(iss, token, ',');
        id = stoi(token);
        getline(iss, name, ',');
        getline(iss, token, ',');
        price = stod(token);
        getline(iss, token, ',');
        quantity = stoi(token);

        return Item(id, name, price, quantity);
    }
};

// Bill class definition
class Bill
{
public:
    int billID;
    string customerName;
    Item items[MAX_ITEMS];
    int itemCount;

    Bill(int id = 0, string name = "")
    {
        billID = id;
        customerName = name;
        itemCount = 0;
    }

    Bill &operator+(const Item &item)
    {
        if (itemCount >= MAX_ITEMS)
            throw overflow_error("Cannot add more items. Bill is full.");
        if (item.stockQuantity <= 0)
            throw invalid_argument("Cannot add item with zero or negative stock.");
        items[itemCount++] = item;
        return *this;
    }

    void checkEmpty() const
    {
        if (itemCount == 0)
            throw runtime_error("Cannot generate an empty bill.");
    }

    void displayBill() const
    {
        checkEmpty();
        cout << "Bill ID: " << billID << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Items Purchased:" << endl;
        double total = 0.0;
        for (int i = 0; i < itemCount; i++)
        {
            items[i].displayItem();
            total += items[i].price * items[i].stockQuantity;
        }
        cout << "Total Amount: $" << total << endl;
    }

    // Serialize bill as string
    string serialize() const
    {
        ostringstream oss;
        oss << billID << "," << customerName << "," << itemCount;
        for (int i = 0; i < itemCount; i++)
        {
            oss << "," << items[i].serialize();
        }
        return oss.str();
    }

    // Deserialize from string
    static Bill deserialize(const string &data)
    {
        istringstream iss(data);
        string token;
        int id, count;
        string name;

        getline(iss, token, ',');
        id = stoi(token);
        getline(iss, name, ',');
        getline(iss, token, ',');
        count = stoi(token);

        Bill bill(id, name);
        bill.itemCount = count;
        for (int i = 0; i < count; i++)
        {
            getline(iss, token, ',');
            int itemID = stoi(token);
            getline(iss, name, ',');
            getline(iss, token, ',');
            double price = stod(token);
            getline(iss, token, ',');
            int quantity = stoi(token);
            bill.items[i] = Item(itemID, name, price, quantity);
        }
        return bill;
    }
};

// Load all previous bills from file
void loadBills()
{
    ifstream infile(BILL_FILE);
    if (!infile)
    {
        cout << "No previous bills found." << endl;
        return;
    }

    string line;
    cout << "Previous Bills:" << endl;
    while (getline(infile, line))
    {
        try
        {
            Bill bill = Bill::deserialize(line);
            bill.displayBill();
            cout << "----------------------" << endl;
        }
        catch (const exception &e)
        {
            cout << "Error reading bill: " << e.what() << endl;
        }
    }
    infile.close();
}

// Save a new bill to file (append mode)
void saveBill(const Bill &bill)
{
    ofstream outfile(BILL_FILE, ios::app);
    if (!outfile)
    {
        cout << "Error opening file for writing." << endl;
        return;
    }
    outfile << bill.serialize() << endl;
    outfile.close();
}

int main()
{
    loadBills();

    try
    {
        Bill bill1(1, "John Doe");

        Item item1(101, "Keyboard", 25.50, 2);
        Item item2(102, "Mouse", 15.00, 1);

        bill1 + item1;
        bill1 + item2;

        bill1.displayBill();

        saveBill(bill1);
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
