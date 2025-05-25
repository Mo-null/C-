#include <iostream>
#include <limits>
using namespace std;

constexpr int MAX_INPUT_SIZE = 100;
constexpr char ASCII_UPPER_OFFSET = 'a' - 'A';

size_t stringLength(const char* str) {
    if (!str) return 0;
    const char* ptr = str;
    while (*ptr) ptr++;
    return ptr - str;
}

void showAddresses(const char* str) {
    if (!str || !*str) {
        cout << "Error: Empty or invalid string\n";
        return;
    }
    cout << "Character\tAddress\n";
    while (*str) {
        cout << *str << "\t\t" << (void*)str << endl;
        str++;
    }
}

char* concatenateStrings(const char* str1, const char* str2) {
    if (!str1 || !str2) return nullptr;
    size_t len1 = stringLength(str1);
    size_t len2 = stringLength(str2);
    char* result = new char[len1 + len2 + 1];
    
    size_t i = 0;
    for (; i < len1; i++) result[i] = str1[i];
    for (size_t j = 0; j < len2; j++) result[i + j] = str2[j];
    result[len1 + len2] = '\0';
    
    return result;
}

int compareStrings(const char* str1, const char* str2) {
    if (!str1 || !str2) return 0;
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

void toUpperCase(char* str) {
    if (!str) return;
    while (*str) {
        if (*str >= 'a' && *str <= 'z') *str -= ASCII_UPPER_OFFSET;
        str++;
    }
}

void reverseString(char* str) {
    if (!str || !*str) return;
    size_t len = stringLength(str);
    for (size_t i = 0, j = len - 1; i < j; i++, j--) {
        swap(str[i], str[j]);
    }
}

char* insertString(const char* mainStr, const char* insertStr, int pos) {
    if (!mainStr || !insertStr) return nullptr;
    size_t mainLen = stringLength(mainStr);
    size_t insertLen = stringLength(insertStr);
    
    if (pos < 0 || (size_t)pos > mainLen) {
        cout << "Error: Position must be 0-" << mainLen << endl;
        return nullptr;
    }

    char* result = new char[mainLen + insertLen + 1];
    size_t i = 0;
    for (; i < (size_t)pos; i++) result[i] = mainStr[i];
    for (size_t j = 0; j < insertLen; j++) result[i + j] = insertStr[j];
    for (size_t j = 0; j < mainLen - pos; j++) result[i + insertLen + j] = mainStr[pos + j];
    result[mainLen + insertLen] = '\0';
    
    return result;
}

bool readString(char* str, size_t maxSize) {
    size_t i = 0;
    char c;
    while (i < maxSize - 1 && (c = cin.get()) != '\n') {
        if (c == EOF) return false;
        str[i++] = c;
    }
    str[i] = '\0';
    
    if (i == 0) {
        cout << "Error: Empty input. Try again: ";
        return readString(str, maxSize);
    }
    return true;
}

bool readInteger(int& num) {
    if (!(cin >> num)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}

void displayMenu() {
    cout << "\nString Manipulation Menu:\n"
         << "1. Show character addresses\n"
         << "2. Concatenate strings\n"
         << "3. Compare strings\n"
         << "4. Get string length\n"
         << "5. Convert to uppercase\n"
         << "6. Reverse string\n"
         << "7. Insert substring\n"
         << "8. Exit\n";
}

int main() {
    char str1[MAX_INPUT_SIZE], str2[MAX_INPUT_SIZE];
    char* result = nullptr;

    displayMenu();
    while (true) {
        cout << "Enter choice (1-8): ";
        
        int choice;
        if (!readInteger(choice)) {
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 8) {
            cout << "Exiting program...\n";
            break;
        }

        if (choice < 1 || choice > 8) {
            cout << "Error: Choice must be 1-8\n";
            continue;
        }

        int cmp; // Moved outside switch to avoid cross-initialization errors
        
        switch (choice) {
            case 1:
                cout << "Enter string: ";
                while (!readString(str1, MAX_INPUT_SIZE)) {}
                showAddresses(str1);
                break;
                
            case 2:
                cout << "Enter first string: ";
                while (!readString(str1, MAX_INPUT_SIZE)) {}
                cout << "Enter second string: ";
                while (!readString(str2, MAX_INPUT_SIZE)) {}
                result = concatenateStrings(str1, str2);
                if (result) {
                    cout << "Result: " << result << endl;
                    delete[] result;
                }
                break;
                
            case 3:
                cout << "Enter first string: ";
                while (!readString(str1, MAX_INPUT_SIZE)) {}
                cout << "Enter second string: ";
                while (!readString(str2, MAX_INPUT_SIZE)) {}
                cmp = compareStrings(str1, str2);
                cout << "Comparison: ";
                if (cmp == 0) cout << "Strings are equal\n";
                else cout << "String 1 is " << (cmp > 0 ? "greater" : "smaller") << " than string 2\n";
                break;
                
            case 4:
                cout << "Enter string: ";
                while (!readString(str1, MAX_INPUT_SIZE)) {}
                cout << "Length: " << stringLength(str1) << endl;
                break;
                
            case 5:
                cout << "Enter string: ";
                while (!readString(str1, MAX_INPUT_SIZE)) {}
                toUpperCase(str1);
                cout << "Uppercase: " << str1 << endl;
                break;
                
            case 6:
                cout << "Enter string: ";
                while (!readString(str1, MAX_INPUT_SIZE)) {}
                reverseString(str1);
                cout << "Reversed: " << str1 << endl;
                break;
                
            case 7:
                cout << "Enter main string: ";
                while (!readString(str1, MAX_INPUT_SIZE)) {}
                cout << "Enter substring to insert: ";
                while (!readString(str2, MAX_INPUT_SIZE)) {}
                cout << "Enter position (0-" << stringLength(str1) << "): ";
                int pos;
                while (!readInteger(pos) || pos < 0 || (size_t)pos > stringLength(str1)) {
                    cout << "Invalid position. Enter 0-" << stringLength(str1) << ": ";
                }
                result = insertString(str1, str2, pos);
                if (result) {
                    cout << "Result: " << result << endl;
                    delete[] result;
                }
                break;
        }
    }
    return 0;
}