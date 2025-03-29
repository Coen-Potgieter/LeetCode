
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        std::vector<int> indicies(2, -1);
        for (int first = 0; first < nums.size(); first++) {
            for (int second = first + 1; second < nums.size() ; second++) {
                if (nums[first] + nums[second] == target) {
                    std::vector<int> indicies = {first, second};
                    return indicies;
                }
            }
        }
        return indicies;
    }
};

int main() {

    std::vector<int> inp1 = { 2,7,11,15 };
    int target1 = 9;

    std::vector<int> inpVec = inp1;
    int inpTarget = target1;

    Solution mySol;
    std::vector<int> outp = mySol.twoSum(inpVec, inpTarget);

    std::cout << outp[0] << " " << outp[1] << std::endl;

    return 0;
}
