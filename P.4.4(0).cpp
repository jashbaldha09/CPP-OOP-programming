#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
protected:
    int AccountNumber, Balance, PreviousBalance;
public:
    BankAccount(int MainNumber, int MainBalance) {
        AccountNumber = MainNumber;
        Balance = MainBalance;
        PreviousBalance = Balance;
    }
};

class SavingAccount : public BankAccount {
private:
    float InterestRate;
    vector<string> history;
public:
    SavingAccount(int MainNumber, int MainBalance, float MainInterestRate) : BankAccount(MainNumber, MainBalance) {
        InterestRate = MainInterestRate;
        cout << "Saving account created successfully!" << endl << endl;
    }

    void DepositMoney(int amount) {
        PreviousBalance = Balance;
        Balance += amount;
        history.push_back("Deposited: " + to_string(amount));
        cout << "Amount " << amount << " deposited successfully!" << endl;
        cout << "Current balance: " << Balance << endl << endl;
    }

    void WithdrawMoney(int amount) {
        PreviousBalance = Balance;
        Balance -= amount;
        history.push_back("Withdrawn: " + to_string(amount));
        cout << "Amount " << amount << " withdrawn successfully!" << endl;
        cout << "Current balance: " << Balance << endl << endl;
    }

    void UndoMoney() {
        Balance = PreviousBalance;
        history.push_back("Undo transaction");
        cout << "Undo done and current balance: " << Balance << endl << endl;
    }

    void DisplayHistory() {
        cout << "Transaction History:" << endl;
        for (int i = 0; i < history.size(); i++) {
            cout << history[i] << endl;
        }
        cout << endl;
    }
};

class CurrentAccount : public BankAccount {
private:
    int OverDraftLimit;
    vector<string> history;
public:
    CurrentAccount(int MainNumber, int MainBalance, int MainOverDraftLimit = 0) : BankAccount(MainNumber, MainBalance) {
        OverDraftLimit = MainOverDraftLimit;
        cout << "Current account created successfully!" << endl << endl;
    }

    void DepositMoney(int amount) {
        PreviousBalance = Balance;
        Balance += amount;
        history.push_back("Deposited: " + to_string(amount));
        cout << "Amount " << amount << " deposited successfully!" << endl;
        cout << "Current balance: " << Balance << endl << endl;
    }

    void WithdrawMoney(int amount) {
        PreviousBalance = Balance;
        if (amount > Balance + OverDraftLimit) {
            cout << "Amount is not enough to withdraw! Withdraw denied" << endl << endl;
        } else {
            Balance -= amount;
            history.push_back("Withdrawn: " + to_string(amount));
            cout << "Amount " << amount << " withdrawn successfully!" << endl;
            cout << "Current balance: " << Balance << endl << endl;
        }
    }

    void UndoMoney() {
        Balance = PreviousBalance;
        history.push_back("Undo transaction");
        cout << "Undo done and current balance: " << Balance << endl << endl;
    }

    void DisplayHistory() {
        cout << "Transaction History:" << endl;
        for (int i = 0; i < history.size(); i++) {
            cout << history[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    int MainNumber, MainBalance, MainOverDraftLimit, amount;
    float MainInterestRate;
    int ChoiceToAccount, ChoiceToTransaction;

    cout << "Enter 1 to create Saving Account" << endl;
    cout << "Enter 2 to create Current Account" << endl;
    cout << "Enter your choice: ";
    cin >> ChoiceToAccount;
    cout << endl;

    switch (ChoiceToAccount) {
    case 1: {
        cout << "Enter account number: ";
        cin >> MainNumber;
        cout << "Enter initial balance: ";
        cin >> MainBalance;
        cout << "Enter interest rate: ";
        cin >> MainInterestRate;
        cout << endl;

        SavingAccount mySaving(MainNumber, MainBalance, MainInterestRate);

        do {
            cout << "Enter 1 to Deposit amount" << endl;
            cout << "Enter 2 to Withdraw amount" << endl;
            cout << "Enter 3 to Undo last transaction" << endl;
            cout << "Enter 4 to View transaction history" << endl;
            cout << "Enter 0 to Exit" << endl;
            cout << "Enter your choice: ";
            cin >> ChoiceToTransaction;
            cout << endl;

            switch (ChoiceToTransaction) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                cout << endl;
                mySaving.DepositMoney(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                cout << endl;
                mySaving.WithdrawMoney(amount);
                break;
            case 3:
                mySaving.UndoMoney();
                break;
            case 4:
                mySaving.DisplayHistory();
                break;
            case 0:
                cout << "Thank you!" << endl << endl;
                break;
            default:
                cout << "Enter valid choice!" << endl << endl;
            }
        } while (ChoiceToTransaction != 0);
        break;
    }

    case 2: {
        cout << "Enter account number: ";
        cin >> MainNumber;
        cout << "Enter initial balance: ";
        cin >> MainBalance;
        cout << "Enter overdraft limit: ";
        cin >> MainOverDraftLimit;
        cout << endl;

        CurrentAccount myCurrent(MainNumber, MainBalance, MainOverDraftLimit);

        do {
            cout << "Enter 1 to Deposit amount" << endl;
            cout << "Enter 2 to Withdraw amount" << endl;
            cout << "Enter 3 to Undo last transaction" << endl;
            cout << "Enter 4 to View transaction history" << endl;
            cout << "Enter 0 to Exit" << endl;
            cout << "Enter your choice: ";
            cin >> ChoiceToTransaction;
            cout << endl;

            switch (ChoiceToTransaction) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                cout << endl;
                myCurrent.DepositMoney(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                cout << endl;
                myCurrent.WithdrawMoney(amount);
                break;
            case 3:
                myCurrent.UndoMoney();
                break;
            case 4:
                myCurrent.DisplayHistory();
                break;
            case 0:
                cout << "Thank you!" << endl << endl;
                break;
            default:
                cout << "Enter valid choice!" << endl << endl;
            }
        } while (ChoiceToTransaction != 0);
        break;
    }

    default:
        cout << "Enter valid choice! and try again" << endl << endl;
    }

    cout << "Created by Jashkumar - 24CE004" << endl;
    return 0;
}
