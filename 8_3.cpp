#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, num;
    set<int> uniqueIDs;

    cout << "Enter number of transaction IDs: ";
    cin >> n;

    cout << "Enter the transaction IDs:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        uniqueIDs.insert(num);  // Automatically removes duplicates
    }

    cout << "Unique transaction IDs in sorted order:" << endl;
    for (set<int>::iterator it = uniqueIDs.begin(); it != uniqueIDs.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}