#include<iostream>
using namespace std;

class bank
{
public:
    int acc_number;
    double balance;
    string name;
    void deposit(int amount)
    {
        balance+=amount;
    }
    void withdraw(int amount)
    {
        balance-=amount;
    }
    void display()
    {
        cout<<"Your balance is "<<balance<<endl;
    }
};

int main()
{
    char choice;
    double amount;
    bank b1;

    cout<<"Enter your name:";
    getline(cin,b1.name);

    cout<<"Enter your account number:";
    cin>>b1.acc_number;

    cout<<"For DEPOSIT press 1"<<endl<<"For WITHDRAW press 2"<<endl<<"For BALANCE press 3"<<endl<<"For EXIT press 4";
    while(1)
    {
        cout<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        if(choice == '1')
        {
            cout<<"Enter your amount to deposit:";
            cin>>amount;
            b1.deposit(amount);

        }

        else if(choice == '2')
        {
            if(b1.balance < 10)
            {
                cout<<"Your balance is less than 10 so you can't withdraw"<<endl;
            }
            else
            {
                cout<<"Enter your amount to withdraw:";
                cin>>amount;
                b1.withdraw(amount);
            }

        }

        else if(choice == '3')
        {
            b1.display();
        }

        else
        {
            cout<<"Thank You!!"<<endl;
            break;
        }

    }
        cout<<"------------------------------"<<endl;
        cout<<"Prepared by JASHKUMAR:24CE004";
}
