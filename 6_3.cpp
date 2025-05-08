#include <iostream>
using namespace std;

class SortedArrayMerger {
private:
    int* arr1;
    int* arr2;
    int size1;
    int size2;

public:
    SortedArrayMerger(int s1, int s2) : size1(s1), size2(s2) {
        arr1 = new int[size1];
        arr2 = new int[size2];
    }

    ~SortedArrayMerger() {
        delete[] arr1;
        delete[] arr2;
    }

    void inputArrays() {
        cout << "Enter the elements of first sorted array: ";
        for (int i = 0; i < size1; i++) {
            cin >> arr1[i];
        }

        cout << "Enter the elements of second sorted array: ";
        for (int i = 0; i < size2; i++) {
            cin >> arr2[i];
        }
    }

    void mergeSortedArrays() {
        int* mergedArr = new int[size1 + size2];
        int i = 0, j = 0, k = 0;

        while (i < size1 && j < size2) {
            if (arr1[i] < arr2[j]) {
                mergedArr[k++] = arr1[i++];
            } else {
                mergedArr[k++] = arr2[j++];
            }
        }

        while (i < size1) {
            mergedArr[k++] = arr1[i++];
        }

        while (j < size2) {
            mergedArr[k++] = arr2[j++];
        }

        cout << "Merged Sorted Array: ";
        for (int i = 0; i < size1 + size2; i++) {
            cout << mergedArr[i] << " ";
        }
        cout << endl;

        delete[] mergedArr;
    }
};

int main() {
    int size1, size2;

    cout << "Enter the size of first array: ";
    cin >> size1;
    cout << "Enter the size of second array: ";
    cin >> size2;

    SortedArrayMerger merger(size1, size2);
    merger.inputArrays();
    merger.mergeSortedArrays();

    return 0;
}