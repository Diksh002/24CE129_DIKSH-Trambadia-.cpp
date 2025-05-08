#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
private:
    string name;
    int score;

public:
    Student(const string& n, int s) : name(n), score(s) {}

    string getName() const {
        return name;
    }

    int getScore() const {
        return score;
    }

    void setName(const string& n) {
        name = n;
    }

    void setScore(int s) {
        score = s;
    }
};

void inputStudents(int n, vector<Student>& students) {
    cout << "Enter student name and score:" << endl;
    for (int i = 0; i < n; ++i) {
        string name;
        int score;
        cin >> name >> score;
        students.push_back(Student(name, score));
    }
}

void displayRankedStudents(const vector<Student>& students) {
    cout << "Ranked list of students:" << endl;
    int rank = 1;
    for (const auto& student : students) {
        cout << rank << ". " << student.getName() << " - " << student.getScore() << endl;
        ++rank;
    }
}

void sortStudentsByScore(vector<Student>& students) {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getScore() > b.getScore();
    });
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students;
    inputStudents(n, students);
    sortStudentsByScore(students);
    displayRankedStudents(students);

    return 0;
}