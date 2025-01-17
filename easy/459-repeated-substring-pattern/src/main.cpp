
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>

class Solution {
private:
    bool checkForMatch(std::queue<char>& q, const std::string& s, const int currIdx) {

        if (s.size() % q.size() != 0) {
            return false;
        }

        int qSize = q.size();
        char* key = new char[qSize];

        for (int i = 0; i < qSize; i++) {
            key[i] = q.front();
            q.pop();
        }



        int i = currIdx;
        while(i < s.size()) {

            int j = 0;
            while (j < qSize) {
                if (key[j] != s[i + j]) {
                    delete[] key;
                    return false;
                }
                j++;
            }
            i += qSize;
        }


        delete[] key;
        return true;
    }
public:
    bool repeatedSubstringPattern(std::string s) {

        int repeatingFirstCharBase = 1;
        std::queue<char> q;

        while (1) {

            int repeatingFirstChar = repeatingFirstCharBase;
            q.push(s[0]);
            // Loop through chars of s
            for (int sIdx = 1; sIdx < s.size(); sIdx++) {
                const char c = s[sIdx];

                // if repeating char
                if (c == q.front()) {
                    repeatingFirstChar -= 1;
                }

                // if we must now check (enough reps of starting idx)
                if (repeatingFirstChar == 0) {

                    if (q.size() > (s.size() / 2)) {
                        return false;
                    }

                    if (checkForMatch(q, s, sIdx)) {
                        return true;
                    } else {
                        break;
                    }
                } 
                q.push(c);
            }

            if (q.size() > (s.size() / 2)) {
                return false;
            }
            repeatingFirstCharBase += 1;
            while (!q.empty()) {
                q.pop();
            }
        }


        return false;
    }
};


int main() {

    std::string case1 = "ababab";
    std::string case2 = "abadabad";
    std::string case3 = "aba";
    std::string case4 = "abcabcabcabc";
    std::string case5 = "ababa";
    std::string case6 = "ababba";

    std::string myCase = case6;

    Solution mySol;

    std::string ans = (mySol.repeatedSubstringPattern(myCase)) ? "True" : "False";

    std::cout << "Input: " << myCase << std::endl;
    std::cout << "Answer: " << ans << std::endl;

    return 0;
}
