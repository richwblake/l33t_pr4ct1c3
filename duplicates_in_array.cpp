#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::unordered_map<int, int> tracker;
    std::vector<int> duplicates;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (tracker.find(nums[i]) != tracker.end())
            tracker[nums[i]]++;
        else
            tracker[nums[i]] = 1;
    }

    for (auto it = tracker.begin(); it != tracker.end(); it++) {
        if (it->second == 2)
            duplicates.push_back(it->first);
    }

    return duplicates;
}

void printVector(std::vector<int>& nums) {
    int n = nums.size();
    std::cout << "[";
    for (int i = 0; i < n; i++)
        std::cout << " " << nums[i];
    std::cout << " ]" << std::endl;
}


int main () {

    std::vector<int> nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
    std::vector<int> nums2 = { 1, 1, 3 };
    std::vector<int> nums3 = { };

    std::vector<int> r1 = findDuplicates(nums); 
    std::vector<int> r2 = findDuplicates(nums2); 
    std::vector<int> r3 = findDuplicates(nums3);

    printVector(r1);
    printVector(r2);
    printVector(r3);

    return 0;

}
