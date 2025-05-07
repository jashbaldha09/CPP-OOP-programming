#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DynamicArray() {
        capacity = 2;
        size = 0;
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void insert(int value) {
        if (size == capacity) {
            resize();
        }
        data[size] = value;
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return;
        }
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void display() {
        cout << "Array: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray* arr = new DynamicArray;
    int choice, value, index;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                arr->insert(value);
                break;
            case 2:
                cout << "Enter index to delete: ";
                cin >> index;
                arr->remove(index);
                break;
            case 3:
                arr->display();
                break;
            case 4:
                delete arr;
                cout << endl << "Created by Jashkumar : 24CE004" << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}

