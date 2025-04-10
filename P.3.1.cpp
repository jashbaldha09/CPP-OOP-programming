#include <iostream>
using namespace std;

class PayRoll
{
private:
    string EmployeeName;
    int EmployeeSalary,EmployeeBonus,EmployeeID;

public:

    PayRoll(){}

    PayRoll(string MainName,int MainSalary,int MainID,int MainBonus = 500)
    {
        EmployeeName = MainName;
        EmployeeSalary = MainSalary;
        EmployeeID = MainID;
        EmployeeBonus = MainBonus;
    }

    void TotalSalary()
    {
        EmployeeSalary += EmployeeBonus;
    }

    void DisplayInfo()
    {
        cout<<"Name   : "<<EmployeeName<<endl;
        cout<<"ID     : "<<EmployeeID<<endl;
        cout<<"Total  : "<<EmployeeSalary<<endl;
    }
};

int main()
{
    string MainName;
    int MainSalary,MainID,MainBonus;
    int n;
    cout<<"Enter the numbers of the Employee : ";
    cin>>n;
    cout<<endl;
    PayRoll employee[n];

    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter your Name : ";
        cin>>MainName;

        cout<<"Enter your ID : ";
        cin>>MainID;

        cout<<"Enter your Salary : ";
        cin>>MainSalary;

        cout<<"Enter your BonusSalary : ";
        cin>>MainBonus;
        cout<<endl;
        employee[i] = PayRoll(MainName,MainSalary,MainID,MainBonus);
    }

    for(int i=0 ; i<n ; i++)
    {
        cout<<endl<<"Information of Employee "<<i+1<<endl;
        employee[i].DisplayInfo();
    }

    cout<<endl<<"Created by Jashkumar : 24CE004"<<endl;
}
