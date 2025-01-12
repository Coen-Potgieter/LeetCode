#include <sys/resource.h>
#include <vector>
#include <iostream>

class Solution {
private:
    int k = 0;
    void moveToEnd(std::vector<int>& nums, const int idx) {
        int tmp = nums[k-1];
        nums[k-1] = nums[idx];
        nums[idx] = tmp;
    }

public:
    int removeElement(std::vector<int>& nums, int val) {

        k = nums.size();

        int currIdx = 0;

        while (currIdx != k) {
            if (nums[currIdx] != val) {
                currIdx += 1;
                continue;
            } 
            moveToEnd(nums, currIdx);
            k -= 1;
        }

        return k;
    }
};

int main() {

    Solution mySol;

    std::vector<int> nums1 = { 1,2,3,4,5 };
    std::vector<int> nums2 = { 3, 2, 2, 3 };
    std::vector<int> nums3 = { 12, 239, 19, -1, 23, 129, 0 };

    std::vector<int> nums = nums2;
    int val = 3;
    const int k = mySol.removeElement(nums, val);


    std::cout << "K: " << k << std::endl;
    for (const int& elem : nums) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;


    return 0;
}
