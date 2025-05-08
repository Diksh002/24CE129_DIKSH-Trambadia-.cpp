#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> vec(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    // Use std::reverse with vector iterators
    reverse(vec.begin(), vec.end());

    cout << "Reversed sequence:\n";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> vec(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    // Use std::reverse with vector iterators
    reverse(vec.begin(), vec.end());

    cout << "Reversed sequence:\n";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}