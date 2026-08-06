#include <bits/stdc++.h>
#define UNVISITED -1
#define VISITED 1

using namespace std;

vector<int> dfs_num;


class Graph {
    vector<vector<int>> adjList;

    public:
        void add_edge(int u, int v) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        void dfs(Graph g, int u) {
            printf(" %d", u);
            dfs_num[u] = VISITED;
            for(int v : adjList[u]) {
                if(dfs_num[v] == UNVISITED) {
                    dfs(g, v);
                }
            }
            
        }
};




int main() {
    Graph g;
    int n, m;
    cin >> n >> m;
    int u,v;
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        g.add_edge(u, v);
    }

    int s, t, ds, dt;
    cin >> s >> t >> ds >> dt;

    








    return 0;
}