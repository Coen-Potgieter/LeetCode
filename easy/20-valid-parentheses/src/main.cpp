

#include <string>
#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {


        std::stack<char> myStack;

        for (const char& elem: s) {
            if ((elem == '(') || (elem == '[') || (elem == '{')) {
                myStack.push(elem);
                continue;
            } 

            if (myStack.empty()) {
                return false;
            }


            char poppedElem = myStack.top();
            if ((elem == ')') && (poppedElem != '(')) {
                return false;
            }
            if ((elem == ']') && (poppedElem != '[')) {
                return false;
            }
            if ((elem == '}') && (poppedElem != '{')) {
                return false;
            }
            myStack.pop();
        }
        
        if (!myStack.empty()) {
            return false;
        }
        return true;
    }
};


int main() {

    std::string case1 = "()";
    std::string case2 = "()[]{}";
    std::string case3 = "(]";
    std::string case4 = "([])";
    std::string case5 = "((((";
    std::string case6 = "(";
    std::string case7 = ")";

    std::string inpCase = case7;
    Solution mySol;
    bool ans = mySol.isValid(inpCase);
    std::cout << "Input: " << inpCase << std::endl;
    std::cout << "Answer: " << ans << std::endl;
    return 0;
}
