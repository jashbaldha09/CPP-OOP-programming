#include<iostream>
using namespace std;

class Complex {
private:
    int Imaginary, Real;

public:
    Complex(int MainImaginary = 0, int MainReal = 0) : Imaginary(MainImaginary), Real(MainReal) {}

    void read() {
        cout << "Enter Real Part: ";
        cin >> Real;
        cout << "Enter Imaginary Part: ";
        cin >> Imaginary;
    }

    Complex operator+(Complex Obj) {
        Complex Add;
        Add.Imaginary = Imaginary + Obj.Imaginary;
        Add.Real = Real + Obj.Real;
        return Add;
    }

    Complex operator-(Complex Obj) {
        Complex Sub;
        Sub.Imaginary = Imaginary - Obj.Imaginary;
        Sub.Real = Real - Obj.Real;
        return Sub;
    }

    void display() {
        cout << Real << " + i(" << Imaginary << ")" << endl;
    }
};

int main() {
    Complex c1, c2, sum, diff;

    cout << "Enter first complex number:" << endl;
    c1.read();

    cout << endl << "Enter second complex number:" << endl;
    c2.read();

    sum = c1 + c2;
    diff = c1 - c2;

    cout << endl << "+ Result: ";
    sum.display();

    cout << "- Result: ";
    diff.display();

    cout << endl << "Created by Jashkumar - 24CE004" << endl;

    return 0;
}