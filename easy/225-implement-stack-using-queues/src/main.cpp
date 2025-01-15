
#include <queue>
#include <iostream>

class MyStack {
private:

    std::queue<int> q;
public:


    MyStack() {
    }

    
    void push(int x) {
        std::queue<int> newQ;
        int oldVal;

        newQ.push(x);

        while (q.size() > 0) {
            oldVal = q.front();
            q.pop();
            newQ.push(oldVal);
        }
        q = newQ;
    }
    
    int pop() {

        int oldVal = q.front();
        q.pop();
        return oldVal;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return (q.size() <= 0);
    }
};

int main() {

    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();

    std::cout << "param_2: " << param_2 << std::endl;
    std::cout << "param_3: " << param_3 << std::endl;
    std::cout << "param_4: " << param_4 << std::endl;

    delete obj;
    return 0;
}



