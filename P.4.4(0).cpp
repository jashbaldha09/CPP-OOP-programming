#include<iostream>
#include<vector>
using namespace std;

class SavingAccount;
class CurrentAccount;

class BankAccount
{
protected:
    int AccNumber;
    float AccBalance;

public:
    BankAccount(int MainNumber, float MainBalance)
    {
        AccNumber = MainNumber;
        AccBalance = MainBalance;
    }

    // Getter function to access AccNumber
    int GetAccNumber() const
    {
        return AccNumber;
    }

    friend bool SavingSearchAcc(vector<SavingAccount>& savingaccount, int MainNumber);
    friend bool CurrentSearchAcc(vector<CurrentAccount>& currentaccount, int MainNumber);
};

class Transaction
{
public:
    int AccountNumber;
    string Type;  // Deposit or Withdrawal
    float Amount;
};

class SavingAccount : public BankAccount
{
protected:
    float AccInterest;
    vector<Transaction> transactionHistory;

public:
    SavingAccount(float MainInterest, int MainNumber, float MainBalance) : BankAccount(MainNumber, MainBalance)
    {
        AccInterest = MainInterest;
    }

    void DepositMoney(float DMoney)
    {
        AccBalance += DMoney;
        transactionHistory.push_back({AccNumber, "Deposit", DMoney});
    }

    void WithdrawMoney(float WMoney)
    {
        AccBalance -= WMoney;
        transactionHistory.push_back({AccNumber, "Withdraw", WMoney});
    }

    void AccDetail()
    {
        cout << "\nAccount Number: " << GetAccNumber() << endl;  // Use GetAccNumber
        cout << "Account Balance: " << AccBalance << endl;
    }

    void ShowTransactionHistory()
    {
        cout << "Transaction History for Account " << GetAccNumber() << ":" << endl;
        for (int i = 0; i < transactionHistory.size(); i++)
        {
            cout << "Type: " << transactionHistory[i].Type << " | Amount: " << transactionHistory[i].Amount << endl;
        }
    }

    void UndoLastTransaction()
    {
        if (!transactionHistory.empty())
        {
            Transaction lastTransaction = transactionHistory.back();
            if (lastTransaction.Type == "Deposit")
            {
                // Undo deposit (withdraw the same amount)
                AccBalance -= lastTransaction.Amount;
                cout << "Undoing Deposit of " << lastTransaction.Amount << " from Account " << GetAccNumber() << endl;
            }
            else if (lastTransaction.Type == "Withdraw")
            {
                // Undo withdrawal (deposit the same amount)
                AccBalance += lastTransaction.Amount;
                cout << "Undoing Withdrawal of " << lastTransaction.Amount << " to Account " << GetAccNumber() << endl;
            }
            transactionHistory.pop_back();  // Remove the last transaction
        }
        else
        {
            cout << "No transactions to undo!" << endl;
        }
    }
};

class CurrentAccount : public BankAccount
{
protected:
    float AccOverdraft;
    vector<Transaction> transactionHistory;

public:
    CurrentAccount(float MainOverdraft, int MainNumber, float MainBalance) : BankAccount(MainNumber, MainBalance)
    {
        AccOverdraft = MainOverdraft;
    }

    void DepositMoney(float DMoney)
    {
        AccBalance += DMoney;
        transactionHistory.push_back({AccNumber, "Deposit", DMoney});
    }

    void WithdrawMoney(float WMoney)
    {
        AccBalance -= WMoney;
        transactionHistory.push_back({AccNumber, "Withdraw", WMoney});
    }

    void AccDetail()
    {
        cout << "\nAccount Number: " << GetAccNumber() << endl;  // Use GetAccNumber
        cout << "Account Balance: " << AccBalance << endl;
    }

    void ShowTransactionHistory()
    {
        cout << "Transaction History for Account " << GetAccNumber() << ":" << endl;
        for (int i = 0; i < transactionHistory.size(); i++)
        {
            cout << "Type: " << transactionHistory[i].Type << " | Amount: " << transactionHistory[i].Amount << endl;
        }
    }

    void UndoLastTransaction()
    {
        if (!transactionHistory.empty())
        {
            Transaction lastTransaction = transactionHistory.back();
            if (lastTransaction.Type == "Deposit")
            {
                // Undo deposit (withdraw the same amount)
                AccBalance -= lastTransaction.Amount;
                cout << "Undoing Deposit of " << lastTransaction.Amount << " from Account " << GetAccNumber() << endl;
            }
            else if (lastTransaction.Type == "Withdraw")
            {
                // Undo withdrawal (deposit the same amount)
                AccBalance += lastTransaction.Amount;
                cout << "Undoing Withdrawal of " << lastTransaction.Amount << " to Account " << GetAccNumber() << endl;
            }
            transactionHistory.pop_back();  // Remove the last transaction
        }
        else
        {
            cout << "No transactions to undo!" << endl;
        }
    }
};

