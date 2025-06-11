#include <iostream>
#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        const size_t patternLength = p.size();
        const size_t stringLength = s.size();

        // Edge Case: If p only contains "*" chars
        bool allSpecialChars = true;
        for (const char& c : p) {
            if (c != '*') {
                allSpecialChars = false;
                break;
            }
        }
        if (allSpecialChars) return true;

        size_t sPtr = 0;
        size_t pPtr = 0;


        size_t sAccounted = 0;
        size_t pAccounted = 0;
        // First Match Non special chars
        while ((pPtr < patternLength) && (sPtr < stringLength)) {

            char patternChar = p.at(pPtr);

            // Case 1
            if (patternChar == '?') {
                sAccounted += 1;
                pAccounted += 1;
                sPtr += 1;
                pPtr += 1;
                continue;
            }

            // Case 2
            if (patternChar != '*') {

                if (s.at(sPtr) == p.at(pPtr)) {
                    sAccounted += 1;
                    pAccounted +=1;
                    sPtr += 1;
                    pPtr += 1;
                    continue;
                } else {
                    return false;
                }
            } else {
                // Case `*`
                size_t pNextPtr = p.find_first_not_of("*?", pPtr);
                if (pNextPtr == std::string::npos) return true;
                char nextChar = p.at(pNextPtr);
                size_t sNextPtr = s.find_first_of(nextChar, sPtr);
                if (sNextPtr == std::string::npos) return false;
                sAccounted += sNextPtr - sPtr + 1;
                pAccounted += pNextPtr - pPtr + 1;
                pPtr = pNextPtr + 1;
                sPtr = sNextPtr + 1;

            }
        }
        if ((sAccounted != stringLength) || (pAccounted != patternLength)) return false;
        return true;

    }
};


int main() {

    Solution mySol;

    std::vector<std::string> sExamples = {
        "aa",
        "cb",
        "aa",
        "adceb",
        "",
        "abcabczzzde",
    };
    std::vector<std::string> pExamples = {
        "a",
        "?b",
        "*",
        "*a*b",
        "******",
        "*abc???de*",
    };
    size_t testIdx = 5;
    bool outp = mySol.isMatch(sExamples.at(testIdx), pExamples.at(testIdx));
    std::cout << "Input:\n   a=\"" << sExamples.at(testIdx) << "\" | p=\"" << pExamples.at(testIdx) << "\"\n";
    std::cout << "Output:\n   ";
    if (outp) std::cout << "true\n";
    else std::cout << "false\n";

    return 0;
}

