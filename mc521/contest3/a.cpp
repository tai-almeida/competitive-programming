#include <bits/stdc++.h>

using namespace std;

bool eh_vogal(char c) {
    if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }

    return false;
}

int main() {
    int n;
    string s;

    cin >> n;
    cin >> s;

    string res;

    for (int i=0; i<n; i++) {
        if(i+2 < n && eh_vogal(s[i]) && s[i] == s[i+2] && s[i+1] == 'x') {
            res += "...";
            i += 2;
            
        } else {
            res += s[i];
        }
    }

    cout << res << '\n';


    return 0;
}