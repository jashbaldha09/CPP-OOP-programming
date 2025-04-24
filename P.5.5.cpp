#include <iostream>
#include <vector>
#define PI 3.14
using namespace std;

class Shape
{
public:
    virtual double Area() = 0;
};

class Rectangle : public Shape
{
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double Area()
    {
        return length * width;
    }
};

class Circle : public Shape
{
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double Area()
    {
        return PI * radius * radius;
    }
};

void DisplayAreas(vector<Shape*>& shapes)
{
    for (int i = 0; i < shapes.size(); i++)
    {
        cout << "Shape " << i + 1 << " Area: " << shapes[i]->Area() << endl;
    }
}

int main()
{
    vector<Shape*> shapes;

    shapes.push_back(new Rectangle(8.0, 4.0));
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(3.5, 6.2));
    shapes.push_back(new Circle(2.3));

    DisplayAreas(shapes);

    for (int i = 0; i < shapes.size(); i++)
    {
            delete shapes[i];
    }

    cout<<endl<<"Created by Jashkumar : 24CE004"<<endl;
    return 0;
}
