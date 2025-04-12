#include <iostream>
using namespace std;

int DigitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int SuperDigit(int num) {
    if (num < 10)
        return num;

    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return SuperDigit(sum);
}

int main() {
    int Number, k;

    cout << "Enter the number (as integer): ";
    cin >> Number;

    cout << "Enter the value of k: ";
    cin >> k;

    int multiplied = DigitSum(Number) * k;
    int result = SuperDigit(multiplied);

    cout << "Super Digit: " << result << endl;
    cout<<endl<<"Created by Jashkumar : 24CE004"<<endl;

    return 0;
}
