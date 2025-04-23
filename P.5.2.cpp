#include<iostream>
using namespace std;

class Complex {
private:
    int Imaginary, Real;

public:
    Complex(int MainImaginary = 0, int MainReal = 0) : Imaginary(MainImaginary), Real(MainReal) {}

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

    friend ostream& operator<<(ostream& out, const Complex& c);

    friend istream& operator>>(istream& in, Complex& c);
};

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.Real << " + i(" << c.Imaginary<<")";
    return out;
}

istream& operator>>(istream& in, Complex& c) {
    cout << "Enter Real Part: ";
    in >> c.Real;
    cout << "Enter Imaginary Part: ";
    in >> c.Imaginary;
    return in;
}

int main() {
    Complex c1, c2, sum, diff;

    cout << "Enter first complex number:\n";
    cin >> c1;

    cout << "\nEnter second complex number:\n";
    cin >> c2;

    sum = c1 + c2;
    diff = c1 - c2;

    cout << "\n+ Overloading: " << sum << endl;
    cout << "- Overloading: " << diff << endl;

    cout<<endl<<"Created by Jashkumar - 24CE004"<<endl;

    return 0;
}
