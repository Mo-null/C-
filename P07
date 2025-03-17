#include <iostream>
using namespace std;

// Function to calculate GCD using recursion
int gcdRecursive(int a, int b) {
    if (b == 0) {
        return a; // Base case: GCD(a, 0) = a
    }
    return gcdRecursive(b, a % b); // Recursive case: GCD(a, b) = GCD(b, a % b)
}

// Function to calculate GCD using iteration
int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a; // When b == 0, a is the GCD
}

int main() {
    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Calculate GCD using recursion
    int resultRecursive = gcdRecursive(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " (using recursion) is: " << resultRecursive << endl;

    // Calculate GCD using iteration
    int resultIterative = gcdIterative(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " (using iteration) is: " << resultIterative << endl;

    return 0;
}
