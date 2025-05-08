#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Student {
private:
    string name;
    int marks;
    string grade;

public:
    Student(const string& n, int m, const string& g)
        : name(n), marks(m), grade(g) {}

    string getName() const { return name; }
    int getMarks() const { return marks; }
    string getGrade() const { return grade; }
};

int main() {
    ifstream file("students.txt");
    vector<Student> students;

    if (!file) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, grade;
        int marks;

        ss >> name >> marks >> grade;

        if (ss.fail()) {
            cerr << "Error reading line: " << line << endl;
            continue;
        }

        students.push_back(Student(name, marks, grade));
    }

    file.close();

    cout << "Student Name   Marks   Grade" << endl;
    for (const auto& student : students) {
        cout << student.getName() << "   " << student.getMarks() << "   " << student.getGrade() << endl;
    }

    return 0;
}