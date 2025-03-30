


#include <vector>
#include <iostream>
#include <stack>


class MinStack {
public:

    std::stack<int> mainStack;
    std::stack<int> minStack;
    MinStack() = default;

    void push(int val) {

        this->mainStack.push(val);
        if (this->minStack.empty()) {
            this->minStack.push(val);
            return;
        }
        int currMin = this->minStack.top();
        if (val <= currMin) minStack.push(val);
    }

    void pop() {
        int toBePopped = this->mainStack.top();
        if (toBePopped <= this->minStack.top()) minStack.pop();
        this->mainStack.pop();
    }

    int top() {
        return this->mainStack.top();
    }

    int getMin() {
        return this->minStack.top();
    }
};


int main() {

    MinStack *obj = new MinStack();
    obj->push(2147483646); // 1
    obj->push(2147483646); // 2
    obj->push(2147483647); // 3
    std::cout << "Current Top: " << obj->top() << std::endl; // 4
    obj->pop(); // 5
    std::cout << "Current Min: " << obj->getMin() << std::endl; // 6
    obj->pop(); // 7
    std::cout << "Current Min: " << obj->getMin() << std::endl; // 8
    obj->pop(); // 9
    obj->push(2147483647); // 10
    std::cout << "Current Top: " << obj->top() << std::endl; // 11
    std::cout << "Current Min: " << obj->getMin() << std::endl; // 12
    obj->push(-2147483648); // 13
    std::cout << "Current Top: " << obj->top() << std::endl; // 14
    std::cout << "Current Min: " << obj->getMin() << std::endl; // 15
    obj->pop(); // 16
    std::cout << "Current Min: " << obj->getMin() << std::endl; // 15
    /* std::cout << obj->top() << std::endl; */
    delete obj;

    std::cout << INT_MIN << std::endl;
    std::cout << INT_MAX << std::endl;
    return 0;
}

