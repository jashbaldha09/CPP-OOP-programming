#include<iostream>
#include<iomanip>
using namespace std;

class accountdetails
{
    string name;
    int amount,number;

public:
    bool Search_Account(int Acc_number)
    {
        if(number == Acc_number)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void New_Account(string Acc_name,int Acc_number,int Acc_amount)
    {
        name = Acc_name;
        number = Acc_number;
        amount = Acc_amount;
    }

    void Deposit_Money(int Deposit)
    {
        amount = amount + Deposit;
        cout<<"Your Balance is "<<amount<<endl;
    }

    void Withdraw_Money(int Withdraw)
    {

        if(amount - Withdraw<2000)
        {
            cout<<"Minimum balance should be 2000. Transaction failed"<<endl;
        }

        else
        {
            amount = amount - Withdraw;
            cout<<"Your Balance is "<<amount<<endl;
        }
    }

    int Get_Balance()
    {
        return amount;
    }

    void Print_Details()
    {
        cout<<left<<setw(21)<<"Account holder name : "<<name<<endl;
        cout<<left<<setw(22)<<"Account number : "<<number<<endl;
        cout<<left<<setw(22)<<"Total balance : "<<amount<<endl;
    }
};

int main()
{
    accountdetails acc[20];
    string Acc_name;
    int Acc_number , Acc_amount , n=0 , choice=0 , main_choice=0 , Withdraw , Deposit , i=0;
    bool Verify = false;

    cout<<"WELCOME!!"<<endl;
    cout<<"1.For Account Create"<<endl;
    cout<<"2.Account transaction"<<endl;
    cout<<"0.For exit the system"<<endl;

    while(true)
    {
        cout<<endl<<"Enter your choice of system : ";
        cin>>main_choice;

        if(main_choice==0)
        {
            cout<<"Exit the system!!!"<<endl;
            cout<<"Created by Jashkumar : 24CE004"<<endl;
            break;
        }

        switch(main_choice)
        {
        case 1:
            cout<<"Enter your Account number : ";
            cin>>Acc_number;

            for(i=0 ; i<n ; i++)
            {
                if(acc[i].Search_Account(Acc_number)==1)
                {
                    cout<<"Your Account already exist"<<endl;
                    goto end_case1;
                }
            }
                cout<<"New Account Created"<<endl;
                cout<<"Enter your name : ";
                cin>>Acc_name;

                cout<<"Enter your amount : ";
                cin>>Acc_amount;

                acc[n].New_Account(Acc_name,Acc_number,Acc_amount);
                n++;

            end_case1:
            break;

        case 2:
            cout<<"1.Deposit Money"<<endl;
            cout<<"2.Withdraw money"<<endl;
            cout<<"3.Print the details of Account"<<endl;
            cout<<"0.Exit the Account"<<endl;

            cout<<endl<<"Enter your Account number : ";
            cin>>Acc_number;
            Verify = false;

            for(i=0 ; i<n ; i++)
            {
                if(acc[i].Search_Account(Acc_number)==1)
                {
                    Verify = true;
                    break;
                }
            }

            if(Verify==false)
            {
                cout<<"Account does not exist"<<endl;
                break;
            }

            while(true)
            {

                cout<<endl<<"Enter your choice of account : ";
                cin>>choice;

                if(choice == 0)
                {
                    cout<<"Exit the Account!!!"<<endl;
                    break;
                }

                switch(choice)
                {
                case 1:
                    cout<<"Enter your deposit : ";
                    cin>>Deposit;
                    acc[i].Deposit_Money(Deposit);
                    break;

                case 2:
                    cout<<"Enter your withdrawal : ";
                    cin>>Withdraw;
                    acc[i].Withdraw_Money(Withdraw);
                    break;

                case 3:
                    acc[i].Print_Details();
                    break;
                }
            }
        }
    }
}
