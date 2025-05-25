#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int binarySearchRec(const vector<int>& arr, int target, int left, int right) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    return (arr[mid] < target)
        ? binarySearchRec(arr, target, mid + 1, right)
        : binarySearchRec(arr, target, left, mid - 1);
}

int binarySearchIter(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        (arr[mid] < target) ? left = mid + 1 : right = mid - 1;
    }
    return -1;
}

vector<int> parseLineToVector(const string& line, bool& success) {
    vector<int> result;
    istringstream iss(line);
    int num;
    while (iss >> num) {
        result.push_back(num);
    }
    success = !result.empty() && iss.eof();
    return result;
}

int main() {
    string line;
    vector<int> arr;
    bool valid = false;

    while (!valid) {
        cout << "Enter sorted numbers (space-separated): ";
        getline(cin, line);
        arr = parseLineToVector(line, valid);
        if (!valid) {
            cout << "Error: Invalid input.\n";
            continue;
        }
        if (!is_sorted(arr.begin(), arr.end())) {
            cout << "Error: Numbers must be sorted in ascending order.\n";
            valid = false;
        }
    }

    int target;
    while (true) {
        cout << "Enter target to search: ";
        getline(cin, line);
        istringstream iss(line);
        if (iss >> target && iss.eof()) break;
        cout << "Error: Invalid number.\n";
    }

    int recResult = binarySearchRec(arr, target, 0, arr.size() - 1);
    int iterResult = binarySearchIter(arr, target);

    cout << "\nResults:\n"
         << "(i) Recursive: "  << (recResult != -1 ? to_string(recResult) : "Not found") << "\n"
         << "(ii) Iterative: " << (iterResult != -1 ? to_string(iterResult) : "Not found") << "\n";

    return 0;
}
