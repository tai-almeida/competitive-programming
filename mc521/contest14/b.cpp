#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        unordered_map<int, long long> n_notes;
        int x;
        for (int j = 0; j < n; j++) {
            cin >> x;
            n_notes[x] += 1;
        }

        long long res = 0;
        for (auto [x, count] : n_notes) {
            res += count * (count - 1) / 2;
        }

        res += n_notes[1] * n_notes[2];
        cout << res << endl;
    }
}