#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person() {} 
    virtual ~Person() {}

    void setName(const string& n) { name = n; }
    string getName() const { return name; }

    virtual void display() const {
        cout << "Name: " << name << endl;
    }
};


class Student : public Person {
private:
    string course;
    int marks;
    int year;

public:
    Student() : marks(0), year(0) {}

    void setCourse(const string& c) { course = c; }
    string getCourse() const { return course; }

    void setMarks(int m) { marks = m; }
    int getMarks() const { return marks; }

    void setYear(int y) { year = y; }
    int getYear() const { return year; }

    void display() const override {
        cout << "Student Details:" << endl;
        Person::display();
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};

class Employee : public Person {
private:
    string department;
    double salary;

public:
    Employee() : salary(0.0) {}

    void setDepartment(const string& d) { department = d; }
    string getDepartment() const { return department; }

    void setSalary(double s) { salary = s; }
    double getSalary() const { return salary; }

    void display() const override {
        cout << "Employee Details:" << endl;
        Person::display();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {

    Student* s = new Student();
    string temp;
    int intVal;
    double doubleVal;

    cout << "Enter Student Name: ";
    getline(cin, temp);
    s->setName(temp);

    cout << "Enter Course: ";
    getline(cin, temp);
    s->setCourse(temp);

    cout << "Enter Marks: ";
    cin >> intVal;
    s->setMarks(intVal);

    cout << "Enter Year: ";
    cin >> intVal;
    s->setYear(intVal);
    cin.ignore();

    Employee* e = new Employee();

    cout << "\nEnter Employee Name: ";
    getline(cin, temp);
    e->setName(temp);

    cout << "Enter Department: ";
    getline(cin, temp);
    e->setDepartment(temp);

    cout << "Enter Salary: ";
    cin >> doubleVal;
    e->setSalary(doubleVal);

    Person* p1 = s;
    Person* p2 = e;

    cout << "\nDisplaying Student via base pointer:\n";
    p1->display();

    cout << "\nDisplaying Employee via base pointer:\n";
    p2->display();

    delete s;
    delete e;

    return 0;
}