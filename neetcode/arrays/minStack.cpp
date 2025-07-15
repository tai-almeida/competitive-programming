#include <bits/stdc++.h>

using namespace std;

class MinStack {
    public:
    stack<int> stk;
    MinStack() {
        //init
    }

    void push(int val) {
        stk.push(val);
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        stack<int> aux;
        // O(n)
        if(stk.empty()) {
            return -1;
        } 

        int valorMinimo = stk.top();
        while(!stk.empty()) {
            if(stk.top() < valorMinimo) {
                valorMinimo = stk.top();
                stk.pop();
                aux.push(valorMinimo);
            } else {
                aux.push(stk.top());
                stk.pop();
            }
        }
        while(!aux.empty()) {
            stk.push(aux.top());
            aux.pop();
        }
        return valorMinimo;
    }

};

int main() {
    MinStack minStack;
}