#include <iostream>
#include <vector>
using namespace std;

class Product {
private:
    int productID;
    string name;
    int quantity;
    double price;

public:
    Product() {
        productID = 0;
        name = "Unknown";
        quantity = 0;
        price = 0.0;
    }

    void setDetails(int id, string n, int q, double p) {
        productID = id;
        name = n;
        quantity = q;
        price = p;
    }

    void updateQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    double calculateTotalValue() const {
        return quantity * price;
    }

    void displayProduct() const {
        cout << "ID: " << productID << ", Name: " << name << ", Quantity: " << quantity << ", Price: " << price << endl;
    }

    int getProductID() const {
        return productID;
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct() {
        Product p;
        int id, quantity;
        string name;
        double price;

        cout << "Enter Product ID, Name, Quantity, and Price: ";
        cin >> id >> name >> quantity >> price;
        p.setDetails(id, name, quantity, price);
        products.push_back(p);
    }

    void updateProductQuantity() {
        int id, newQuantity;
        cout << "Enter Product ID and new Quantity: ";
        cin >> id >> newQuantity;

        for (Product &product : products) {
            if (product.getProductID() == id) {
                product.updateQuantity(newQuantity);
                cout << "Product quantity updated successfully!" << endl;
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    void calculateTotalInventoryValue() {
        double totalValue = 0;
        for (const Product &product : products) {
            totalValue += product.calculateTotalValue();
        }
        cout << "Total Inventory Value: " << totalValue << endl;
    }

    void displayInventory() {
        for (const Product &product : products) {
            product.displayProduct();
        }
    }
};

int main() {
    Inventory storeInventory;
    int choice;

    do {
        cout << "\n1. Add Product\n2. Update Quantity\n3. Display Inventory\n4. Calculate Total Value\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                storeInventory.addProduct();
                break;
            case 2:
                storeInventory.updateProductQuantity();
                break;
            case 3:
                storeInventory.displayInventory();
                break;
            case 4:
                storeInventory.calculateTotalInventoryValue();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    cout<<endl<<"24CE129 _ DIKSH Trambadia";

    return 0;
}