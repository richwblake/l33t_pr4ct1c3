#include <iostream>
#include <string>
#include <unordered_set>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> set;
    int n = s.size();
    int m = 0;
    int a = 0;
    int b = 0;

    while (a < n && b < n) {
        if (set.find(s[b]) == set.end()) {
            set.insert(s[b]);
            b++;
            m = std::max(m, b - a);
        } else {
            set.erase(s[b]);
            a++;
        }
    }

    return m; 
}

int main () {

    std::string test = "abcabcbb";
    int ans = lengthOfLongestSubstring(test);

    std::cout << ans << std::endl;


    return 0;
}
