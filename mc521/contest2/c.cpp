#include <bits/stdc++.h>

using namespace std;

int dfs(int user, vector<bool>& visited_users, vector<vector<int>>& users_graph) {
    visited_users[user] = true;
    int num_users = 1;


    for(int i = 0; i<users_graph[user].size(); i++) {
        int v = users_graph[user][i];

        if(!visited_users[v]) {
            num_users += dfs(v, visited_users, users_graph);
        }
    }
    return num_users;
}


int main() {
    int users, groups;
    cin >> users >> groups;

    vector<vector<int>> users_graph(users+1);
    vector<bool> visited_users(users+1, false);


    for(int i = 0; i < groups; i++) {
        int num_group_members;
        cin >> num_group_members;

        vector<int> group_members(num_group_members);
        
        // preenche c/ listas de adj
        for(int j=0; j< num_group_members; j++) {
            cin >> group_members[j];

            

        }
        
        for(int j=1; j< num_group_members; j++) {
            int u = group_members[j-1];
            int v = group_members[j];

            users_graph[u].push_back(v);
            users_graph[v].push_back(u);
        }

    

        
    }

    for(int i=0; i < users; i++) {
        cout << dfs(i, visited_users, users_graph) << " ";
    }


    return 0;
}