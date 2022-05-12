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
            std::cout << "added " << s[b] << " to the set" << std::endl;
            set.insert(s[b++]);
            m = std::max(m, b - a);
        } else {
            std::cout << "removed " << s[a] << " from the set" << std::endl;
            set.erase(s[a]);
            a++;
        }
    }

    return m; 
}

int main () {

    std::string test = "abcabcbb";
    int ans = lengthOfLongestSubstring(test);

    std::string test2 = "pwwkew";
    int ans2 = lengthOfLongestSubstring(test2);

    std::cout << ans << std::endl;
    std::cout << ans2 << std::endl;


    return 0;
}
