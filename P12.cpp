#include <iostream>
#include <fstream>
#include <cctype> // for isspace()
using namespace std;

int main() {
    string inputFile, outputFile;

    // Get input and output file names from the user
    cout << "Enter the name of the input file: ";
    cin >> inputFile;
    cout << "Enter the name of the output file: ";
    cin >> outputFile;

    // Open the input file
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error: Unable to open input file!" << endl;
        return 1;
    }

    // Open the output file
    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Error: Unable to open output file!" << endl;
        return 1;
    }

    char ch;
    while (inFile.get(ch)) {
        // Check if the character is not a whitespace
        if (!isspace(ch)) {
            outFile << ch; // Write non-whitespace characters to the output file
        }
    }

    // Close the files
    inFile.close();
    outFile.close();

    cout << "File copied successfully after removing whitespaces!" << endl;

    return 0;
}
