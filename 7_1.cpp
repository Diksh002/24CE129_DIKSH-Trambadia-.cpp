#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string word;
    map<string, int> wordCount;

    cout << "Enter words one by one (type 'end' to stop):\n";
    while (true) {
        cin >> word;

        if (word == "end") {
            break;
        }

        for (char &ch : word) {
            ch = tolower(ch);
        }

        wordCount[word]++;
    }

    cout << "\nWord frequencies:\n";
    for (const auto &entry : wordCount) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}