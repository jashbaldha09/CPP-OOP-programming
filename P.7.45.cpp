#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    float marks1, marks2, marks3;
    float fee;

public:
    void inputStudent()
    {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter marks for Subject 1: ";
        cin >> marks1;
        cout << "Enter marks for Subject 2: ";
        cin >> marks2;
        cout << "Enter marks for Subject 3: ";
        cin >> marks3;
        cout << "Enter tuition fee: ";
        cin >> fee;
        cin.ignore();
    }

    void saveToFile()
    {
        ofstream outFile("P.7.45.txt", ios::app);
        outFile << name << " " << marks1 << " " << marks2 << " " << marks3 << " " << fee << endl;
        outFile.close();
    }

    void displayFormatted()
    {
        float total = marks1 + marks2 + marks3;
        float avg = total / 3.0;

        cout << left << setw(20) << name
             << right << setw(10) << fixed << setprecision(2) << marks1
             << setw(10) << marks2
             << setw(10) << marks3
             << setw(10) << avg
             << "   $" << setw(7) << fee << endl;
    }

    void readFromFile()
    {
        ifstream inFile("P.7.45.txt");

        if (!inFile)
        {
            cout << "Error opening file!" << endl;
            return;
        }

        cout << left << setw(20) << "Name"
             << right << setw(10) << "Sub1"
             << setw(10) << "Sub2"
             << setw(10) << "Sub3"
             << setw(10) << "Avg"
             << setw(10) << "Fee" << endl;

        cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;

        while (inFile >> name >> marks1 >> marks2 >> marks3 >> fee)
        {
            displayFormatted();
        }

        inFile.close();
    }
};

int main()
{
    int choice;
    Student s;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Records\n";
        cout << "3. Exit\n";
        cout << "Choose option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            s.inputStudent();
            s.saveToFile();
        }
        else if (choice == 2)
        {
            s.readFromFile();
        }

    } while (choice != 3);

    cout << "System exited!";
    cout << endl << "Created by Jashkumar : 24CE004" << endl;
    return 0;
}
