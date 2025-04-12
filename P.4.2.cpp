#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class Person
{
protected:
    int Age;
    string Name;

public:
    Person(int MainAge,string MainName)
    {
        Age = MainAge;
        Name = MainName;
    }
};

class Employee : public Person
{
protected:
    int ID;

public:
    Employee(int MainID,int MainAge,string MainName) : Person(MainAge,MainName)
    {
        ID = MainID;
    }
};

class Manager : public Employee
{
private:
    string Department;

public:
    Manager(string MainDepartment,int MainID,int MainAge,string MainName) : Employee(MainID,MainAge,MainName)
    {
        Department = MainDepartment;
    }

    void DisplayData(int i)
    {
        cout << endl << "Detail of person " << i + 1 << endl;
        cout << setw(13) << left << "Name" << " : " << Name << endl;
        cout << setw(13) << left << "Age" << " : " << Age << endl;
        cout << setw(13) << left << "ID" << " : " << ID << endl;
        cout << setw(13) << left << "Department" << " : " << Department << endl;
    }
};

int main()
{
    string MainDepartment,MainName;
    int MainID,MainAge,MainChoice;
    vector<Manager> managers;

    cout << "1. Add Manager" << endl;
    cout << "2. Show All Managers" << endl;
    cout << "3. Exit" << endl;

    do
    {
        cout<<endl<<"Enter your choice : ";
        cin>>MainChoice;

        if(MainChoice==3)
            break;

        switch(MainChoice)
        {
        case 1:
            {
                cout<<endl<<"Enter the Name : ";
                cin>>MainName;

                cout<<"Enter the Age : ";
                cin>>MainAge;

                cout<<"Enter the ID : ";
                cin>>MainID;

                cout<<"Enter the Department : ";
                cin>>MainDepartment;

                Manager m(MainDepartment,MainID,MainAge,MainName);
                managers.push_back(m);
                break;
            }

        case 2:
            {
                for(int i=0 ; i<managers.size() ; i++)
                {
                    managers[i].DisplayData(i);
                }
                break;
            }

        default:
            {
                cout<<endl<<"Enter valid choice!!";
                break;
            }

        }
    }while(true);

    cout<<endl<<"Created by Jashkumar - 24CE004"<<endl;
}
