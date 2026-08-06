#include <bits/stdc++.h>

using namespace std;


struct DSU {
    vector<int> predecessor, sz;

    DSU(int n) {
        predecessor.resize(n + 1);
        sz.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
            predecessor[i] = i;
    }

    int find(int x) {
        if (predecessor[x] == x) return x;
        return predecessor[x] = find(predecessor[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (sz[a] < sz[b])
            swap(a, b);

        predecessor[b] = a;
        sz[a] += sz[b];

        return true;
    }
};

struct Edge {
    int a, b;
    long long c;

    bool operator<(const Edge& other) const {
        return c < other.c;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].c;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    long long total = 0;
    int used = 0;

    for (auto &e : edges) {
        if (dsu.unite(e.a, e.b)) {
            total += e.c;
            used++;
        }
    }

    if (used != n - 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << total << '\n';
    }

    return 0;
}