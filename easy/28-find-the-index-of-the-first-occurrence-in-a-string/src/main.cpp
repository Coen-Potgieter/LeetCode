

#include <string>
#include <iostream>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int hayLength = haystack.size();
        int needleLength = needle.size();

        bool notFound;
        int startingIdx = 0;
        while (1) {

            // Check if hay is big enough
            if ((hayLength - startingIdx) < needleLength) {
                return -1;
            }

            notFound = false;
            for (int i = 0; i < needleLength; i++) {
                if (haystack[i + startingIdx] != needle[i]) {
                    notFound = true;
                    break;
                }
            }

            if (!notFound) {
                return startingIdx;
            }
            startingIdx += 1;
        }

    }
};

int main() {

    std::string hay1 = "sadbud";
    std::string needle1 = "sad";

    std::string hay2 = "sadbud";
    std::string needle2 = "sfd";

    std::string hay3 = "hello";
    std::string needle3 = "ll";

    std::string hay = hay3;
    std::string needle = needle3;

    Solution mySol;

    int res = mySol.strStr(hay, needle);

    std::cout << res << std::endl;

    return 0;
}
