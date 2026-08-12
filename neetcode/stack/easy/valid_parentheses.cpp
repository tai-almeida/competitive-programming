#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closes;
        closes['['] = ']';
        closes['{'] = '}';
        closes['('] = ')';

        stack<char> stack_chars;

        for(char c : s) {
            if(c == '{' || c == '(' || c == '[') {
                stack_chars.push(c);
            } else if(!stack_chars.empty() && c == closes[stack_chars.top()]) {
                stack_chars.pop();
            } else {
                return false;
            }
        }
        if(!stack_chars.empty()) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution solution = Solution();
    string s = "[]";
    cout << solution.isValid(s) << endl;
}