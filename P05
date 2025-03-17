#include <iostream>
using namespace std;

// Function to merge two sorted arrays
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    // Traverse both arrays and merge them in sorted order
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1 (if any)
    while (i < size1) {
        result[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2 (if any)
    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2;

    // Input size of the first array
    cout << "Enter the size of the first array: ";
    cin >> size1;
    int arr1[size1];

    // Input elements of the first array
    cout << "Enter the elements of the first array (in sorted order): ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    // Input size of the second array
    cout << "Enter the size of the second array: ";
    cin >> size2;
    int arr2[size2];

    // Input elements of the second array
    cout << "Enter the elements of the second array (in sorted order): ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    // Create a result array to store the merged array
    int result[size1 + size2];

    // Merge the two arrays
    mergeArrays(arr1, size1, arr2, size2, result);

    // Output the merged array
    cout << "Merged array: ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
