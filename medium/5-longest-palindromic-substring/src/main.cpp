

#include <stack>
#include <string>
#include <iostream>
#include <unordered_map>

class Solution2 {
public:
    std::string longestPalindrome(std::string s) {

        // if no duplicates then return first element
        bool dups = false;
        std::unordered_map<char, size_t> map;
        for (const char& c : s) {
            if (map.count(c)) {
                map[c] += 1;
            } else {
                map[c] = 1;
            }
        }
        for (const auto& pair : map) {
            if (pair.second > 1) {
                dups = true;
            }
        }
        if (!dups) return s.substr(0,1);

        /* return s; */
        // Sliding window
        int currSize = s.size();

        while (currSize > 1) {

            int startPtr = 0;
            int endPtr = startPtr + currSize - 1;
            while (endPtr < s.size()) {

                if (s[startPtr] != s[endPtr]) {
                    startPtr += 1;
                    endPtr += 1;
                    continue;
                }
                if (endPtr - startPtr <= 1) return s.substr(startPtr, 2);

                int ptr1 = startPtr + 1;
                int ptr2 = endPtr - 1;
                bool correct = true;
                while (ptr1 <= ptr2) {
                    if (s[ptr1] != s[ptr2]) {
                        correct = false;
                        break;
                    }
                    ptr1 += 1;
                    ptr2 -= 1;
                }
                if (correct) {
                    return s.substr(startPtr, endPtr - startPtr + 1);
                }
                startPtr += 1;
                endPtr += 1;
            }
            currSize -= 1;
        }
        return s.substr(0, 1);
    }

};

class Solution {
public:
    std::string longestPalindrome(std::string s) {

        std::unordered_map<char, int> map;
        int p1 = -1;
        int p2 = -1;

        // init map
        for (const char& c : s) {
            if (map.count(c)) {
                map[c] += 1;
            } else {
                map[c] = 1;
            }
        }

        for (size_t charIdx = 0; charIdx < s.size(); charIdx++) {
            if (s.size() - charIdx < p2 - p1 + 1) break;

            char c = s[charIdx];
            if (map[c] <= 1) {
                continue;
            }
            map[c] -= 1;

            for (int targetIdx = map[c]; targetIdx > 0; targetIdx--) {
                int numSeen = 0;
                std::stack<char> myStack;
                myStack.push(c);
                size_t ptr2 = charIdx + 1;
                while (1) {
                    myStack.push(s[ptr2]);
                    if (s[ptr2] == c) {
                        numSeen += 1;
                    }
                    if (numSeen == targetIdx) break;
                    ptr2 += 1;
                }
                // Stack initialised


                // Check if bigger than curr Solutiuon
                if (myStack.size() < (p2 - p1 + 1)) continue;

                // Check if curr solution is correct
                size_t ptr3 = charIdx;
                bool correct = true;
                while (!myStack.empty()) {
                    if (!(s[ptr3] == myStack.top())) { 
                        correct = false;
                    }
                    myStack.pop();
                    ptr3 += 1;
                }
                myStack.pop();

                if (correct) {
                    p1 = charIdx;
                    p2 = ptr2;
                    break;
                }
            }

        }
        if (p1 == -1) return s.substr(0, 1);
        return s.substr(p1, p2 - p1 + 1);
    }
};

int main() {

    Solution2 mySol;

    std::string inp1 = "babad";
    std::string inp2 = "ac";
    std::string inp3 = "oiJAfoAKNdf";
    std::string inp4 = "cbbd";

    std::string inp = inp4;

    std::string outp = mySol.longestPalindrome(inp);

    std::cout << outp << std::endl;







    return 0;
}
