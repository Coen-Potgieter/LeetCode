#include <vector>
#include <iostream>

class Solution {
private:

    int binarySearch(std::vector<int>& nums, int lo, int hi, int target) {
        if (lo > hi) {
            return -1;
        }

        int mid = lo + ((hi - lo) / 2);

        if (nums[mid] == target) {
            return mid;
        }

        if (target < nums[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
        return binarySearch(nums, lo, hi, target);
    }

public:
    int searchInsert(std::vector<int>& nums, int target) {

        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) / 2);

            if (nums.at(mid) == target) {
                return mid;
            }

            if (target < nums[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
        /* return binarySearch(nums, 0, nums.size(), target); */
    }
};


int main() {

    std::vector<int> myNums = { 1, 3, 5, 6};
    Solution mySol;
    int idx = mySol.searchInsert(myNums, 7);
    std::cout << idx << std::endl;

    return 0;
}
