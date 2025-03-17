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
    // Default constructor
    Student() : rollNo(0), name(""), studentClass(""), year(0), totalMarks(0) {}

    // Parameterized constructor
    Student(int roll, const string& n, const string& cls, int y, int marks)
        : rollNo(roll), name(n), studentClass(cls), year(y), totalMarks(marks) {}

    // Function to display student details
    void display() const {
        cout << "Roll No.: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Year: " << year << endl;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "-------------------------" << endl;
    }

    // Function to write student details to a file
    void writeToFile(ofstream& outFile) const {
        outFile << rollNo << endl;
        outFile << name << endl;
        outFile << studentClass << endl;
        outFile << year << endl;
        outFile << totalMarks << endl;
    }

    // Function to read student details from a file
    void readFromFile(ifstream& inFile) {
        inFile >> rollNo;
        inFile.ignore(); // Ignore newline after rollNo
        getline(inFile, name);
        getline(inFile, studentClass);
        inFile >> year;
        inFile >> totalMarks;
    }
};

int main() {
    // Create an array of 5 Student objects
    Student students[5] = {
        Student(1, "Alice", "10th", 2023, 450),
        Student(2, "Bob", "11th", 2023, 480),
        Student(3, "Charlie", "9th", 2023, 430),
        Student(4, "David", "12th", 2023, 490),
        Student(5, "Eve", "10th", 2023, 460)
    };

    // Write student records to a file
    ofstream outFile("students.txt");
    if (!outFile) {
        cerr << "Error: Unable to open file for writing!" << endl;
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        students[i].writeToFile(outFile);
    }
    outFile.close();

    // Read student records from the file
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file for reading!" << endl;
        return 1;
    }

    Student retrievedStudents[5];
    for (int i = 0; i < 5; i++) {
        retrievedStudents[i].readFromFile(inFile);
    }
    inFile.close();

    // Display retrieved student records
    cout << "Retrieved Student Records:" << endl;
    for (int i = 0; i < 5; i++) {
        retrievedStudents[i].display();
    }

    return 0;
}
