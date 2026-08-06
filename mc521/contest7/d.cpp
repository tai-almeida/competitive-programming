#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    vector<vector<long long>> dp(n+1, vector<long long>(n+1));
    for(int i = 0; i< n; i++) {
        cin >> a[i];
        dp[i][i] = a[i];
    }

    for(int len = 2; len <=n; len++) {
        for(int left = 0; left <= n - len; left++) {
            int right = left + len - 1;
            dp[left][right] = max(a[left] - dp[left+1][right], a[right] - dp[left][right-1]);

        }
    }

    cout << dp[0][n-1] << '\n';
    return 0;
}