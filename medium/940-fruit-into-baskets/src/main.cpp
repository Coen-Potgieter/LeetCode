
#include <unordered_map>
#include <vector>
#include <iostream>

class Solution {

public:
    int totalFruit(std::vector<int>& fruits) {

        std::unordered_map<int, int> ht;
        int maxLength = INT_MIN;
        int myStart = 0;
        int myEnd = 0;

        bool add = true;

        while (myEnd < fruits.size()) {

            if (add) {
                if (ht.count(fruits[myEnd])) {
                    ht[fruits[myEnd]] += 1;
                } else {
                    ht[fruits[myEnd]] = 1;
                }
            }

            if (ht.size() <= 2) {

                if ((myEnd - myStart + 1) > maxLength) {
                    maxLength = myEnd - myStart + 1;
                }
                myEnd += 1;
                add = true;


            } else {

                ht[fruits[myStart]] -= 1;
                if (ht[fruits[myStart]] <= 0) {
                    ht.erase(fruits[myStart]);
                }
                myStart += 1;
                add = false;
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
