#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;

    cin >> s;
    cin >> t;

    unordered_map<char, bool> present_chars;
    for(int i=0; i<t.length(); i++) {
        present_chars[t[i]] = true;
    }

    bool valid = false;
    for(int i=1; i<s.length(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            if(present_chars[s[i-1]]) {
                valid = true;
            } else {
                valid = false;
                cout << "No" << '\n';
                return 0;
            }
        }
    }

    cout << "Yes" << '\n';
    return 0;

}