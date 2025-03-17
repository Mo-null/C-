#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

// Triangle class
class Triangle {
private:
    double side1, side2, side3;

public:
    // Constructor with exception handling
    Triangle(double s1, double s2, double s3) {
        // Check if all sides are greater than 0
        if (s1 <= 0 || s2 <= 0 || s3 <= 0) {
            throw invalid_argument("All sides must be greater than 0.");
        }

        // Check triangle inequality theorem
        if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1) {
            throw invalid_argument("Sum of any two sides must be greater than the third side.");
        }

        // Assign sides if valid
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    // Function to calculate area of a right-angled triangle
    double area(double base, double height) {
        if (base <= 0 || height <= 0) {
            throw invalid_argument("Base and height must be greater than 0.");
        }
        return 0.5 * base * height;
    }

    // Function to calculate area using Heron's formula
    double area() {
        double s = (side1 + side2 + side3) / 2; // Semi-perimeter
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    // Function to display sides
    void display() const {
        cout << "Triangle sides: " << side1 << ", " << side2 << ", " << side3 << endl;
    }
};

int main() {
    try {
        // Create a valid triangle
        Triangle t(3, 4, 5);
        t.display();

        // Calculate area using Heron's formula
        cout << "Area using Heron's formula: " << t.area() << endl;

        // Calculate area of a right-angled triangle
        cout << "Area of right-angled triangle (base=3, height=4): " << t.area(3, 4) << endl;

        // Test exception handling
        /*
        Triangle invalidTriangle(1, 2, 3); // Invalid triangle (1 + 2 <= 3)
        Triangle negativeSides(-1, 2, 3);  // Invalid triangle (negative side)
        */
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
