#include <iostream>
#include <vector>
#include <string>

// Custom manipulator to format currency
std::ostream& currency(std::ostream& os) {
    return os << "₹";  // You can replace ₹ with $, £, etc.
}

class Student {
private:
    std::string name;
    int marks;
    double tuitionFee;

public:
    // Constructor to initialize student data
    Student(const std::string& n, int m, double fee) 
        : name(n), marks(m), tuitionFee(fee) {}

    // Getters
    std::string getName() const { return name; }
    int getMarks() const { return marks; }
    double getTuitionFee() const { return tuitionFee; }
};

// Function to display student data with formatting
void displayStudentData(const std::vector<Student>& students) {
    std::cout << "Student Name - Marks - Tuition Fee" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    for (const auto& student : students) {
        std::cout << student.getName() << " - " 
                  << student.getMarks() << " - " << currency(std::cout) << student.getTuitionFee() << std::endl;
                  
    }
}

int main() {
    std::vector<Student> students;
    int numStudents;

    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    // Input student data
    for (int i = 0; i < numStudents; ++i) {
        std::string name;
        int marks;
        double tuitionFee;

        std::cin.ignore();  // To clear the newline character from the buffer

        std::cout << "Enter name of student #" << i + 1 << ": ";
        std::getline(std::cin, name);  // Allow spaces in the name

        std::cout << "Enter marks for " << name << ": ";
        std::cin >> marks;

        std::cout << "Enter tuition fee for " << name << ": ₹";
        std::cin >> tuitionFee;

        // Create Student object and add it to the vector
        students.push_back(Student(name, marks, tuitionFee));
    }

    // Display the formatted student data
    displayStudentData(students);

    return 0;
}