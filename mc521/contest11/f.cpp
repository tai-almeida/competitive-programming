#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        vector<vector<long long>> dists(n, vector<long long>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dists[i][j];
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
                }
            }
        }

        int orders;
        cin >> orders;

        long long total = 0;

        for (int i = 0; i < orders; i++) {
            int s, d;
            cin >> s >> d;

            s--;
            d--;

            total += dists[s][d];
        }

        cout << "Case #" << t+1 << ": " << total << "\n";
    }

    return 0;
}

