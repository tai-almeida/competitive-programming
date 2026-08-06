#include <bits/stdc++.h>
#define UNVISITED -1
#define VISITING 0
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
        void dfs(int u, bool &tem_ciclo) {
            dfs_num[u] = VISITING;
            for(int v : adjList[u]) {
                if(dfs_num[v] == UNVISITED) {
                    dfs(v, tem_ciclo);
                } else if (dfs_num[v] == VISITING) {
                    tem_ciclo = true;
                    return;
                }
            }
            dfs_num[u] = VISITED;
            topoSort.push_back(u);
            
            
        }
};

int main() {
    int n, m;

    cin >> n >> m;
    Graph g(n);

    int u, v;
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        g.add_edge(u, v);
    }
    bool tem_ciclo = false;

    topoSort.clear();
    dfs_num.assign(n+1, UNVISITED);
    for(long long i=1; i<=n; i++) {
        if(dfs_num[i] == UNVISITED) {
            g.dfs(i, tem_ciclo);
        }
    }
    reverse(topoSort.begin(), topoSort.end());

    if(tem_ciclo) {
        cout << "IMPOSSIBLE\n";
    } else {
        for(int i=0; i<topoSort.size()-1; i++) {
            cout << topoSort[i] << " ";
        }
        cout << topoSort[topoSort.size()-1] << '\n';
    }

    return 0;
}