
#include <unordered_map>
#include <vector>
#include <iostream>

class Solution {

public:
    int totalFruit(std::vector<int>& fruits) {

        std::unordered_map<int, int> ht;
        int maxLength = INT_MIN;
        int myStart = 0;

        for (int end = 0; end < fruits.size(); end++) {

            if (ht.count(fruits[end])) {
                ht[fruits[end]] += 1;
            } else {
                ht[fruits[end]] = 1;
            }

            if (ht.size() <= 2) {
                if ((end - myStart + 1) > maxLength) maxLength = end-myStart+1;
            } else {
                if (ht[fruits[myStart]] == 1) {
                    ht.erase(fruits[myStart]);
                } else {
                    fruits[myStart] -= 1;
                }

                end -= 1;
                myStart += 1;
            }
        }

        return (maxLength == INT_MIN) ? 0 : maxLength;
    }
};

int main() {
    Solution sol;

    std::vector<int> fruits1 = { 1,2,1 };
    std::vector<int> fruits2 = {0,1,2,2};
    std::vector<int> fruits3 = {1,2,3,2,2};
    std::vector<int> fruits4 = {3,3,3,1,2,1,1,2,3,3,4};

    std::vector<int> fruits = fruits4;

    std::cout << "Fruits: "; for (const int& elem : fruits) { std::cout << elem << ", ";}
    std::cout << "\nOutput: " << sol.totalFruit(fruits) << std::endl;
    return 0;
}
