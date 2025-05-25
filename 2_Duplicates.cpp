#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

void removeDuplicates(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    auto it = nums.begin();
    while (it != nums.end()) {
        if (!seen.insert(*it).second) { 
            it = nums.erase(it);
        } else {
            ++it;
        }
    }
}

int main() {
    std::vector<int> arr;
    std::string inputLine;

    std::cout << "Enter numbers separated by spaces: ";
    std::getline(std::cin, inputLine); 

    std::stringstream ss(inputLine);
    int num;
    while (ss >> num) { 
        arr.push_back(num);
    }

    if (ss.fail() && !ss.eof()) {
        std::cerr << "Error: Invalid input. Only integers allowed.\n";
        return 1;
    }

    removeDuplicates(arr); 

    std::cout << "Deduplicated array: ";
    for (int n : arr) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}