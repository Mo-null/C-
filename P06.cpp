#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// (i) Without recursion
int binarySearchIter(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        arr[mid] < target ? left = mid + 1 : right = mid - 1;
    }
    return -1;
}

// (ii) With recursion
int binarySearchRec(const vector<int>& arr, int target, int left, int right) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    return arr[mid] < target 
        ? binarySearchRec(arr, target, mid + 1, right)
        : binarySearchRec(arr, target, left, mid - 1);
}

int main() {
    int N, target;
    cout << "Enter number of elements (N > 0): ";
    cin >> N;
    if (N <= 0) { cerr << "Invalid N.\n"; return 1; }  // Crucial: Prevent crash

    vector<int> nums(N);
    cout << "Enter " << N << " sorted numbers: ";
    for (int& num : nums) cin >> num;
    if (!is_sorted(nums.begin(), nums.end())) {  // Crucial: Binary search requirement
        cerr << "Error: Numbers must be sorted.\n"; 
        return 1;
    }

    cout << "Enter target: ";
    cin >> target;

    // Output results
    int iter_result = binarySearchIter(nums, target);
    int rec_result = binarySearchRec(nums, target, 0, N - 1);
    cout << "Iterative: " << (iter_result != -1 ? to_string(iter_result) : "Not found") << endl;
    cout << "Recursive: " << (rec_result != -1 ? to_string(rec_result) : "Not found") << endl;
}
