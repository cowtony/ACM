#include <iostream>
#include <vector>
using namespace std;

enum Grade {
    C,
    A,
    B,
    D,
    FAIL,
    A_PLUS,
};

struct Student {
    string name;
    int id;
    Grade grade;
};


int main() {
    int student_size = 12;

    vector<Student> students(student_size);
    for (int i = 0; i < student_size; i++) {
        students[i].name = "name";
        students[i].id = i;
        students[i].grade = Grade::FAIL;
    }


    for (const Student& s : students) {
        cout << s.name << "\t" << s.id << '\t' << s.grade << endl;
    }

}
