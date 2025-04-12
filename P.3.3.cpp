#include <iostream>
#include <vector>
using namespace std;

class BankAccount
{
private:
    string HolderName;
    int AccountNumber;
    int AccountBalance;
    static int TotalAccounts;

public:
    // Constructor
    BankAccount(string MainName, int MainNumber, int MainBalance)
    {
        HolderName = MainName;
        AccountNumber = MainNumber;
        AccountBalance = MainBalance;
        TotalAccounts++;
    }

    // Check if account exists
    static bool CheckAccount(vector<BankAccount> &Accounts, int MainNumber)
    {
        for (int i=0 ; i<Accounts.size() ; i++)
        {
            if (Accounts[i].AccountNumber == MainNumber)
                return true;
        }
        return false;
    }

    // Create a new account and add it to the accounts vector
    static void AccountCreation(vector<BankAccount> &Accounts, string MainName, int MainNumber, int MainBalance)
    {
        Accounts.emplace_back(MainName, MainNumber, MainBalance);
        cout << "Account has been created.\n";
    }

    // Display the details of a specific account
    void DisplayData(int i)
    {
        cout << "\nCustomer " << i + 1 << "\n";
        cout << "Name         : " << HolderName << "\n";
        cout << "Account No.  : " << AccountNumber << "\n";
        cout << "Balance      : " << AccountBalance << "\n";
    }

    // Display all account data
    static void DisplayAll(vector<BankAccount> &Accounts)
    {
        if (Accounts.empty())
        {
            cout << "No account found!\n";
            return;
        }

        for (int i = 0; i < Accounts.size(); i++)
        {
            Accounts[i].DisplayData(i);
        }
    }

    // Perform a transaction
    static void Transaction(vector<BankAccount> &Accounts, int SendNumber, int ReceiveNumber, int MainAmount)
    {
        int Sender = -1, Receiver = -1;

        for (int i = 0; i < Accounts.size(); i++)
        {
            if (Accounts[i].AccountNumber == SendNumber)
                Sender = i;
            if (Accounts[i].AccountNumber == ReceiveNumber)
                Receiver = i;
        }

        if (Sender != -1 && Receiver != -1)
        {
            if (Accounts[Sender].AccountBalance >= MainAmount)
            {
                Accounts[Sender].AccountBalance -= MainAmount;
                Accounts[Receiver].AccountBalance += MainAmount;
                cout << "Transaction Successful!\n";
            }
            else
            {
                cout << "Insufficient balance!\n";
            }
        }
        else
        {
            cout << "Invalid account number(s)!\n";
        }
    }

    // Delete an account from the vector
    static void DeleteAccount(vector<BankAccount> &Accounts, int MainNumber)
    {
        for (int i = 0; i < Accounts.size(); i++)
        {
            if (Accounts[i].AccountNumber == MainNumber)
            {
                Accounts.erase(Accounts.begin() + i);
                TotalAccounts--;
                cout << "Your Account has been deleted.\n";
                return;
            }
        }
        cout << "Invalid Account number!\n";
    }

    // Display the total number of accounts
    static void DisplayTotalAccounts()
    {
        cout << "Total number of accounts: " << TotalAccounts << "\n";  // Display the total account count
    }
};


int BankAccount::TotalAccounts = 0;

int main()
{
    vector<BankAccount> Accounts;
    char choice;
    string MainName;
    int MainNumber, MainBalance, SendNumber, ReceiveNumber, MainAmount;

    cout << "\n====== Bank Account Management ======\n";
    cout << "1. Create Account\n";
    cout << "2. Display All Accounts\n";
    cout << "3. Transfer Money\n";
    cout << "4. Delete Account\n";
    cout << "5. Check Total Accounts\n";
    cout << "0. Exit\n";

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "\nEnter Account Number: ";
            cin >> MainNumber;

            if (BankAccount::CheckAccount(Accounts, MainNumber))
            {
                cout << "Account Already exists!\n";
            }
            else
            {
                cin.ignore();
                cout << "Enter Account Holder's Name: ";
                getline(cin, MainName);

                cout << "Enter Initial Balance: ";
                cin >> MainBalance;

                BankAccount::AccountCreation(Accounts, MainName, MainNumber, MainBalance);
            }
            break;

        case '2':
            BankAccount::DisplayAll(Accounts);
            break;

        case '3':
            cout << "\nEnter Sender's Account Number: ";
            cin >> SendNumber;

            cout << "Enter Receiver's Account Number: ";
            cin >> ReceiveNumber;

            if (BankAccount::CheckAccount(Accounts, SendNumber) && BankAccount::CheckAccount(Accounts, ReceiveNumber))
            {
                cout << "Enter Amount to Transfer: ";
                cin >> MainAmount;
                BankAccount::Transaction(Accounts, SendNumber, ReceiveNumber, MainAmount);
            }
            else
            {
                cout << "Invalid Account number(s)!\n";
            }
            break;

        case '4':
            cout << "\nEnter Account Number to Delete: ";
            cin >> MainNumber;

            if (BankAccount::CheckAccount(Accounts, MainNumber))
            {
                BankAccount::DeleteAccount(Accounts, MainNumber);
            }
            else
            {
                cout << "Invalid Account number!\n";
            }
            break;

        case '5':
            BankAccount::DisplayTotalAccounts();
            break;

        case '0':
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
            break;
        }

    } while (choice != '0');

    cout<<endl<<"Created by Jashkumar - 24CE004"<<endl;

    return 0;
}
