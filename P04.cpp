#include <iostream>
using namespace std;

// Function to show address of each character in string
void showAddress(const char* str) {
    cout << "Address of each character in the string:\n";
    for (int i = 0; str[i] != '\0'; i++) {
        cout << "Character: " << str[i] << ", Address: " << (void*)&str[i] << endl;
    }
}

// Function to concatenate two strings
void concatenateStrings(char* str1, const char* str2) {
    int len1 = 0;
    while (str1[len1] != '\0') len1++; // Calculate length of str1

    int len2 = 0;
    while (str2[len2] != '\0') len2++; // Calculate length of str2

    for (int i = 0; i < len2; i++) {
        str1[len1 + i] = str2[i]; // Append str2 to str1
    }
    str1[len1 + len2] = '\0'; // Add null terminator
    cout << "Concatenated string: " << str1 << endl;
}

// Function to compare two strings
int compareStrings(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i]; // Return difference if characters differ
        }
        i++;
    }
    return str1[i] - str2[i]; // Return difference based on length
}

// Function to calculate length of the string using pointers
int stringLength(const char* str) {
    int len = 0;
    while (*(str + len) != '\0') len++; // Increment pointer to count characters
    return len;
}

// Function to convert all lowercase characters to uppercase
void toUpperCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // Convert lowercase to uppercase
        }
    }
    cout << "Uppercase string: " << str << endl;
}

// Function to reverse the string
void reverseString(char* str) {
    int len = 0;
    while (str[len] != '\0') len++; // Calculate length of the string

    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp; // Swap characters
    }
    cout << "Reversed string: " << str << endl;
}

// Function to insert a string into another string at a specified position
void insertString(char* str1, const char* str2, int pos) {
    int len1 = 0;
    while (str1[len1] != '\0') len1++; // Calculate length of str1

    int len2 = 0;
    while (str2[len2] != '\0') len2++; // Calculate length of str2

    if (pos < 0 || pos > len1) {
        cout << "Invalid position!\n";
        return;
    }

    // Shift characters in str1 to make space for str2
    for (int i = len1; i >= pos; i--) {
        str1[i + len2] = str1[i];
    }

    // Insert str2 into str1
    for (int i = 0; i < len2; i++) {
        str1[pos + i] = str2[i];
    }

    str1[len1 + len2] = '\0'; // Add null terminator
    cout << "String after insertion: " << str1 << endl;
}

int main() {
    int choice;
    char str1[100], str2[100];
    int pos;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Show address of each character in string\n";
        cout << "2. Concatenate two strings\n";
        cout << "3. Compare two strings\n";
        cout << "4. Calculate length of the string\n";
        cout << "5. Convert all lowercase characters to uppercase\n";
        cout << "6. Reverse the string\n";
        cout << "7. Insert a string in another string at a specified position\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a string: ";
                cin >> str1;
                showAddress(str1);
                break;

            case 2:
                cout << "Enter first string: ";
                cin >> str1;
                cout << "Enter second string: ";
                cin >> str2;
                concatenateStrings(str1, str2);
                break;

            case 3:
                cout << "Enter first string: ";
                cin >> str1;
                cout << "Enter second string: ";
                cin >> str2;
                int result = compareStrings(str1, str2);
                if (result == 0) {
                    cout << "Strings are equal.\n";
                } else if (result < 0) {
                    cout << "First string is smaller.\n";
                } else {
                    cout << "First string is larger.\n";
                }
                break;

            case 4:
                cout << "Enter a string: ";
                cin >> str1;
                cout << "Length of the string: " << stringLength(str1) << endl;
                break;

            case 5:
                cout << "Enter a string: ";
                cin >> str1;
                toUpperCase(str1);
                break;

            case 6:
                cout << "Enter a string: ";
                cin >> str1;
                reverseString(str1);
                break;

            case 7:
                cout << "Enter the main string: ";
                cin >> str1;
                cout << "Enter the string to insert: ";
                cin >> str2;
                cout << "Enter the position to insert: ";
                cin >> pos;
                insertString(str1, str2, pos);
                break;

            case 8:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
