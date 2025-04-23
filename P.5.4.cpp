#include <iostream>
using namespace std;

class Fahrenheit;
class Celsius
{
public:
    float c;

    Celsius(float temp = 0)
    {
        c = temp;
    }

    Fahrenheit toFahrenheit();

    void show()
    {
        cout << c << "C" << endl;
    }
};

class Fahrenheit
{
public:
    float f;

    Fahrenheit(float temp = 0)
    {
        f = temp;
    }

    Celsius toCelsius()
    {
        float converted = (f - 32) * 5 / 9;
        return Celsius(converted);
    }

    void show()
    {
        cout << f << "F" << endl;
    }
};

Fahrenheit Celsius :: toFahrenheit()
{
        float converted = (c * 9 / 5) + 32;
        return Fahrenheit(converted);
}

int main()
{
    float temp;
    int choice;

    while (true)
    {
        cout << "\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Exit\nEnter choice (1-3): ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter temperature in Celsius: ";
            cin >> temp;
            Celsius c(temp);
            Fahrenheit f = c.toFahrenheit();
            cout << "Converted: ";
            f.show();
        }
        else if (choice == 2)
        {
            cout << "Enter temperature in Fahrenheit: ";
            cin >> temp;
            Fahrenheit f(temp);
            Celsius c = f.toCelsius();
            cout << "Converted: ";
            c.show();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
    cout<<endl<<"Created by Jashkumar : 24CE004"<<endl;
    return 0;
}
