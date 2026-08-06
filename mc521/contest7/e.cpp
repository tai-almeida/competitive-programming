#include <bits/stdc++.h>

using namespace std;

long long dp_mrs(int n, vector<long long> &seq, vector<long long> &dp) {
    dp[0] = seq[0];
    long long maxMRS = dp[0];

    for(int i=1; i<n; i++) {
        dp[i] = max(seq[i], dp[i-1] + seq[i]);
        maxMRS = max(maxMRS, dp[i]);
    }

    return maxMRS;

}

int main() {
    int n;
    cin >> n;

    vector<long long> seq(n);
    for(int i=0; i<n; i++) {
        cin >> seq[i]; 
    }

    vector<long long> dp(n+1);
    cout << dp_mrs(n, seq, dp) << '\n';

    return 0;
}