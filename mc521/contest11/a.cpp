#include <bits/stdc++.h>

using namespace std;

int main() {
    int t = 1;
    int n;

    while(cin >> n && n) {

        unordered_map<string, int> id;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            id[s] = i;
        }

        vector<vector<double>> dists(n, vector<double>(n, 0.0));

        for (int i = 0; i < n; i++) {
            dists[i][i]  = 1.0;
        }

        int m;
        cin >> m;

        for (int i = 0; i < m; i++) {
            string a, b;
            double rate;

            cin >> a >> rate >> b;

            int u = id[a];
            int v = id[b];

            dists[u][v] = max(dists[u][v], rate);
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dists[i][j] = max(dists[i][j], dists[i][k] * dists[k][j]);
                }
            }
        }

        bool arbitrage = false;

        for (int i = 0; i < n; i++) {
            if (dists[i][i] > 1.0) {
                arbitrage = true;
                break;
            }
        }

        if(arbitrage) {
            cout << "Case " << t << ": " << "Yes" << "\n";
        } else {
            cout << "Case " << t << ": " << "No" << "\n";
        }

        
        t++;
    }

    return 0;
}

