#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> stk;
    stack<int> min_stack;
    MinStack() {
        
    }

    void push(int val) {
        stk.push(val);
        if(min_stack.empty()) {
            min_stack.push(val);
        } else if(val  < min_stack.top()) {
            min_stack.push(val);
        } else {
            min_stack.push(min_stack.top());
        }
    }

    void pop() {
        stk.pop();
        min_stack.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stack.top();
    }
};

