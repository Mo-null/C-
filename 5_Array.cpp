#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> mergeSortedArrays(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;  
    
    while (i < a.size() && j < b.size())
        res.push_back(a[i] <= b[j] ? a[i++] : b[j++]);
    
    while (i < a.size()) res.push_back(a[i++]);
    while (j < b.size()) res.push_back(b[j++]);
    
    return res;
}

vector<int> getNumbers(const string& prompt) {
    vector<int> nums;
    string line;
    
    while (true) {
        cout << prompt;
        getline(cin, line);
        
        if (line.empty()) {
            cout << "Error: Empty input. Try again.\n";
            continue;
        }

        istringstream iss(line);
        int x;
        bool error = false;
        
        while (iss >> x) {
            if (!nums.empty() && x < nums.back()) {
                cout << "Error: " << x << " breaks order. Re-enter.\n";
                error = true;
                break;
            }
            nums.push_back(x);
        }

        if (iss.fail() && !iss.eof()) {
            cout << "Error: Only integers allowed. Re-enter.\n";
            error = true;
        }

        if (!error) break;
        nums.clear();
    }
    return nums;
}

int main() {
    vector<int> a = getNumbers("Enter sorted numbers for Array 1 (space-separated): ");
    vector<int> b = getNumbers("Enter sorted numbers for Array 2 (space-separated): ");
    vector<int> merged = mergeSortedArrays(a, b);
    
    cout << "Merged: [";
    for (int i = 0; i < merged.size(); ++i) {
        cout << merged[i];
        if (i != merged.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}