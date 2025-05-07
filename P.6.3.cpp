#include <iostream>
using namespace std;

class SortedArrayMerger {
private:
    int* arr1;
    int* arr2;
    int* merged;
    int size1, size2;

public:
    SortedArrayMerger(int s1, int s2) {
        size1 = s1;
        size2 = s2;

        arr1 = new int[size1];
        arr2 = new int[size2];
        merged = new int[size1 + size2];
    }

    ~SortedArrayMerger() {
        delete[] arr1;
        delete[] arr2;
        delete[] merged;
    }

    void inputArrays() {
        cout << "Enter elements of the first array: ";
        for (int i = 0; i < size1; i++) {
            cin >> arr1[i];
        }

        cout << "Enter elements of the second array: ";
        for (int i = 0; i < size2; i++) {
            cin >> arr2[i];
        }
    }

    void mergeArrays() {
        int i = 0, j = 0, k = 0;

        while (i < size1 && j < size2) {
            if (arr1[i] < arr2[j]) {
                merged[k++] = arr1[i++];
            } else {
                merged[k++] = arr2[j++];
            }
        }

        while (i < size1) {
            merged[k++] = arr1[i++];
        }

        while (j < size2) {
            merged[k++] = arr2[j++];
        }
    }

    void displayMergedArray() {
        cout << "Merged array: ";
        for (int i = 0; i < size1 + size2; i++) {
            cout << merged[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size1, size2;

    cout << "Enter the size of the first sorted array: ";
    cin >> size1;
    cout << "Enter the size of the second sorted array: ";
    cin >> size2;

    SortedArrayMerger merger(size1, size2);

    merger.inputArrays();
    merger.mergeArrays();
    merger.displayMergedArray();

    cout << endl << "Created by Jashkumar : 24CE004" << endl;
    return 0;
}
