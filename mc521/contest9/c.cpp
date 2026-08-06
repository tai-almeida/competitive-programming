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

    vector<long long> dp(n+1, -1);
    vector<long long> predecessores(n+1, -1);
    dp[1] = 1;
    for(long long u : topoSort) {
        for(long long v : g.adjList[u]) {
            if(dp[u] != -1) {
                if(dp[u] + 1 > dp[v]) {
                    dp[v] = dp[u] + 1;
                    predecessores[v] = u;
                } 
            }
            
        }
    }

    if(dp[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    } 

    vector<int> caminho;
    int atual = n;
    while(atual != -1) {
        caminho.push_back(atual);
        atual = predecessores[atual];
    }
    reverse(caminho.begin(), caminho.end());
    
    cout << dp[n] << '\n';
    for(int v : caminho) {
        cout << v << " ";
    }
    cout << '\n';


    
    return 0;
}