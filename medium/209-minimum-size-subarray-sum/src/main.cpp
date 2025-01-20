
#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {


        int start = 0;
        int windowSum = 0;
        int minLength = INT_MAX;

        for (int end = 0; end < nums.size(); end++) {
            windowSum += nums[end];

            while (windowSum >= target) {
                if ((end - start + 1) < minLength) minLength = end-start+1;
                windowSum -= nums[start];
                start++;

            }
        }
        return (minLength == INT_MAX) ? 0 : minLength;
        
    }
};

int main() {
    
    Solution sol;

    std::vector<int> nums1 = { 2, 3, 1, 2, 4, 3 };
    int k1 = 7;
    std::vector<int> nums2 = {1,4,4};
    int k2 = 4;
    std::vector<int> nums3 = {1,1,1,1,1,1,1,1};
    int k3 = 11;

    std::vector<int> nums = nums3;
    int k = k3;


    std::cout << "Input: " << std::endl;
    std::cout << "nums: "; for (const int& elem : nums) { std::cout << elem << ", ";}
    std::cout << std::endl << "k: " << k << std::endl << std::endl;
    std::cout << "Output:\n" << sol.minSubArrayLen(k, nums) << std::endl;





    return 0;
}
