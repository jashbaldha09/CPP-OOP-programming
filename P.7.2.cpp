#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int countCharacters = 0;
    int countWords = 0;
    int countLines = 0;
    string filename = "P.7.2.txt";
    ifstream inputFile(filename);
    char ch;
    bool inWord = false;

    if (!inputFile) {
        cerr << "Unable to open file: " << filename << endl;
        return 1;
    }

    cout << "File content:\n";

    while (inputFile.get(ch)) {
        cout << ch;
        countCharacters++;

        if (ch == '\n') {
            countLines++;
        }

        if (ch != ' ' && ch != '\n' && ch != '\t') {
            if (!inWord) {
                inWord = true;
                countWords++;
            }
        } else {
            inWord = false;
        }
    }

    inputFile.close();

    if (countCharacters > 0 && countLines == 0) {
        countLines = 1;
    }

    cout << "\n--- Statistics ---" << endl;
    cout << "Number of characters: " << countCharacters << endl;
    cout << "Number of words: " << countWords << endl;
    cout << "Number of lines: " << countLines+1 << endl;

    cout << "\nNijal bhanderi 24ce009" << endl;
    return 0;
}
