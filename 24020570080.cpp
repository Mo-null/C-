#include <iostream>
#include <cctype> 
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " \"text_to_analyze\"" << endl;
        return 1;
    }

    int counts[26] = {0};
    string input = argv[1];

    for (char c : input) {
        if (isalpha(c)) { 
            c = tolower(c);
            counts[c - 'a']++; 
        }
    }

    cout << "Alphabet Count:" << endl;
    for (char letter = 'a'; letter <= 'z'; letter++) {
        cout << letter << ": " << counts[letter - 'a'] << endl;
    }

    return 0;
}

//cd %userprofile%\Downloads

/* 

cd /d C:\Users\Mohammed\OneDrive\Desktop
g++ 24020570080.cpp -o 24020570080.exe
.\24020570080.exe "Test123"

*\