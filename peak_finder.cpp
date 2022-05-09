#include <iostream>
#include <vector>

int peakFinder (int l, int r, std::vector<int>& nums) {
    int mid = (l + r) / 2;

    if (nums[mid + 1] > nums[mid])
        return peakFinder(mid, r, nums);
    else if (nums[mid - 1] > nums[mid])
        return peakFinder(l, mid, nums);
        
    return mid;
}

int peakIndexInMountainArray (std::vector<int>& nums) {
    return peakFinder(0, nums.size() - 1, nums);
}


int main () {

    std::vector<int> nums = { 0, 1, 2, 3, 4, 5, 6, 8, 12, 23, 24, 45, 67, 69, 234, 555, 654, 5, 4, 3, 1 };

    int res = peakIndexInMountainArray(nums);

    std::cout << "Expected 16, got " << res << std::endl;

    return 0;
}
