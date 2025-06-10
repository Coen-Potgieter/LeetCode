#include <iostream>
#include <string>

class Solution {
public:

    bool isSpecialChar(const char& s) {
        if ((s == '?') || (s == '*')) {
            return true;
        }
        return false;
    }
    bool isMatch(std::string s, std::string p) {


        const size_t patternLength = p.size();
        const size_t stringLength = s.size();
        if (patternLength > stringLength) return false;

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
    };
    std::vector<std::string> pExamples = {
        "a",
        "?b",
    };
    size_t testIdx = 1;
    bool outp = mySol.isMatch(sExamples.at(testIdx), pExamples.at(testIdx));
    std::cout << "Input:\n   a=\"" << sExamples.at(testIdx) << "\" | p=\"" << pExamples.at(testIdx) << "\"\n";
    std::cout << "Output:\n   ";
    if (outp) std::cout << "true\n";
    else std::cout << "false\n";

    return 0;
}

