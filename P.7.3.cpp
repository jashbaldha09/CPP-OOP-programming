#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Inventory {
private:
    int itemId;
    string itemName;
    int itemPrice;
    int itemQuantity;

public:
    void addItem() {
        ofstream outFile("P.7.3.txt", ios::app);
        if (!outFile) {
            cout << "File could not be opened!" << endl;
            return;
        }

        cout << "Enter Item ID: ";
        cin >> itemId;
        cin.ignore(); // clear buffer

        cout << "Enter Item Name: ";
        getline(cin, itemName);

        cout << "Enter Item Price: ";
        cin >> itemPrice;

        cout << "Enter Item Quantity: ";
        cin >> itemQuantity;

        outFile << itemId << " " << itemName << " " << itemPrice << " " << itemQuantity << endl;
        outFile.close();

        cout << "Item added successfully!" << endl;
    }

    void viewInventory() {
        ifstream inFile("P.7.3.txt");
        if (!inFile) {
            cout << "File could not be opened!" << endl;
            return;
        }

        cout << "\n--- INVENTORY ---\n";
        cout << left << setw(10) << "ID"
             << setw(20) << "Name"
             << setw(10) << "Price"
             << setw(10) << "Quantity" << endl;
        cout << "---------------------------------------------" << endl;

        while (inFile >> itemId >> itemName >> itemPrice >> itemQuantity) {
            cout << left << setw(10) << itemId
                 << setw(20) << itemName
                 << setw(10) << itemPrice
                 << setw(10) << itemQuantity << endl;
        }

        inFile.close();
    }

    void searchItem() {
        ifstream inFile("P.7.3.txt");
        if (!inFile) {
            cout << "File could not be opened!" << endl;
            return;
        }

        string searchName;
        bool found = false;

        cout << "Enter item name to search: ";
        cin >> searchName;

        while (inFile >> itemId >> itemName >> itemPrice >> itemQuantity) {
            if (itemName == searchName) {
                cout << "\nItem Found!\n";
                cout << "ID: " << itemId << endl;
                cout << "Name: " << itemName << endl;
                cout << "Price: " << itemPrice << endl;
                cout << "Quantity: " << itemQuantity << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Item not found!" << endl;
        }

        inFile.close();
    }
};

int main() {
    Inventory inv;
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Item\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Item\n";
        cout << "4. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inv.addItem();
                break;
            case 2:
                inv.viewInventory();
                break;
            case 3:
                inv.searchItem();
                break;
            case 4:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}

