


#include <vector>
#include <string>
#include <iostream>


class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {

        std::vector<int> runningScores(operations.size(), 0);
        int scoreIdx = 0;

        for (const std::string& opp: operations) {

            if (opp == "+") {
                runningScores[scoreIdx] += runningScores[scoreIdx - 1];
                runningScores[scoreIdx] += runningScores[scoreIdx - 2];
            } else if (opp == "D") {
                runningScores[scoreIdx] = runningScores[scoreIdx -1] * 2;
            } else if (opp == "C") {
                scoreIdx -= 1;
                runningScores[scoreIdx] = 0;
                continue;
            } else {
                runningScores[scoreIdx] = std::stoi(opp);
            }
            scoreIdx += 1;
        }

        scoreIdx = 0;
        for (const int& elem : runningScores) {
            scoreIdx += elem;
        }
        return scoreIdx;
    }
};

int main() {


    Solution mySol;

    std::vector<std::string> case1 = { "5","-2","4","C","D","9","+","+" };
    std::vector<std::string> case2 = {"5","2","C","D","+"};

    std::vector<std::string> inpCase = case2;

    int ans = mySol.calPoints(inpCase);

    for (const std::string& c: inpCase) {
        std::cout << c << ", ";
    }

    std::cout << std::endl;

    std::cout << "Output: " << ans << std::endl;


    return 0;
}
