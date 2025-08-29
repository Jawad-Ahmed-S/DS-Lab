#include <iostream>
using namespace std;

int main() {
    int noStudents;
    int* noCourses;
    int** marks;

    cout << "Enter the number of students" << endl;
    cin >> noStudents;

    noCourses = new int[noStudents];
    for (int i = 0; i < noStudents; i++) {
        cout << "Enter number of courses for student " << i + 1 << ": " << endl;
        cin >> noCourses[i];
    }

    cout << "Number of courses noted!" << endl;

    marks = new int* [noStudents];
    for (int i = 0; i < noStudents; i++) {
        marks[i] = new int[noCourses[i]];
    }

    for (int i = 0; i < noStudents; i++) {
        for (int j = 0; j < noCourses[i]; j++) {
            cout << "Enter marks of student " << i + 1 << ": course " << j + 1 << endl;
            cin >> marks[i][j];
        }
    }

    int* averageMarks = new int[noStudents]();  

    for (int i = 0; i < noStudents; i++) {
        for (int j = 0; j < noCourses[i]; j++) {
            averageMarks[i] += marks[i][j];
        }
        averageMarks[i] /= noCourses[i];  
    }

    for (int i = 0; i < noStudents; i++) {
        cout << "Average marks of Student " << i + 1 << ": " << averageMarks[i] << endl;
    }

    delete[] averageMarks;
    delete[] noCourses;
    for (int i = 0; i < noStudents; i++) {
        delete[] marks[i];
    }
    delete[] marks;

    return 0;
}
