#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to add product
void addProduct() {
    ofstream file("inventory.txt", ios::app); // Open file in append mode
    string name;
    int qty;
    float price;

    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter quantity: ";
    cin >> qty;
    cout << "Enter price: ";
    cin >> price;

    file << name << " " << qty << " " << price << endl; // Save product data
    file.close();
}

// Function to view all products
void viewInventory() {
    ifstream file("inventory.txt"); // Open file to read
    string name;
    int qty;
    float price;

    while (file >> name >> qty >> price) {
        cout << "Product: " << name << ", Quantity: " << qty << ", Price: $" << price << endl;
    }
    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Product\n2. View Inventory\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            addProduct();
        } 
        else if (choice == 2) {
            viewInventory();
        }

    } while (choice != 3);

    return 0;
}