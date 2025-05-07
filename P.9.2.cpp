#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    double balance;
    string history[100];
    int logIndex;

public:
    BankAccount() {
        balance = 0;
        logIndex = 0;
    }

    void log(string message) {
        if (logIndex < 100) {
            history[logIndex++] = message;
        }
    }

    void deposit(double amount) {
        if (amount <= 0) {
            log("Invalid deposit attempt.");
            throw invalid_argument("Deposit amount must be greater than 0.");
        }
        balance += amount;
        log("Deposited: " + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            log("Invalid withdraw attempt.");
            throw invalid_argument("Withdrawal amount must be greater than 0.");
        }
        if (amount > balance) {
            log("Attempt to withdraw more than balance.");
            throw runtime_error("Insufficient balance.");
        }
        balance -= amount;
        log("Withdrawn: " + to_string(amount));
    }

    double getBalance() {
        return balance;
    }

    void printHistory() {
        cout << "\n--- Transaction History ---" << endl;
        for (int i = 0; i < logIndex; i++) {
            cout << history[i] << endl;
        }
    }
};

int main() {
    BankAccount myAccount;
    double amount;
    int choice;

    cout << fixed << setprecision(2);

    do {
        cout << "\n===== Banking System =====" << endl;
        cout << "1. Deposit\n2. Withdraw\n3. Check Balance\n4. Show History\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    myAccount.deposit(amount);
                    cout << "Deposit successful." << endl;
                    break;

                case 2:
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    myAccount.withdraw(amount);
                    cout << "Withdrawal successful." << endl;
                    break;

                case 3:
                    cout << "Current balance: " << myAccount.getBalance() << endl;
                    break;

                case 4:
                    myAccount.printHistory();
                    break;

                case 5:
                    cout << "Thank you for using the banking system." << endl;
                    break;

                default:
                    cout << "Invalid choice." << endl;
            }
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 5);

    cout << endl << "Created by Jashkumar : 24CE004" << endl;
    return 0;
}
