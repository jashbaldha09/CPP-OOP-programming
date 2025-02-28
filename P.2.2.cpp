#include<iostream>
#include<iomanip>

using namespace std;

class student
{
    int roll_number,m1,m2,m3;
    string name;
    float avg;

    public:
    void getdata(string,int,int,int,int);
    void avg_calculator();
    void putdata(int);
};

void student :: getdata(string Sname = "Unknown",int Sroll_number=0,int Sm1=0,int Sm2=0,int Sm3=0)
{
    name = Sname;
    roll_number = Sroll_number;
    m1 = Sm1;
    m2 = Sm2;
    m3 = Sm3;

    avg_calculator();
}

void student :: avg_calculator()
{
    float sum=0;

    sum = m1+m2+m3;

    avg = (float)sum/3.0;
}

void student :: putdata(int i)
{
    cout<<endl;
    cout<<" Student details for student "<<i+1<<endl;
    cout<<left<<setw(20)<<"Name : "<<name<<endl;
    cout<<left<<setw(20)<<"Roll Number : "<<roll_number<<endl;
    cout<<left<<setw(20)<<"1st subject marks : "<<m1<<endl;
    cout<<left<<setw(20)<<"2nd subject marks : "<<m2<<endl;
    cout<<left<<setw(20)<<"3rd subject marks : "<<m3<<endl;
    cout<<left<<setw(20)<<fixed<<setprecision(2)<<"Average : "<<avg<<endl;
}

int main()
{
    int number,Sroll_number,Sm1,Sm2,Sm3;
    string Sname;
    cout<<"Enter the Number of students : ";
    cin>>number;

    student s[number];

    for(int i=0 ; i<number ; i++)
    {
        cout<<endl;
        cout<<"Enter "<<i+1<<" student name : ";
        cin>>Sname;

        cout<<"Enter "<<i+1<<" student roll number : ";
        cin>>Sroll_number;

        cout<<"Enter "<<i+1<<" student first subject marks : ";
        cin>>Sm1;

        cout<<"Enter "<<i+1<<" student second subject marks : ";
        cin>>Sm2;

        cout<<"Enter "<<i+1<<" student third subject marks : ";
        cin>>Sm3;

        s[i].getdata(Sname,Sroll_number,Sm1,Sm2,Sm3);
    }

     for(int i=0 ; i<number ; i++)
     {
         s[i].putdata(i);
     }

     cout<<endl<<"Created by Jashkumar : 24CE004"<<endl;
}
