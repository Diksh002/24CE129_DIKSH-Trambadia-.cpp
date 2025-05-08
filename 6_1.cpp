#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        
        delete[] arr;
        arr = newArr;
    }

public:
    DynamicArray() : size(0), capacity(2) {
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void addElement(int value) {
        if (size == capacity) resize();
        arr[size++] = value;
    }

    void removeElement(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        }
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty.\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr;
    int choice, value, index;

    while (true) {
        cout << "1. Add element\n2. Remove element\n3. Display array\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to add: ";
            cin >> value;
            arr.addElement(value);
        } else if (choice == 2) {
            cout << "Enter index to remove: ";
            cin >> index;
            arr.removeElement(index);
        } else if (choice == 3) {
            cout << "Array elements: ";
            arr.display();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}