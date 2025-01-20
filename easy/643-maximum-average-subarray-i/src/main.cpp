
#include <climits>
#include <vector>
#include <iostream>

class Solution {


public:
    double findMaxAverage(std::vector<int>& nums, int k) {

        double maxAvg = INT_MIN;
        double windowSum = 0;

        for (int start = 0; start <= nums.size(); start++) {

            windowSum += nums[start];
            if (start >= (k - 1)) {
                if ((windowSum/k) > maxAvg) maxAvg = windowSum/k;
                windowSum -= nums[start - k + 1];
            }
        }
        return maxAvg;
    }
};


int main() {
    Solution sol;

    std::vector<int> nums1 = { 1,12,-5,-6,50,3 }; 
    int k1 = 4;
    std::vector<int> nums2 = {5}; 
    int k2 = 1;

    std::vector<int> nums = nums2;
    int k = k2;

    std::cout << "Input: " << std::endl << "`nums`: ";
    for (const int& elem : nums) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl << "`k`: " << k << std::endl;
    std::cout << std::endl << "Output:\n" << sol.findMaxAverage(nums, k) << std::endl;
    
    return 0;
}
