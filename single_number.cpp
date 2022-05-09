#include <iostream>
#include <vector>

int singleNumber (std::vector<int>& nums) {
    
    int len = nums.size();
    
    return nums[0];
}

int main () {
 
    std::vector<int> nums1 = { 2, 2, 1 };
    std::vector<int> nums2 = { 4, 1, 2, 1, 2 };
    std::vector<int> nums3 = { 1 };


    return 0;
}
