#include<iostream>
using namespace std;

class Inventory {
private:
    int ID, quantity, price;
    string name;

public:
    void addProduct() {
        cout << "Enter your ID: ";
        cin >> ID;

        cout << "Enter the quantity: ";
        cin >> quantity;

        cout << "Enter price of product: ";
        cin >> price;

        cout << "Enter product name: ";
        cin >> name;
    }

    int getID() {
        return ID;
    }

    int getQuantity() {
        return quantity;
    }

    void updateQuantity(int q) {
        quantity += q;
    }

    int getValue() {
        return quantity * price;
    }
};

int main() {
    Inventory management[20];
    int choice, n = 0;

    cout << "Enter 1 to add product" << endl;
    cout << "Enter 2 to add quantity" << endl;
    cout << "Enter 3 to calculate the total value of all products" << endl;
    cout << "Enter 4 to Exit" << endl;

    while (1) {
        cout << endl << "Enter here: ";
        cin >> choice;

        if (choice == 1) {
            int amount;
            cout << endl << "Enter the number of products: ";
            cin >> amount;

            for (int i = 1; i <= amount; i++) {
                cout << endl << "Enter the detail for product " << (n + 1) << endl;
                management[n].addProduct();
                n++;
            }
        }

        else if (choice == 2) {
            int check_id, quantity;
            bool found = false;
            cout << "Enter your ID to update quantity: ";
            cin >> check_id;

            for (int j = 0; j < n; j++) {
                if (management[j].getID() == check_id) {
                    cout << "Your current quantity is: " << management[j].getQuantity() << endl;
                    cout << "Enter quantity to add: ";
                    cin >> quantity;

                    management[j].updateQuantity(quantity);
                    cout << "Quantity successfully updated!" << endl;
                    cout << "Updated quantity is: " << management[j].getQuantity() << endl;
                    found = true;
                }
            }

            if (!found) {
                cout << "Invalid ID" << endl;
            }
        }

        else if (choice == 3) {
            int totalValue = 0;
            for (int k = 0; k < n; k++) {
                totalValue += management[k].getValue();
            }
            cout << "Total value of inventory is: " << totalValue << endl;
        }

        else if (choice == 4) {
            cout << "Exiting the system!" << endl;
            break;
        }

        else {
            cout << "Enter a valid value!" << endl;
        }
    }

    cout << "------------------------------" << endl;
    cout << "Created by Jashkumar - 24CE004" << endl;
    return 0;
}
