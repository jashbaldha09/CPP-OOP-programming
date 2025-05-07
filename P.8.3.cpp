#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int n, value;
    set<int> transactionIDs;

    cout << "Enter number of transaction IDs: ";
    cin >> n;

    cout << "Enter " << n << " transaction IDs:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        transactionIDs.insert(value);
    }

    vector<int> uniqueTransactions(transactionIDs.begin(), transactionIDs.end());

    cout << "\nUnique sorted transaction IDs: ";
    for (int i = 0; i < uniqueTransactions.size(); i++)
    {
        cout << uniqueTransactions[i] << " ";
    }
    cout << endl;

    cout << "\nCreated by Jashkumar : 24CE004\n";
    return 0;
}

