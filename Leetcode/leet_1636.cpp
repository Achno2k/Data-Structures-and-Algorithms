#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

static bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.second == b.second)
        return a.first > b.first;
    else
        return a.second < b.second;
}

std::vector<int> frequencySort(std::vector<int>& nums) {
    std::unordered_map<int, int> hashMap;
    for (int i : nums) {
        hashMap[i]++;
    }

    std::vector<std::pair<int, int>> frequencyVec;
    for (auto& pair : hashMap) {
        frequencyVec.push_back(pair);
    }

    std::sort(frequencyVec.begin(), frequencyVec.end(), compare);

    std::vector<int> ans;
    for (const std::pair<int, int>& pair : frequencyVec) {
        int frequency = pair.second;
        while (frequency--) {
            ans.push_back(pair.first);
        }
    }

    return ans;
}

int main() {
    // Example usage
    std::vector<int> nums = {4, 5, 6, 6, 5, 4, 3, 1, 1, 1, 2, 2, 2};
    std::vector<int> sortedArray = frequencySort(nums);

    // Print the sorted array
    std::cout << "Sorted Array: ";
    for (int num : sortedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
