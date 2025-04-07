#include<iostream>
#define PI 3.14
using namespace std;

class AllShape
{
private:
    int Radius;

public:
    void SetRadius(float MainRadius)
    {
        Radius = MainRadius;
    }

    int GetRadius()
    {
        return Radius;
    }
};

class CircleShape : public AllShape
{
public:
    float CircleArea()
    {
       return PI*GetRadius()*GetRadius();
    }
};

int main()
{
    CircleShape Circle[25];
    int i,NumberCircle;
    float MainRadius;

    cout<<"Enter the numbers of the Circles : ";
    cin>>NumberCircle;
    cout<<endl;

    for(i=0 ; i<NumberCircle ; i++)
    {
        cout<<"Enter the Radius of the circle "<<i+1<<" : ";
        cin>>MainRadius;

        Circle[i].SetRadius(MainRadius);
        cout<<"The area of the circle "<<i+1<<" is "<<Circle[i].CircleArea()<<endl<<endl;
    }

    cout<<endl<<"Created by Jashkumar - 24CE004"<<endl;
}
