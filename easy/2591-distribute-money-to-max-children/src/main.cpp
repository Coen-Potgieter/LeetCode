
#include <iostream>
#include <vector>

void printVec(const std::vector<double>& inpVec) {
    std::cout << "Printing Vector:" << std::endl;
    size_t runningIdx = 0;
    for (const double& elem : inpVec) {
        std::cout << "Elem " << runningIdx << ": " << elem << std::endl;
        runningIdx += 1;
    }
}

class DevSolution {
public:
    double calcRemainingMoney(const std::vector<double>& distr, const int money) {
        double runningSum = 0;
        for (const double& elem : distr) {
            runningSum += elem;
        }
        return money - runningSum;
    }
    int giveChildWith4(const std::vector<double>& distr) {

        for (size_t i = 0; i < distr.size(); i++) {
            if (distr[i] == 4.0) {
                return i;
            }
        }
        return -1;
    }

    int calcRemainingMoney(const int numGet8, const int money) {
        return money - 8*numGet8;
    }

    double calcMoneyPerChild(const int remainingMoney, const int remainingChidlren) {
        return remainingMoney / static_cast<double>(remainingChidlren);
    }

    int distMoney(int money, int children){

        std::cout << "Money: " << money << std::endl;
        std::cout << "Children: " << children << std::endl << std::endl;
        std::vector<double> distr(children, 0);

        // Begin with Base Cases

        if (children > money) {
            return -1;
        }

        if (money < 8) {
            return 0;
        }


        int numDivisibleBy8 = money / 8;
        int numGet8 = (numDivisibleBy8 > children) ? children : numDivisibleBy8;
        for (size_t i = 0; i < numGet8; i++) {
            distr[i] = 8;
        }


        int remainingMoney = calcRemainingMoney(numGet8, money);
        int remainingChildren = children - numGet8;
        double moneyRemainingPerChild; 

        if (remainingMoney > 0) {
            // Need to distr remaining money

            if (remainingChildren == 0) {

                // Decrease `numGet8` and reset `distr` vector
                distr = std::vector<double>(children, 0);
                numGet8 -= 1;
                if (numGet8 == 0) {
                    return 0;
                }
                for (size_t i = 0; i < numGet8; i++) {
                    distr[i] = 8;
                }

                remainingMoney = calcRemainingMoney(numGet8, money);
                remainingChildren = children - numGet8;
            } 


        } else if (remainingChildren > 0) {
            // This is now if we have remaining children but no reminaing money
            //  solution: decrease `numGet8` and distr money evenly

            numGet8 -= 1;
            if (numGet8 == 0) {
                return 0;
            }

            distr = std::vector<double>(children, 0);
            for (size_t i = 0; i < numGet8; i++) {
                distr[i] = 8;
            }

            remainingChildren = children - numGet8;
            remainingMoney = calcRemainingMoney(numGet8, money);
        }

        // Distribute remaining money evenly
        moneyRemainingPerChild = calcMoneyPerChild(remainingMoney, remainingChildren);
        for (size_t i = (children - remainingChildren); i < children; i++){
            distr[i] = moneyRemainingPerChild;
        }
        printVec(distr);

        // Some meta stuff here
        //  - if non-get8 kids each have < 1 dollar and then answer is `numGet8 - 1` 

        while (moneyRemainingPerChild < 1) {

            numGet8 -= 1;
            if (numGet8 == 0) {
                return 0;
            }

            remainingChildren += 1;
            remainingMoney = calcRemainingMoney(numGet8, money);
            moneyRemainingPerChild = calcMoneyPerChild(remainingMoney, remainingChildren);
        }

        // Tackling not 4 dollar constraint
        if (moneyRemainingPerChild == 4.0) {
            if (remainingChildren > 1) {
                // If we we have more than 1 kid with 4 dollars then its fine
                return numGet8;
            } else {
                return numGet8 - 1;
            }
        }

        return numGet8;
    }
};


class Solution {
public:
    int calcRemainingMoney(const int numGet8, const int money) {
        return money - 8*numGet8;
    }
    double calcMoneyPerChild(const int remainingMoney, const int remainingChidlren) {
        return remainingMoney / static_cast<double>(remainingChidlren);
    }
    int distMoney(int money, int children){

        // Begin with Base Cases
        if (children > money) {
            return -1;
        }
        if (money < 8) {
            return 0;
        }
        int numDivisibleBy8 = money / 8;
        int numGet8 = (numDivisibleBy8 > children) ? children : numDivisibleBy8;
        int remainingMoney = calcRemainingMoney(numGet8, money);
        int remainingChildren = children - numGet8;
        double moneyRemainingPerChild; 

        if (remainingMoney > 0) {
            // Need to distr remaining money

            if (remainingChildren == 0) {

                // Decrease `numGet8` and reset `distr` vector
                numGet8 -= 1;
                if (numGet8 == 0) {
                    return 0;
                }
                remainingMoney = calcRemainingMoney(numGet8, money);
                remainingChildren = children - numGet8;
            } 
        } else if (remainingChildren > 0) {
            // This is now if we have remaining children but no reminaing money
            //  solution: decrease `numGet8` and distr money evenly

            numGet8 -= 1;
            if (numGet8 == 0) {
                return 0;
            }
            remainingChildren = children - numGet8;
            remainingMoney = calcRemainingMoney(numGet8, money);
        }

        // Distribute remaining money evenly
        moneyRemainingPerChild = calcMoneyPerChild(remainingMoney, remainingChildren);

        //  - if non-get8 kids each have < 1 dollar and then answer is `numGet8 - 1` 
        if (moneyRemainingPerChild < 1) {

            return numGet8 - 1;
        }

        // Tackling not 4 dollar constraint

        if (moneyRemainingPerChild == 4.0) {
            if (remainingChildren > 1) {
                // If we we have more than 1 kid with 4 dollars then its fine
                return numGet8;
            } else {
                return numGet8 - 1;
            }
        }
        return numGet8;
    }
};
int main() {
    DevSolution mine = DevSolution();


    int testCases[10][2];

    testCases[0][0] = 20;
    testCases[0][1] = 3;

    testCases[1][0] = 16;
    testCases[1][1] = 2;

    testCases[2][0] = 18;
    testCases[2][1] = 2;

    testCases[3][0] = 16;
    testCases[3][1] = 3;

    testCases[4][0] = 8;
    testCases[4][1] = 8;

    testCases[5][0] = 17;
    testCases[5][1] = 11;

    testCases[6][0] = 18;
    testCases[6][1] = 10;

    testCases[7][0] = 17;
    testCases[7][1] = 4;

    size_t testCaseIdx = 7;
    int ans = mine.distMoney(testCases[testCaseIdx][0], testCases[testCaseIdx][1]);
    std::cout << "Solution Is: " << ans << std::endl;
    return 0;
}
