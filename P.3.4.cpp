#include <iostream>
using namespace std;

// Template to display array
template <typename T>
void display(T* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Template to find maximum value
template <typename T>
T findMax(T* arr, int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

// Template to reverse the array
template <typename T>
void reverse(T* arr, int size) {
    for (int i = 0; i < size / 2; i++)
        swap(arr[i], arr[size - 1 - i]);
}

// Test the templates
int main() {
    int intArr[4] = {5, 3, 9, 1};
    float floatArr[4] = {2.3, 5.6, 1.1, 4.4};
    char charArr[4] = {'d', 'a', 'c', 'b'};

    int intSize = sizeof(intArr)/sizeof(intArr[0]);
    int floatSize = sizeof(floatArr)/sizeof(floatArr[0]);
    int charSize = sizeof(charArr)/sizeof(charArr[0]);

    cout << "Original int array: ";
    display(intArr, intSize);
    cout << "Max: " << findMax(intArr, intSize) << endl;
    reverse(intArr, intSize);
    cout << "Reversed: ";
    display(intArr, intSize);

    cout << "\nOriginal float array: ";
    display(floatArr, floatSize);
    cout << "Max: " << findMax(floatArr, floatSize) << endl;
    reverse(floatArr, floatSize);
    cout << "Reversed: ";
    display(floatArr, floatSize);

    cout << "\nOriginal char array: ";
    display(charArr, charSize);
    cout << "Max: " << findMax(charArr, charSize) << endl;
    reverse(charArr, charSize);
    cout << "Reversed: ";
    display(charArr, charSize);

    cout<<endl<<"Created by Jashkumar - 24CE004"<<endl;

    return 0;
}
