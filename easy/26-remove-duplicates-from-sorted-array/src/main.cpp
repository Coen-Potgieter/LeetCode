#include <vector>
#include <iostream>


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {

        int numsSize = nums.size();

        for (int i = 0; i < (numsSize - 1); i++){
            while (nums[i] == nums[i+1]) {
                nums.erase(nums.begin() + i+1);
                numsSize -= 1;
                if (i == numsSize - 1){
                    break;
                }
            }
        }

        return numsSize;
    }
};


int main() {

    Solution mySol;


    std::vector<int> nums1 = {1,1,2};
    std::vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
    std::vector<int> nums3 = { 1,2,3,5,6 };
    std::vector<int> nums4 = { 1, 1};

    std::vector<int> nums = nums4;

    int k = mySol.removeDuplicates(nums);

    for (const int& elem : nums) {
        std::cout << elem << std::endl;
    }
    std::cout << "k: " << k << std::endl;
    return 0;

}

