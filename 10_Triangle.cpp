#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>
using namespace std;

class Triangle {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) {
        if (s1 <= 0 || s2 <= 0 || s3 <= 0)
            throw invalid_argument("All sides must be greater than 0.");

        if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1)
            throw invalid_argument("Sum of any two sides must be greater than the third side.");

        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    double area() const {
        if (side1 * side1 + side2 * side2 == side3 * side3)
            return 0.5 * side1 * side2;
        else if (side1 * side1 + side3 * side3 == side2 * side2)
            return 0.5 * side1 * side3;
        else if (side2 * side2 + side3 * side3 == side1 * side1)
            return 0.5 * side2 * side3;
        else
            throw logic_error("Not a right-angled triangle.");
    }

    double area(bool useHeron) const {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    void display() const {
        cout << "Triangle sides: " << side1 << ", " << side2 << ", " << side3 << endl;
    }
};

int main() {
    double s1, s2, s3;

    while (true) {
        cout << "Enter 3 sides of a triangle: ";
        if (!(cin >> s1 >> s2 >> s3)) {
            cout << "Invalid input. Please enter numbers only." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    try {
        Triangle t(s1, s2, s3);
        t.display();

        try {
            cout << "Right-angled area: " << t.area() << endl;
        } catch (const logic_error& e) {
            cout << "Area (Heron's formula): " << t.area(true) << endl;
        }

    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}