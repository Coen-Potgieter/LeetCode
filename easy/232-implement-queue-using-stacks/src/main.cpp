
#include <stack>
#include <iostream>

class MyQueue {
private:
    std::stack<int> s;
public:
    MyQueue() {

    }

    void push(int x) {
        std::stack<int> tmpStack;

        while (s.size() > 0) {
            tmpStack.push(s.top());
            s.pop();
        }
        s.push(x);
        while (tmpStack.size() > 0) {
            s.push(tmpStack.top());
            tmpStack.pop();
        }
    }

    int pop() {
        int res = s.top();
        s.pop();
        return res;
    }

    int peek() {
        return s.top();
    }

    bool empty() {
        return (s.size() <= 0);
    }
};

int main() {
    /* Your MyQueue object will be instantiated and called as such: */
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();

    std::cout << "`param_2`: " << param_2 << std::endl;
    std::cout << "`param_3`: " << param_3 << std::endl;
    std::cout << "`param_4`: " << param_4 << std::endl;

    delete obj;
    return 0;


}






