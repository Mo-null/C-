#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    string studentClass;
    int year;
    int totalMarks;

public:
    Student() = default;

    void setRollNo(int roll) { rollNo = roll; }
    int getRollNo() const { return rollNo; }

    void setName(const string& n) { name = n; }
    string getName() const { return name; }

    void setClass(const string& cls) { studentClass = cls; }
    string getStudentClass() const { return studentClass; }

    void setYear(int y) { year = y; }
    int getYear() const { return year; }

    void setTotalMarks(int marks) { totalMarks = marks; }
    int getTotalMarks() const { return totalMarks; }

    void display() const {
        cout << "Roll No.: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Year: " << year << endl;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "-------------------------" << endl;
    }

    void writeToFile(ofstream& outFile) const {
    outFile << "Roll No.: " << rollNo << '\n'
            << "Name: " << name << '\n'
            << "Class: " << studentClass << '\n'
            << "Year: " << year << '\n'
            << "Total Marks: " << totalMarks << "\n\n";
}

    void readFromFile(ifstream& inFile) {
        inFile >> rollNo;
        inFile.ignore();
        getline(inFile, name);
        getline(inFile, studentClass);
        inFile >> year >> totalMarks;
    }
};

int main() {
    Student students[5];

    for (int i = 0; i < 5; i++) {
        int roll, year, marks;
        string name, cls;

        cout << "Enter details for Student " << i + 1 << ":\n";
        cout << "Roll No.: ";  cin >> roll;
        cin.ignore();
        cout << "Name: ";      getline(cin, name);
        cout << "Class: ";     getline(cin, cls);
        cout << "Year: ";      cin >> year;
        cout << "Total Marks: "; cin >> marks;
        cout << endl;

        students[i].setRollNo(roll);
        students[i].setName(name);
        students[i].setClass(cls);
        students[i].setYear(year);
        students[i].setTotalMarks(marks);
    }

    ofstream outFile("students.txt");
    if (!outFile) {
        cerr << "Error opening file for writing!\n";
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        students[i].writeToFile(outFile);
    }
    outFile.close();

    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!\n";
        return 1;
    }
    Student retrievedStudents[5];
    for (int i = 0; i < 5; i++) {
        retrievedStudents[i].readFromFile(inFile);
    }
    inFile.close();

    cout << "\nRetrieved Student Records:\n";
    for (int i = 0; i < 5; i++) {
        retrievedStudents[i].display();
    }

    return 0;
}
// type "C:\Users\Mohammed\OneDrive\Desktop\students.txt"