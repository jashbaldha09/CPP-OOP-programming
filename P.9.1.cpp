#include <iostream>
#include <stdexcept>
using namespace std;

class LoanAnalyzer {
public:
    double readAmount(const string& label) {
        double amount;
        cout << "Enter " << label << ": ";
        cin >> amount;

        if (cin.fail()) {
            throw invalid_argument("Input must be a valid number.");
        }
        return amount;
    }

    void calculateRatio() {
        double loan = readAmount("Loan Amount");
        double income = readAmount("Annual Income");

        if (income == 0) {
            throw runtime_error("Income cannot be zero.");
        }

        double ratio = loan / income;
        cout << "Loan-to-Income Ratio: " << ratio << endl;
    }
};

int main() {
    LoanAnalyzer checker;

    try {
        checker.calculateRatio();
    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << endl << "Created by Jashkumar : 24CE004" << endl;
    return 0;
}
