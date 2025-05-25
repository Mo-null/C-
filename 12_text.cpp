#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    string inputFile, outputFile;

    cout << "Enter the name of the input file: ";
    cin >> inputFile;
    cout << "Enter the name of the output file: ";
    cin >> outputFile;

    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error: Unable to open input file!" << endl;
        return 1;
    }

    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Error: Unable to open output file!" << endl;
        return 1;
    }

    char ch;
    while (inFile.get(ch)) {
        if (!isspace(ch)) {
            outFile << ch;
        }
    }

    inFile.close();
    outFile.close();

    cout << "File copied successfully after removing whitespaces!" << endl;

    return 0;
}
/*
cd "C:\Users\Mohammed\OneDrive\Desktop"
g++ 12_text.cpp -o 12_text && 12_text.exe

*/
