#include <iostream>
#include <vector>
#include <cmath>

bool contains_duplicate_two(std::vector<int>& nums, int k) {
    int n = nums.size();
    
    if (n == 0) return false;
    if (n == 1) return false;

    int a = 0;
    int b = 1;
    while (a < n) {
        if (a != b && nums[a] == nums[b] && abs(a - b) <= k)
            return true;
        if (b == n - 1) {
            a++;
        }
        if (b < n - 1)
            b++;
    }
    return false;
}   

int main () {

    std::vector<int> nums = { 4, 2, 1, 7, 8, 1, 2, 8, 1, 0 };

    std::vector<int> nums2 = { 1, 2, 3, 1 };

    std::vector<int> nums3 = { 1, 2, 3, 1, 2, 3 };

    bool ans = contains_duplicate_two(nums2, 3);
    bool ans2 = contains_duplicate_two(nums3, 2);

    std::cout << ans << std::endl;
    std::cout << ans2 << std::endl;

    return 0;
}
