#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;

    ifstream file(fileName);

    if (!file) {
        cout << "Error: Unable to open file " << fileName << endl;
        return 1;
    }

    string line;
    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;

    while (getline(file, line)) {
        lineCount++;

        stringstream ss(line);
        string word;
        while (ss >> word) {
            wordCount++;
        }

        charCount += line.length();
    }

    cout << "Total Lines: " << lineCount << endl;
    cout << "Total Words: " << wordCount << endl;
    cout << "Total Characters (including spaces and punctuation): " << charCount << endl;

    file.close();
    return 0;
}