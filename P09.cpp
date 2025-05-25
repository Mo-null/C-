#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(const string& n) : name(n) {}
    virtual ~Person() {}

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
    Student(const string& n, const string& c, int m, int y)
        : Person(n), course(c), marks(m), year(y) {}

    void display() const override {
        cout << "Student Details:" << endl;
        Person::display(); // Call base class display to show name
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
    Employee(const string& n, const string& d, double s)
        : Person(n), department(d), salary(s) {}

    void display() const override {
        cout << "Employee Details:" << endl;
        Person::display(); // Call base class display to show name
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Person* p = new Person("Rahul Sharma");
    Person* s = new Student("Priya Patel", "Mathematics", 88, 2024);
    Person* e = new Employee("Vikram Singh", "Finance", 75000.0);

    cout << "Displaying Person:" << endl;
    p->display();
    cout << endl;

    cout << "Displaying Student:" << endl;
    s->display();
    cout << endl;

    cout << "Displaying Employee:" << endl;
    e->display();
    cout << endl;

    delete p;
    delete s;
    delete e;
    
    return 0;
}
