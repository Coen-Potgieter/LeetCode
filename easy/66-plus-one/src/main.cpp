
#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {

        int idx = digits.size() - 1;

        for (int i = idx; i >= 0; i--) {

            if ((i == 0) && (digits[i] == 9)) {
                digits.insert(digits.begin(), 1);
                for (int j = i+1; j < digits.size(); j++) {
                    digits[j] = 0;
                }
                break;
            }
            if (digits[i] != 9) {
                digits[i] += 1;
                for (int j = i+1; j < digits.size(); j++) {
                    digits[j] = 0;
                }
                break;
            }
        }
        return digits;

    }
};

void printVec(std::vector<int>& inpVec) {
    for (const int& elem : inpVec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution mySol;

    std::vector<int> case1 = { 1, 2 ,3};
    std::vector<int> case2 = { 9,9,9 };
    std::vector<int> case3 = { 9,8,7,6,5,4,3,2,1,0};
    std::vector<int> case4 = { 9, 8,9,9 };
    std::vector<int> digits = case3;

    std::cout << "Input: ";
    printVec(digits);

    std::vector res = mySol.plusOne(digits);

    std::cout << "Output: ";
    printVec(res);

    return 0;
}
