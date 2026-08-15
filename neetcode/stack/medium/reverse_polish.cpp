#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public: 
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        stack<int> factors;
        int res = 0;
        for(string c : tokens) {
            if(c == "+" || c == "*" || c == "-" || c == "/") {
                int second = factors.top();
                factors.pop();
                int first = factors.top();
                factors.pop();
                
                if(c == "+") {
                    res = first + second;
                } else if(c == "*") {
                    res = first * second;
                }else if(c == "-") {
                    res = first - second;
                } else {
                    res = first / second;
                }
                factors.push(res);
            } else {
                int value = stoi(c);
                factors.push(value);
            }
        }
        return factors.top();

    }
};

int main() {
    vector<string> tokens = {"1","2","+","3","*","4","-"};
    Solution s = Solution();
    cout << s.evalRPN(tokens) << endl;
}