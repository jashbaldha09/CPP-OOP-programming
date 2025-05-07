#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    char ch;
    string paragraph;
    string words[1000];
    int wordCount[1000] = {0};
    int wordIndex = 0;

    cout << "Enter your paragraph (end with '#'): " << endl;

    while ((ch = getchar()) != '#') {
        paragraph += tolower(ch);
    }

    string currentWord = "";

    for (int i = 0; i < paragraph.length(); i++) {
        ch = paragraph[i];
        if (isspace(ch)) {
            if (!currentWord.empty()) {
                bool found = false;
                for (int j = 0; j < wordIndex; j++) {
                    if (words[j] == currentWord) {
                        wordCount[j]++;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    words[wordIndex] = currentWord;
                    wordCount[wordIndex] = 1;
                    wordIndex++;
                }
                currentWord = "";
            }
        } else if (isalnum(ch)) {
            currentWord += ch;
        }
    }

    if (!currentWord.empty()) {
        bool found = false;
        for (int j = 0; j < wordIndex; j++) {
            if (words[j] == currentWord) {
                wordCount[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            words[wordIndex] = currentWord;
            wordCount[wordIndex] = 1;
            wordIndex++;
        }
    }

    cout << endl << "--- Statistics ---" << endl;
    cout << "Words: " << wordIndex << endl;

    for (int i = 0; i < wordIndex; i++) {
        cout << words[i] << ": " << wordCount[i] << endl;
    }

    cout << endl << "Created by Jashkumar : 24CE004" << endl;

    return 0;
}
