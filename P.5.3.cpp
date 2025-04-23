#include <iostream>
using namespace std;

class Point
{
public:
    int x, y;

    Point(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }

    Point operator-()
    {
        return Point(-x, -y);
    }

    Point operator+(Point p)
    {
        return Point(x + p.x, y + p.y);
    }

    bool operator==(Point p)
    {
        return x == p.x && y == p.y;
    }

    void show()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    int x1, y1, x2, y2, choice;

    cout << "Enter coordinates for Point 1 (x y): ";
    cin >> x1 >> y1;

    cout << "Enter coordinates for Point 2 (x y): ";
    cin >> x2 >> y2;

    Point p1(x1, y1), p2(x2, y2);

    cout << "1. Negate the coordinates"<<endl;
    cout<<"2. Add two points"<<endl;
    cout<<"3. Check if two points are equal"<<endl;
    cout<<"4. Exit"<<endl;;
    while (true)
    {
        cin >> choice;

        if (choice == 1)
        {
            Point p = -p1;
            cout << "Negated Point 1: ";
            p.show();
        }
        else if (choice == 2)
        {
            Point p = p1 + p2;
            cout << "Result of p1 + p2: ";
            p.show();
        }
        else if (choice == 3)
        {
            if (p1 == p2)
                cout << "Both points are equal" << endl;
            else
                cout << "Points are not equal" << endl;
        }
        else if (choice == 4)
        {
            cout << "Exiting program" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }
    cout<<endl<<"Created by Jashkumar : 24CE004"<<endl;

    return 0;
}
