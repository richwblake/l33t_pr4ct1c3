#include <iostream>
#include <string>


bool isPalindrome(int x) {
    if (x < 0) return false;
    
    std::string num = std::to_string(x);
    int n = num.length();

    for (int i = 0; i < n / 2; i++) {
        std::cout << num[i] << "\n" << num[n - i - 1] << std::endl;
        if (num[i] != num[n - i - 1])
            return false;
    }
    return true;

    std::cout << (x >> 1) << std::endl;
}

int main () {

    int test = 1234321;

    bool res = isPalindrome(test);

    std::cout << res << std::endl;
    return 0;

}
