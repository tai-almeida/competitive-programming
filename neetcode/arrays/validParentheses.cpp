#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string input) {
        stack<char> stackChars;
        string openChars = "({[";
        string closedChars = ")}]";
        vector<string> pairs;
        pairs = {"{}", "[]", "()"};
        bool encontrou = false;
        bool stringValida = false;

        for(int i=0; i<input.size(); i++) {
            // verifies if it is an open bracket
            if(openChars.find(input[i]) != string::npos) {
                stackChars.push(input[i]);
            }

            // closed bracket
            if(closedChars.find(input[i]) != string::npos) {
                if(stackChars.empty()) {
                    return false;
                }

                for(int j=0; j<3; j++) {
                    // checks if the char on top of the stack matches the char on input[i]
                    if(pairs[j] == (string(1, stackChars.top()) + string(1, input[i]))) {
                        encontrou = true;
                        break;
                    } 
                }
                if(encontrou) {
                    stackChars.pop();
                    encontrou = false;
                } else {
                    return false;
                }
            }
        }

        if(stackChars.empty()) {
            // for it to be valid, the stack must end empty
            stringValida = true;
        }

        return stringValida;
    }
};



int main() {
    Solution sol;
    string input;
    cin >> input;

    if(sol.isValid(input)) {
        cout << "true" << "\n";
    } else {
        cout << "false" << "\n";
    }
}

// tempo: O(n)
// espaco: O(n)