bool SavingSearchAcc(vector<SavingAccount>& savingaccount, int MainNumber)
{
    for (int i = 0; i < savingaccount.size(); i++)
    {
        if (savingaccount[i].GetAccNumber() == MainNumber)
        {
            return true;
        }
    }
    return false;
}

bool CurrentSearchAcc(vector<CurrentAccount>& currentaccount, int MainNumber)
{
    for (int i = 0; i < currentaccount.size(); i++)
    {
        if (currentaccount[i].GetAccNumber() == MainNumber)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<CurrentAccount> currentaccount;
    vector<SavingAccount> savingaccount;
    int Choice, ChoiceAcc, MainNumber, MainOverdraft;
    float WMoney, DMoney, MainBalance, MainInterest;

    cout << "   Welcome to Bank System      " << endl;
    cout << "===============================" << endl;
    cout << "1. Account Creation" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Transaction History" << endl;
    cout << "5. Undo Last Transaction" << endl;
    cout << "6. Account Details" << endl;
    cout << "0. Exit" << endl;

    do
    {
        cout << endl << endl << "Enter your choice: ";
        cin >> Choice;

        if (Choice == 0)
            break;

        switch (Choice)
        {
        case 1:
            {
                cout << endl << "1.For Saving Account";
                cout << endl << "2.For Current Account";
                cout << endl << endl << "Enter your choice(Account Type) : ";
                cin >> ChoiceAcc;

                switch (ChoiceAcc)
                {
                case 1:
                    {
                        cout << endl << "Enter Your Account Number : ";
                        cin >> MainNumber;

                        if (SavingSearchAcc(savingaccount, MainNumber) == false)
                        {
                            cout << "Enter Your Account Balance : ";
                            cin >> MainBalance;

                            cout << "Enter Your Interest Rate : ";
                            cin >> MainInterest;

                            savingaccount.emplace_back(MainInterest, MainNumber, MainBalance);
                            cout << "Account has been Created";
                        }
                        else
                        {
                            cout << "Account Already exists!";
                        }
                        break;
                    }

                case 2:
                    {
                        cout << endl << "Enter Your Account Number : ";
                        cin >> MainNumber;

                        if (CurrentSearchAcc(currentaccount, MainNumber) == false)
                        {
                            cout << "Enter Your Account Balance : ";
                            cin >> MainBalance;

                            cout << "Enter Your OverDraft Limit : ";
                            cin >> MainOverdraft;

                            currentaccount.emplace_back(MainOverdraft, MainNumber, MainBalance);
                            cout << "Account has been Created";
                        }
                        else
                        {
                            cout << "Account Already exists!";
                        }
                        break;
                    }
                }
                break;
            }

        case 2:
            {
                cout << "Enter Your Account Number: ";
                cin >> MainNumber;

                cout << endl << "1.For Saving Account";
                cout << endl << "2.For Current Account";
                cout << endl << endl << "Enter your choice(Account Type) : ";
                cin >> ChoiceAcc;

                switch (ChoiceAcc)
                {
                case 1:
                    {
                        if (SavingSearchAcc(savingaccount, MainNumber))
                        {
                            cout << "Enter Deposit Amount: ";
                            cin >> DMoney;

                            for (int i = 0; i < savingaccount.size(); i++)
                            {
                                if (savingaccount[i].GetAccNumber() == MainNumber)
                                {
                                    savingaccount[i].DepositMoney(DMoney);
                                    cout << "Amount Deposited!" << endl;
                                }
                            }
                        }
                        else
                        {
                            cout << "Account does not exist!" << endl;
                        }
                        break;
                    }

                case 2:
                    {
                        if (CurrentSearchAcc(currentaccount, MainNumber))
                        {
                            cout << "Enter Deposit Amount: ";
                            cin >> DMoney;

                            for (int i = 0; i < currentaccount.size(); i++)
                            {
                                if (currentaccount[i].GetAccNumber() == MainNumber)
                                {
                                    currentaccount[i].DepositMoney(DMoney);
                                    cout << "Amount Deposited!" << endl;
                                }
                            }
                        }
                        else
                        {
                            cout << "Account does not exist!" << endl;
                        }
                        break;
                    }

                default:
                    cout << "Invalid Account Type!" << endl;
                    break;
                }
                break;
            }

        case 3:
            {
                cout << "Enter Your Account Number: ";
                cin >> MainNumber;

                cout << endl << "1.For Saving Account";
                cout << endl << "2.For Current Account";
                cout << endl << endl << "Enter your choice(Account Type) : ";
                cin >> ChoiceAcc;

                switch (ChoiceAcc)
                {
                case 1:
                    {
                        if (SavingSearchAcc(savingaccount, MainNumber))
                        {
                            cout << "Enter Withdraw Amount: ";
                            cin >> WMoney;

                            for (int i = 0; i < savingaccount.size(); i++)
                            {
                                if (savingaccount[i].GetAccNumber() == MainNumber)
                                {
                                    savingaccount[i].WithdrawMoney(WMoney);
                                    cout << "Amount Withdrawn!" << endl;
                                }
                            }
                        }
                        else
                        {
                            cout << "Account does not exist!" << endl;
                        }
                        break;
                    }

                case 2:
                    {
                        if (CurrentSearchAcc(currentaccount, MainNumber))
                        {
                            cout << "Enter Withdraw Amount: ";
                            cin >> WMoney;

                            for (int i = 0; i < currentaccount.size(); i++)
                            {
                                if (currentaccount[i].GetAccNumber() == MainNumber)
                                {
                                    currentaccount[i].WithdrawMoney(WMoney);
                                    cout << "Amount Withdrawn!" << endl;
                                }
                            }
                        }
                        else
                        {
                            cout << "Account does not exist!" << endl;
                        }
                        break;
                    }

                default:
                    cout << "Invalid Account Type!" << endl;
                    break;
                }
                break;
            }

        case 4:
            {
                cout << "Enter Your Account Number: ";
                cin >> MainNumber;

                cout << endl << "1.For Saving Account";
                cout << endl << "2.For Current Account";
                cout << endl << endl << "Enter your choice(Account Type) : ";
                cin >> ChoiceAcc;

                switch (ChoiceAcc)
                {
                case 1:
                    {
                        if (SavingSearchAcc(savingaccount, MainNumber))
                        {
                            for (int i = 0; i < savingaccount.size(); i++)
                            {
                                if (savingaccount[i].GetAccNumber() == MainNumber)
                                {
                                    savingaccount[i].ShowTransactionHistory();
                                }
                            }
                        }
                        else
                        {
                            cout << "Account does not exist!" << endl;
                        }
                        break;
                    }

                case 2:
                    {
                        if (CurrentSearchAcc(currentaccount, MainNumber))
                        {
                            for (int i = 0; i < currentaccount.size(); i++)
                            {
                                if (currentaccount[i].GetAccNumber() == MainNumber)
                                {
                                    currentaccount[i].ShowTransactionHistory();
                                }
                            }
                        }
                        else
                        {
                            cout << "Account does not exist!" << endl;
                        }
                        break;
                    }

                default:
                    cout << "Invalid Account Type!" << endl;
                    break;
                }
                break;
            }

        case 5:
            {
                cout << "Enter Your Account Number: ";
                cin >> MainNumber;

                cout << endl << "1.For Saving Account";
                cout << endl << "2.For Current Account";
                cout << endl << endl << "Enter your choice(Account Type) : ";
                cin >> ChoiceAcc;

                switch (ChoiceAcc)
                {
                case 1:
                    {
                        if (SavingSearchAcc(savingaccount, MainNumber))
                        {
                            for (int i = 0; i < savingaccount.size(); i++)
                            {
                                if (savingaccount[i].GetAccNumber() == MainNumber)
                                {
                                    savingaccount[i].UndoLastTransaction();
                                }
                            }
                        }
                        else
                        {
                            cout << "Account does not exist!" << endl;
                        }
                        break;
                    }

                case 2:
                    {
                        if (CurrentSearchAcc(currentaccount, MainNumber))
                        {
                            for (int i = 0; i < currentaccount.size(); i++)
                            {
                                if (currentaccount[i].GetAccNumber() == MainNumber)
                                {
                                    currentaccount[i].UndoLastTransaction();
                                }
                            }
                        }
                        else
                        {
                            cout << "Account does not exist!" << endl;
                        }
                        break;
                    }

                default:
                    cout << "Invalid Account Type!" << endl;
                    break;
                }
                break;
            }

        case 6:
            {
                cout << "Enter Your Account Number: ";
                cin >> MainNumber;

                cout << endl << "1.For Saving Account";
                cout << endl << "2.For Current Account";
                cout << endl << endl << "Enter your choice(Account Type) : ";
                cin >> ChoiceAcc;

                switch (ChoiceAcc)
                {
                case 1:
                    {
                        if (SavingSearchAcc(savingaccount, MainNumber))
                        {
                            for (int i = 0; i < savingaccount.size(); i++)
                            {
                                if (savingaccount[i].GetAccNumber() == MainNumber)
                                {
                                    savingaccount[i].AccDetail();
                                }
                            }
                        }
                        else
                        {
                            cout << "Account does not exist!" << endl;
                        }
                        break;
                    }

                case 2:
                    {
                        if (CurrentSearchAcc(currentaccount, MainNumber))
                        {
                            for (int i = 0; i < currentaccount.size(); i++)
                            {
                                if (currentaccount[i].GetAccNumber() == MainNumber)
                                {
                                    currentaccount[i].AccDetail();
                                }
                            }
                        }
                        else
                        {
                            cout << "Account does not exist!" << endl;
                        }
                        break;
                    }

                default:
                    cout << "Invalid Account Type!" << endl;
                    break;
                }
                break;
            }
        }
    }
    while (Choice != 0);

    cout<<endl<<"Created by Jashkumar - 24CE004"<<endl;

    return 0;
}
