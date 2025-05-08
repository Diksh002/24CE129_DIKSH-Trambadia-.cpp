#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    map<string, int> wordFrequency;
    stringstream ss(sentence);
    string word;

    while (ss >> word) {
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return ispunct(c);
        }), word.end());

        for (char &c : word) {
            c = tolower(c);
        }

        wordFrequency[word]++;
    }

    for (map<string, int>::iterator it = wordFrequency.begin(); it != wordFrequency.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}