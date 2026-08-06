#include <bits/stdc++.h>
#define MAX_ASCII 128
#define INF 1e18

using namespace std;

int main() {

    string message, encripted;
    cin >> message >> encripted;

    int m;
    cin >> m;


    vector<vector<long long>> dist(MAX_ASCII, vector<long long>(MAX_ASCII, INF));

    for (int i = 0; i < MAX_ASCII; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {

        char a, b;
        long long c;

        cin >> a >> b >> c;
        a = (int)a;
        b = (int)b;

        dist[a][b] = min(dist[a][b], c);
    }

    for (int k = 0; k < MAX_ASCII; k++) {
        for (int i = 0; i < MAX_ASCII; i++) {
            for (int j = 0; j < MAX_ASCII; j++) {

                if (dist[i][k] == INF || dist[k][j] == INF) {
                    continue;
                }
                    
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

            }
        }
    }

    long long ans = 0;


    for (int i = 0; i < message.size(); i++) {
        int u = (int)message[i];
        int v = (int)encripted[i];

        if (dist[u][v] == INF) {
            cout << -1 << "\n";
            return 0;
        }

        ans += dist[u][v];
    }

    cout << ans << "\n";

    return 0;
}