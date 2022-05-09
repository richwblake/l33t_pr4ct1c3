#include <iostream>
#include <vector>
#include <map>

bool containsDuplicate(std::vector<int>& nums) {
    std::map<int, bool> tracker;
    int len = nums.size();

    for (int i = 0; i < len; i++) {
        if (tracker.find(nums[i]) != tracker.end())
            return true;
        else
            tracker[nums[i]] = true;
    }
    return false;
}

int main () {
    
    std::vector<int> test1 = { 1, 2, 3, 1 }; 
    std::vector<int> test2 = { 1, 2, 3, 4 }; 
    std::vector<int> test3 = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 }; 

    std::cout << "Expected true, got " << (containsDuplicate(test1) ? "true" : "false") << std::endl;
    std::cout << "Expected false, got " << (containsDuplicate(test2) ? "true" : "false") << std::endl;
    std::cout << "Expected true, got " << (containsDuplicate(test3) ? "true" : "false") << std::endl;

    return 0;
}
