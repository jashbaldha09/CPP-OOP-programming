#include<iostream>
using namespace std;

class Calculator
{
public:
    int Add(int a,int b)
    {
        return a+b;
    }

    float Add(int a,float b)
    {
        return a+b;
    }

    float Add(float a,int b)
    {
        return a+b;
    }

    float Add(float a,float b)
    {
        return a+b;
    }
};

int main()
{
    Calculator c1;

    cout<<"int + int "<<c1.Add(10,11)<<endl;
    cout<<"int + float "<<c1.Add(10,11.5f)<<endl;
    cout<<"float + int "<<c1.Add(10.5f,11)<<endl;
    cout<<"float + float "<<c1.Add(10.5f,11.3f)<<endl;

    cout<<endl<<"Created by Jashkumar : 24CE004"<<endl;
}
