


#include <iostream>
#include <string>
#include <math.h> 

using std::string;

class Solution {
public:

    int myAtoi(string s) {

        // Remove White Space
        s.erase(0, s.find_first_not_of(" \t\n\r"));
        s.erase(s.find_last_not_of(" \t\n\r") + 1);


        // See if its positive
        bool isNegative = (s[0] == '-');


        // Remove starting +, -
        bool startsWithSign (s[0] == '+' || s[0] == '-');
        if (startsWithSign) {
            s.erase(0,1);
        }



        // If chars at beginning then return 0
        size_t not_nums = s.find_first_not_of("0123456789");
        size_t nums = s.find_first_of("0123456789");
        if (not_nums < nums) {
            return 0;
        }

        // Remove from chars to end
        size_t middleCharsPos = s.find_first_not_of("0123456789");

        if (middleCharsPos != -1) {
            s.erase(middleCharsPos);
        }

        // Remove starting 0
        s.erase(0, s.find_first_not_of("0"));


        // Get total size
        long int runningSum = 0;
        int powerOf10 = s.size() - 1;
        if (powerOf10 > 9) {
            if (isNegative) return INT_MIN;
            else return INT_MAX;
        }


        for (const char& c : s) {
            int multiplier = static_cast<int>(c) - 48;
            if (powerOf10 == 9 && multiplier > 2) {
                if (isNegative) return INT_MIN;
                else return INT_MAX;
            }
            runningSum += std::pow(10, powerOf10) * multiplier;
            powerOf10 -= 1;
        }


        if (isNegative == 1 && runningSum*-1 < INT_MIN) return INT_MIN;
        if (isNegative == 0 && runningSum > INT_MAX) return INT_MAX;
        if (isNegative) runningSum *= -1;
        return runningSum;
    }
};

int main() {

    Solution mySol;
    std::string inp1 = "-042";
    std::string inp2 = "   042";
    std::string inp3 = "   12345678910";
    std::string inp4 = "words and 987";
    std::string inp5 = "1337c0d3";
    std::string inp6 = "42";
    std::string inp7 = "0-1";
    std::string inp8 = "-91283472332";
    std::string inp9 = "+-12";
    std::string inp10 = "-2147483648";
    std::string inp11 = "2147483648";


    std::string inp = inp11;
    std::cout << "Input: " << inp << std::endl;

    int outp = mySol.myAtoi(inp);
    std::cout << "Ouput: " << outp << std::endl;

    return 0;
}
