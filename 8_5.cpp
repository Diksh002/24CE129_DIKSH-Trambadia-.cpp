#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class DirectoryManager {
private:
    map<string, vector<string>> directory;

public:
    void addFolder(const string& folderName) {
        if (directory.find(folderName) == directory.end()) {
            directory[folderName];
            cout << "Folder '" << folderName << "' added successfully!" << endl;
        } else {
            cout << "Folder '" << folderName << "' already exists." << endl;
        }
    }

    void addFileToFolder(const string& folderName, const string& fileName) {
        if (directory.find(folderName) != directory.end()) {
            directory[folderName].push_back(fileName);
            cout << "File '" << fileName << "' added to folder '" << folderName << "'." << endl;
        } else {
            cout << "Error: Folder '" << folderName << "' does not exist!" << endl;
        }
    }

    void displayDirectory() {
        cout << "\nDirectory Structure:" << endl;
        if (directory.empty()) {
            cout << "No folders to display." << endl;
            return;
        }

        for (auto& folder : directory) {
            cout << "Folder: " << folder.first << endl;
            vector<string> files = folder.second;
            sort(files.begin(), files.end());
            for (const string& file : files) {
                cout << "  - " << file << endl;
            }
        }
    }
};

int main() {
    DirectoryManager dm;
    int choice;
    string folderName, fileName;

    do {
        cout << "\n1. Add Folder\n2. Add File to Folder\n3. Display Directory\n4. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter folder name: ";
                getline(cin, folderName);
                dm.addFolder(folderName);
                break;

            case 2:
                cout << "Enter folder name: ";
                getline(cin, folderName);
                cout << "Enter file name: ";
                getline(cin, fileName);
                dm.addFileToFolder(folderName, fileName);
                break;

            case 3:
                dm.displayDirectory();
                break;

            case 4:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}