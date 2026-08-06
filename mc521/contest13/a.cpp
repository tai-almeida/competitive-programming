#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int para, rev;
    long long cap;
};

class Graph {
    vector<vector<Edge>> adj;
    vector<int> level, ptr;

public:
    Graph(int n) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void addEdge(int u, int v, long long cap) {
        Edge a = {v, (int)adj[v].size(), cap};
        Edge b = {u, (int)adj[u].size(), 0};

        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);

        queue<int> fila;
        fila.push(s);
        level[s] = 0;

        while (!fila.empty()) {
            int v = fila.front();
            fila.pop();

            for (auto &e : adj[v]) {
                if (e.cap > 0 && level[e.para] == -1) {
                    level[e.para] = level[v] + 1;
                    fila.push(e.para);
                }
            }
        }

        return level[t] != -1;
    }

    long long dfs(int v, int t, long long pushed) {
        if (pushed == 0) {
            return 0;
        } 
        if (v == t) {
            return pushed;
        } 

        for (int &cid = ptr[v]; cid < adj[v].size(); cid++) {
            Edge &e = adj[v][cid];

            if (level[e.para] != level[v] + 1 || e.cap == 0)
                continue;

            long long tr = dfs(e.para, t, min(pushed, e.cap));

            if (tr == 0) {
                continue;
            }

            e.cap -= tr;
            adj[e.para][e.rev].cap += tr;

            return tr;
        }

        return 0;
    }

    long long maxflow(int s, int t) {
        long long flow = 0;

        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);

            while (long long pushed = dfs(s, t, LONG_LONG_MAX))
                flow += pushed;
        }

        return flow;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;

        cin >> a >> b >> c;

        graph.addEdge(a - 1, b - 1, c);
    }

    cout << graph.maxflow(0, n-1) << "\n";
    return 0;
}