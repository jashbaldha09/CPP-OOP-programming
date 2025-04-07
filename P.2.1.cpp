#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length,width;
public:
    void setDimensions(int l,int w)
    {
        length=l;
        width=w;
    }
    int area()
    {
        return length*width;
    }
    int perimeter()
    {
        return 2*(length+width);
    }
};
int main()
{
    Rectangle rectangles[25];
    int l,w,i,n;

    cout<<"Enter the numbers of the Rectangle : ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<endl;
        cout<<"Enter the length of the rectangle "<<i+1<<": ";
        cin>>l;
        cout<<"Enter the width of the rectangle "<<i+1<<": ";
        cin>>w;
        rectangles[i].setDimensions(l,w);
        cout<<"Area of the rectangle "<<i+1<<" is "<<rectangles[i].area()<<endl;
        cout<<"Perimeter of the rectangle "<<i+1<<" is "<<rectangles[i].perimeter()<<endl;
    }
    cout<<endl<<"Created by Jashkumar - 24CE004"<<endl;
    return 0;
}
