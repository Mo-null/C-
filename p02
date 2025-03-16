#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        if (s.find(arr[i]) == s.end()) {
            s.insert(arr[i]);
        }
    }

    cout << "Array after removing duplicates: ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
