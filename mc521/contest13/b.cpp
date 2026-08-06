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

    vector<bool> vertices_alcancaveis() {
        vector<bool> alcancavel(adj.size(), false);

        queue<int> fila;
        fila.push(0);
        alcancavel[0] = true;

        while (!fila.empty()) {
            int v = fila.front();
            fila.pop();

            for (auto &e : adj[v]) {
                if (e.cap > 0 && !alcancavel[e.para]) {
                    alcancavel[e.para] = true;
                    fila.push(e.para);
                }
            }
        }

        return alcancavel;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n);
    vector<pair<int,int>> streets;

    for (int i = 0; i < m; i++) {
        int a, b;
        // long long c;

        cin >> a >> b;

        graph.addEdge(a - 1, b - 1, 1);
        graph.addEdge(b - 1, a - 1, 1);

        streets.push_back({a,b});
    }

    graph.maxflow(0, n - 1);

    vector<bool> alcancavel = graph.vertices_alcancaveis();

    vector<pair<int,int>> resposta;

    for (pair<int,int> p : streets) {

        if (alcancavel[p.first-1] != alcancavel[p.second-1])
            resposta.push_back({p.first,p.second});
    }

    cout << resposta.size() << '\n';

    for (pair<int,int> p : resposta) {
        cout << p.first << ' ' << p.second << '\n';
    }
        
    return 0;
}