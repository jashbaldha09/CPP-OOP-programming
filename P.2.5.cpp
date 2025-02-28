#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class LoanData
{
    string ApplicantName;
    float LoanAmount,LoanInterest,LoanInterest1,LoanTenure,LoanEMI;

public:
    void AddData(string Name,float Amount,float Interest,float Tenure);
    void EMICalculator();
    void PutData();
};

void LoanData :: AddData(string Name,float Amount,float Interest,float Tenure)
{
    ApplicantName = Name;
    LoanAmount = Amount;
    LoanInterest = Interest;
    LoanTenure = Tenure;

    EMICalculator();
    PutData();
}

void LoanData :: EMICalculator()
{
    LoanInterest1 = LoanInterest/1200;
    LoanEMI = (LoanAmount*LoanInterest1*pow(1.0+LoanInterest1,LoanTenure))/(pow(1.0+LoanInterest1,LoanTenure)-1.0);
}

void LoanData :: PutData()
{
    cout << left << setw(23) << "Account holder Name : " << ApplicantName << endl;
    cout << left << setw(23) << "Loan Amount : " << LoanAmount << endl;
    cout << left << setw(23) << "Loan Interest : " << LoanInterest << endl;
    cout << left << setw(23) << "Loan Tenure : " << LoanTenure << endl;
    cout << left << setw(23) << fixed << setprecision(2) << "EMI : " << LoanEMI << endl;
}
int main()
{
    LoanData Account[20];
    string Name;
    float Amount,Interest,Tenure;
    int choice=1,n=0;

    cout<<"1.To check EMI"<<endl;
    cout<<"2.To exit the system"<<endl;

    while(choice!=2)
    {
        jash:
        cout<<endl<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"Enter your Name : ";
            cin>>Name;

            cout<<"Enter your Amount : ";
            cin>>Amount;

            cout<<"Enter your Interest : ";
            cin>>Interest;

            cout<<"Enter your Tenure(In months) : ";
            cin>>Tenure;

            Account[n].AddData(Name,Amount,Interest,Tenure);
            n++;
            break;

        case 2:
            cout<<"Exit the System!!"<<endl;
            cout<<endl<<"Created by Jashkumar : 24CE004"<<endl;
            return 0;

        default:
            goto jash;
            break;
        }
    }
}
