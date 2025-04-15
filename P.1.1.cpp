#include<iostream>
using namespace std;

class Bank {
private:
    int acc_number;
    double balance;
    string name;

public:
    Bank(string Mname, int Macc_number, double Mbalance) {
        name = Mname;
        acc_number = Macc_number;
        balance = Mbalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful!" << endl;
        } else {
            cout << "Invalid amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount." << endl;
        } else if (balance < 10) {
            cout << "Your balance is less than 10. You can't withdraw." << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance. Withdrawal failed." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful!" << endl;
        }
    }

    void display() const {
        cout << "Account Holder: " << name << endl;
        cout << "Account Number: " << acc_number << endl;
        cout << "Your balance is: " << balance << endl;
    }
};

int main() {
    int Macc_number;
    string Mname;
    char choice;
    double amount, Mbalance;

    cout << "Enter your name: ";
    getline(cin, Mname);

    cout << "Enter your account number: ";
    cin >> Macc_number;

    cout << "Enter your initial balance: ";
    cin >> Mbalance;

    Bank b1(Mname, Macc_number, Mbalance);

    cout << "\n----- MENU -----\n"
         << "1. Deposit\n"
         << "2. Withdraw\n"
         << "3. Check Balance\n"
         << "4. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter amount to deposit: ";
                cin >> amount;
                b1.deposit(amount);
                break;

            case '2':
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                b1.withdraw(amount);
                break;

            case '3':
                b1.display();
                break;

            case '4':
                cout << "Thank You for banking with us!" << endl;
                cout << "------------------------------" << endl;
                cout << "Prepared by JASHKUMAR:24CE004" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
        cout<<"------------------------------"<<endl;
        cout<<"Prepared by Jashkumar:24CE004";
}
