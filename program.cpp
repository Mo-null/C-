#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <limits>

using namespace std;

double computeSeriesSum(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        double term = 1.0 / pow(i, i);
        sum += (i % 2 == 0) ? -term : term;
    }
    return sum;
}

bool isValid(int n) {
    return n > 0;
}

int getInput(int argc, char* argv[]) {
    int n = 0;

    if (argc > 1) {
        try {
            n = stoi(argv[1]);
            if (!isValid(n)) {
                cerr << "Invalid input from command line. n must be > 0.\n";
                n = 0;
            } else {
                cout << "Command-line input detected: n = " << n << "\n";
            }
        } catch (...) {
            cerr << "Invalid command-line argument. Please enter a positive integer.\n";
        }
    }

    while (!isValid(n)) {
        cout << "This program computes the sum of the series:\n";
        cout << "1/1^1 - 1/2^2 + 1/3^3 - 1/4^4 + ... ± 1/n^n\n";
        cout << "Enter a positive integer for n: ";
        cin >> n;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter a numeric value.\n";
            n = 0;
        } else if (!isValid(n)) {
            cerr << "n must be greater than 0.\n";
        }
    }

    return n;
}

int main(int argc, char* argv[]) {
    int n = getInput(argc, argv);
    double sum = computeSeriesSum(n);

    cout.precision(10);
    cout << "The sum of the first " << n << " terms is: " << sum << endl;

    return 0;
}
/*
cd C:\Users\Mohammed\OneDrive\Desktop
g++ -o program.exe program.cpp
.\program.exe
*/