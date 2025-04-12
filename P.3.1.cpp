#include <iostream>
#include <vector>
using namespace std;

class PayRoll
{
private:
    string EmployeeName;
    int EmployeeSalary, EmployeeBonus, EmployeeID;

public:

    PayRoll() {}

    PayRoll(string MainName, int MainSalary, int MainID, int MainBonus = 500)
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
        cout << "Name   : " << EmployeeName << endl;
        cout << "ID     : " << EmployeeID << endl;
        cout << "Total  : " << EmployeeSalary+EmployeeBonus << endl;
    }
};

int main()
{
    string MainName;
    int MainSalary, MainID, MainBonus;

    vector<PayRoll> employeelist;

    cout<<"Enter 'stop' to exit"<<endl;
    while (true)
    {
        cout << "Enter your Name : ";
        cin >> MainName;
        if (MainName == "stop")
            break;

        cout << "Enter your ID : ";
        cin >> MainID;

        cout << "Enter your Salary : ";
        cin >> MainSalary;

        cout << "Enter your BonusSalary : ";
        cin >> MainBonus;
        cout << endl;

        PayRoll employee(MainName, MainSalary, MainID, MainBonus);
        employeelist.push_back(employee);
    }

    for (int i = 0; i < employeelist.size(); i++)
    {
        cout << endl << "Information of Employee " << i + 1 << endl;
        employeelist[i].DisplayInfo();
    }

    cout << endl << "Created by Jashkumar : 24CE004" << endl;
}
