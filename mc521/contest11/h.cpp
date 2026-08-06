#include <bits/stdc++.h>
#define INF 1e18


using namespace std;


int main() {
    string s, t;
    cin >> s >> t;
    int n;

    if (t.size() != s.size()) {
        cout << -1 << "\n";
        return 0;
    }
    cin >> n;

    vector<vector<long long>> dist(26, vector<long long>(26, INF));

    for (int i = 0; i < 26; i++) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        char a, b;
        long long w;
        cin >> a >> b >> w;

        int u = a - 'a';
        int v = b - 'a';

        dist[u][v] = min(dist[u][v], w);
    }

    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF) {
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    long long total = 0;
    string res = "";

    for (int i = 0; i < s.size(); i++) {
        int a = s[i] - 'a';
        int b = t[i] - 'a';
        char best_char = '\0';
        long long best = INF;
        

        for (int c = 0; c < 26; c++) {
            if (dist[a][c] == INF || dist[b][c] == INF) {
                continue;
            }

            long long custo = dist[a][c] + dist[b][c];

            if (custo < best) {
                best = custo;
                best_char = char(c + 'a');
            }
        }
        if (best == INF) {
            cout << -1 << "\n";
            return 0;
        }


        total += best;
        res += best_char;
    }

    cout << total << "\n";
    cout << res << "\n";

    return 0;
}