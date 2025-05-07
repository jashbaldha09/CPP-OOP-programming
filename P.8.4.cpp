#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip> // for setw
using namespace std;

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<string> names(n);
    vector<int> scores(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> names[i];
        cout << "Enter score of " << names[i] << ": ";
        cin >> scores[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (scores[j] > scores[i])
            {
                swap(scores[i], scores[j]);
                swap(names[i], names[j]);
            }
        }
    }

    cout << endl << "--- Student Ranking ---" << endl;
    cout << left << setw(10) << "Rank" << setw(20) << "Name" << setw(10) << "Score" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << setw(10) << i + 1 << setw(20) << names[i] << setw(10) << scores[i] << endl;
    }

    cout << endl << "Created by Jashkumar : 24CE004" << endl;
    return 0;
}

