#include <bits/stdc++.h>
#define UNVISITED -1
#define VISITED 1

using namespace std;

vector<int> dfs_num;
vector<int> topoSort;

class Graph {
    public:
        vector<vector<int>> adjList;
        Graph(int n) {
            adjList.resize(n+1);
        }
        void add_edge(int u, int v) {
            adjList[u].push_back(v);
        }
        void dfs(int u) {
            dfs_num[u] = VISITED;
            for(int v : adjList[u]) {
                if(dfs_num[v] == UNVISITED) {
                    dfs(v);
                }
            }
            topoSort.push_back(u);
            
        }
};

int main() {
    
    long long n, m; 
    cin >> n >> m;
    Graph g(n);

    for(int i=0; i<m; i++) {
        long long u,v;
        cin >> u >> v;
        g.add_edge(u, v);
    }

    topoSort.clear();
    dfs_num.assign(n+1, UNVISITED);
    for(long long i=1; i<=n; i++) {
        if(dfs_num[i] == UNVISITED) {
            g.dfs(i);
        }
    }
    reverse(topoSort.begin(), topoSort.end());

    vector<long long> caminhos(n+1, 0);
    const long long mod = 1e9 + 7;
    caminhos[1] = 1;
    for(long long u : topoSort) {
        for(long long v : g.adjList[u]) {
            caminhos[v] = (caminhos[v] + caminhos[u]) % mod;
        }
    }

    cout << caminhos[n] << '\n';

    return 0;
}