#include <bits/stdc++.h>

using namespace std;

int lcs(string &s, string &t, int m, int n, vector<vector<int>> &dp) {
    if(m ==0 || n == 0) {
        return 0;
    }

    if(dp[m][n] != -1) {
        return dp[m][n];
    }

    if(s[m-1] == t[n-1]) {
        // seq.push_back(s[m-1]);
        // s.erase(1, m-1);
        return dp[m][n] = 1 + lcs(s, t, m-1, n-1, dp);
    }
    return dp[m][n] = max(lcs(s, t, m, n-1, dp), lcs(s, t, m-1, n, dp));
}

int main() {
    string s, t;
    cin >> s;
    cin >> t;

    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length()+1, -1));
    string seq = "";

    int m = s.length();
    int n = t.length();
    lcs(s, t, m, n, dp);
    while(m > 0 && n > 0) {
        if(s[m-1] == t[n-1]) {
            seq.push_back(s[m-1]);
            m--;
            n--;
        } else if(dp[m-1][n] > dp[m][n-1]) {
            m--;
        } else {
            n--;
        }
    }

    reverse(seq.begin(), seq.end());
    
    cout << seq << '\n';

    return 0;
}