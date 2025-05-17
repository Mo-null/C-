#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

double computeSeriesSum(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        double term = 1.0 / pow(i, i);
        if (i % 2 == 0) {
            sum -= term;
        } else {
            sum += term;
        }
    }
    return sum;
}

bool validateInput(int n) {
    if (n <= 0) {
        cerr << "Invalid input. Number of terms must be positive." << endl;
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    int n;
    bool inputValid = false;
    
    // Check if command line argument is provided
    if (argc > 1) {
        try {
            n = stoi(argv[1]);
            inputValid = validateInput(n);
        } catch (const exception& e) {
            cerr << "Invalid input: " << e.what() << endl;
        }
    }
    
    // If no valid command line argument, prompt user
    if (!inputValid) {
        cout << "Please enter the number of terms (n): ";
        cin >> n;
        inputValid = validateInput(n);
        if (!inputValid) {
            cerr << "Exiting program." << endl;
            return 1;
        }
    }
    
    double sum = computeSeriesSum(n);
    cout.precision(10);
    cout << "The sum of the first " << n << " terms of the series is: " << sum << endl;
    
    return 0;
}
