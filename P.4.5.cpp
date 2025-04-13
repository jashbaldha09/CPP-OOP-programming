#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int marks;

public:
    Student(string n, int m) : name(n), marks(m) {}

    virtual void ComputeGrade() = 0;

    void Display() {
        cout << "Name: " << name << "\n";
        ComputeGrade();
        cout << "Marks: " << marks << "\n\n";
    }

    virtual ~Student() {}
};

class Undergraduate : public Student {
public:
    Undergraduate(string n, int m) : Student(n, m) {}

    void ComputeGrade() override {
        cout << "Grade: ";
        if (marks >= 90) cout << "A\n";
        else if (marks >= 80) cout << "B\n";
        else if (marks >= 70) cout << "C\n";
        else if (marks >= 60) cout << "D\n";
        else cout << "F\n";
    }
};

class Postgraduate : public Student {
public:
    Postgraduate(string n, int m) : Student(n, m) {}

    void ComputeGrade() override {
        cout << "Grade: ";
        if (marks >= 85) cout << "A\n";
        else if (marks >= 75) cout << "B\n";
        else if (marks >= 65) cout << "C\n";
        else cout << "F\n";
    }
};

int main() {
    vector<Student*> students;
    int ugCount, pgCount;
    string name;
    int marks;

    cout << "Enter number of Undergraduate students: ";
    cin >> ugCount;

    for (int i = 0; i < ugCount; i++) {
        cout << "\nEnter UG student " << i + 1 << " name: ";
        cin >> name;
        cout << "Enter marks: ";
        cin >> marks;
        students.push_back(new Undergraduate(name, marks));
    }

    cout << "\nEnter number of Postgraduate students: ";
    cin >> pgCount;

    for (int i = 0; i < pgCount; i++) {
        cout << "\nEnter PG student " << i + 1 << " name: ";
        cin >> name;
        cout << "Enter marks: ";
        cin >> marks;
        students.push_back(new Postgraduate(name, marks));
    }

    cout << "\n---- Student Results ----\n";
    for (int i = 0; i < students.size(); i++) {
        students[i]->Display();
    }

    for (int i = 0; i < students.size(); i++) {
        delete students[i];
    }

    cout<<endl<<"Created by Jashkumar : 24CE004"<<endl;

    return 0;
}
