#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<char>> forest(n, vector<char>(n));
    for(int i=0; i<n; i++) {
        string linha;
        cin >> linha;
        for(int j=0; j<n; j++) {
            forest[i][j] = linha[j];
        }
    }

    vector<vector<int>> prefix_sum(n+1, vector<int>(n+1, 0));
    int eh_tree;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(forest[i-1][j-1] == '*') {
                eh_tree = 1;
            } else {
                eh_tree = 0;
            }

            prefix_sum[i][j] = eh_tree + prefix_sum[i-1][j] + 
                                prefix_sum[i][j-1] - prefix_sum[i-1][j-1];

            
        }
    }
    int trees;
    int y1, x1, y2, x2;
    for(int i=0; i<q; i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        trees = prefix_sum[y2][x2] - prefix_sum[y1-1][x2] - 
                prefix_sum[y2][x1-1] + prefix_sum[y1-1][x1-1];
        
        cout << trees << '\n';
    }
    return 0;
}