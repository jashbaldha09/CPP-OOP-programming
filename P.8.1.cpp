#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseWithSTL(vector<int> v)
{
    reverse(v.begin(), v.end());

    cout << "Reversed using reverse(): ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void reverseManually(vector<int> v)
{
    vector<int> reversed;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        reversed.push_back(v[i]);
    }

    cout << "Reversed using manual loop: ";
    for (int i = 0; i < reversed.size(); i++)
    {
        cout << reversed[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> sequence;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        sequence.push_back(value);
    }

    reverseWithSTL(sequence);
    reverseManually(sequence);

    cout << "\nCreated by Jashkumar : 24CE004" << endl;
    return 0;
}

