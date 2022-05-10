#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum (std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hash_map;
    int len = nums.size();
    std::vector<int> res;

    for (int i = 0; i < len; i++) {
       int compliment = target - nums[i];
       if (hash_map.find(compliment) != hash_map.end()) {
           res.push_back(i);
           res.push_back(hash_map[compliment]);
           return res;
       } else {
           hash_map[nums[i]] = i;
       }
    }
    return res;
}








int main () {

    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8 };

    std::vector<int> results = twoSum(numbers, 12);
    int len = results.size();

    std::cout << "[ ";
    for (int i = 0; i < len; i++) {
        std::cout << results[i] << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
