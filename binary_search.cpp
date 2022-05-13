#include <iostream>
#include <vector>

int searchUtil (std::vector<int>& nums, int target, int l, int r) {
    if (l > r) return -1;
    int mid = (l + r) / 2;
    int num = nums[mid];
    if (num == target) return mid;
    if (num > target) return searchUtil(nums, target, l, mid - 1);
    if (num < target) return searchUtil(nums, target, mid + 1, r);
    return -1;
}
int search (std::vector<int>& nums, int target) {
    int n = nums.size();
    return searchUtil(nums, target, 0, n - 1);
}


int main () {

    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int index = search(numbers, 8);

    std::vector<int> numbers2 = { -8, -6, -5, -3, -2, -1, 3, 4, 6, 7, 9, 12 };

    int index2 = search(numbers2, -5);

    std::vector<int> numbers3 = { -1 };

    int index3 = search(numbers3, 2);

    std::cout << "target found at index: " << index << std::endl;
    std::cout << "target found at index: " << index2 << std::endl;
    std::cout << "target found at index: " << index3 << std::endl;

    return 0;
}
