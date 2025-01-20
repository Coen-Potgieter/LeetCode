
#include <climits>
#include <string>
#include <iostream>

class Solution {

private:
    bool isUniqueChars(const std::string& s, int start, int end) {

        for (int i = start + 1; i < (end + 1); i++) {
            for (int j = start; j < i; j++) {
                if (s[i] == s[j]) return false;
            }
        }
        return true;
    }

public:
    int lengthOfLongestSubstring(std::string s) {

        int currLength; 
        int maxLength = INT_MIN;
        int start = 0;

        for (int end = 0; end < s.size(); end++) {

            if (isUniqueChars(s, start, end)) {
                currLength = end - start + 1;
                if (currLength > maxLength) maxLength = currLength;
            } else {
                start += 1;
                end -= 1;
            }
        }

        return (maxLength == INT_MIN) ? 0 : maxLength;
    }
};

int main() {

    Solution sol;

    std::string case1 = "abcabcbb";
    std::string case2 = "bbbbb";
    std::string case3 = "pwwkew";

    std::string myCase = case3;
    std::cout << "Input: " << myCase << std::endl;
    std::cout << "Output: " << sol.lengthOfLongestSubstring(myCase) << std::endl;
    return 0;
}
