#include <iostream>
#include <vector>

int peakFinder (int l, int r, std::vector<int>& nums) {
    if (nums[((l + r) / 2) + 1] > nums[((l + r) / 2)])
        return peakFinder(((l + r) / 2), r, nums);
    else if (nums[((l + r) / 2) - 1] > nums[((l + r) / 2)])
        return peakFinder(l, ((l + r) / 2), nums);
    return (l + r) / 2;
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
