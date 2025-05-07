#include <iostream>
using namespace std;

int main()
{
    char ch;
    string paragraph;
    string words[1000];        // Array to store unique words
    int wordCount[1000] = {0}; // Array to store the count of each word
    int wordIndex = 0;         // To keep track of unique words

    cout << "Enter your paragraph (end with '#'): " << endl;

    // Read paragraph until '#' is entered
    while ((ch = getchar()) != '#')
    {
        paragraph += ch; // Add each character to paragraph
    }

    // Convert paragraph to lowercase
    for (int i = 0; i < paragraph.length(); i++)
    {
        if (paragraph[i] >= 'A' && paragraph[i] <= 'Z')
        {
            paragraph[i] = paragraph[i] + ('a' - 'A');
        }
    }

    // Process each word
    string currentWord = ""; // To build each word

    for (int i = 0; i < paragraph.length(); i++)
    {
        ch = paragraph[i];

        // If space, newline, or tab, treat as word separator
        if (ch == ' ' || ch == '\n' || ch == '\t')
        {
            if (!currentWord.empty())
            {
                bool found = false;

                // Check if word already exists
                for (int j = 0; j < wordIndex; j++)
                {
                    if (words[j] == currentWord)
                    {
                        wordCount[j]++;
                        found = true;
                        break;
                    }
                }

                // If word not found, add it
                if (!found)
                {
                    words[wordIndex] = currentWord;
                    wordCount[wordIndex] = 1;
                    wordIndex++;
                }

                currentWord = ""; // Reset for next word
            }
        }
        else
        {
            currentWord += ch; // Add character to current word
        }
    }

    //Handle last word (if not followed by space)
    if (!currentWord.empty())
    {
        bool found = false;

        for (int j = 0; j < wordIndex; j++)
        {
            if (words[j] == currentWord)
            {
                wordCount[j]++;
                found = true;
                break;
            }
        }

        if (!found)
        {
            words[wordIndex] = currentWord;
            wordCount[wordIndex] = 1;
            wordIndex++;
        }
    }

    //Print results
    cout << endl << "--- Statistics ---" << endl;
    cout << "Words: " << wordIndex << endl;

    for (int i = 0; i < wordIndex; i++)
    {
        cout << words[i] << ": " << wordCount[i] << endl;
    }

    cout << endl <<"Created by Jashkumar : 24CE004"<< endl;

    return 0;
}
