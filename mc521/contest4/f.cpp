#include <bits/stdc++.h>

using namespace std;

long long obtem_max_factor(vector<pair<long long, long long>> friends, long long n, long long d) {
    long long soma = 0;
    long long max_factor = 0;

    int left = 0;
    for(int right = 0; right < n; right++) {
        soma += friends[right].second;

        while(friends[right].first - friends[left].first >= d) {
            soma -= friends[left].second;
            left++;
        }

        max_factor = max(max_factor, soma);
        
    }
    return max_factor;

}

int main() {
    long long n, d;
    cin >> n >> d;

    vector<pair<long long, long long>> friends(n);

    for(int i=0; i<n; i++) {
        cin >> friends[i].first >> friends[i].second;
    }

    sort(friends.begin(), friends.end());

    cout << obtem_max_factor(friends, n, d) << '\n';

    return 0;
}