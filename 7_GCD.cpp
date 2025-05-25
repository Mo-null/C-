#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int gcdRec(int a, int b) {
    a = abs(a); b = abs(b);
    return b == 0 ? a : gcdRec(b, a % b);
}

int gcdIter(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int getNumber(const string& prompt) {
    int num;
    string line;
    while (true) {
        cout << prompt;
        getline(cin, line);
        istringstream iss(line);
        if (iss >> num && iss.eof()) break;
        cout << "Error: Invalid number. Try again.\n";
    }
    return num;
}

int main() {
    int a = getNumber("Enter first integer: ");
    int b = getNumber("Enter second integer: ");

    if (a == 0 && b == 0) {
    cout << "Error: GCD(0, 0) is undefined.\n";
    return 1;
}

    cout << "\nResults:\n"
         << "(i) Recursive GCD: " << gcdRec(a, b) << "\n"
         << "(ii) Iterative GCD: " << gcdIter(a, b) << "\n";

    return 0;
}