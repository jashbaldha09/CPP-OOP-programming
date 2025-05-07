#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor called." << endl;
    }

    virtual ~Base() {
        cout << "Base destructor called." << endl;
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        data = new int[5];
        cout << "Derived constructor: Memory allocated." << endl;
    }

    ~Derived() {
        delete[] data;
        cout << "Derived destructor: Memory deallocated." << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;
    cout<<endl<<"Created by Jashkumar : 24CE004"<<endl;
    return 0;
}

