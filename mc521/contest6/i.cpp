#include <bits/stdc++.h>

using namespace std;


void matrix_chain(int n, vector<vector<int>>& m, vector<int>& dims) {
    for(int i=0; i<n; i++) {
        m[i][i] = 0;
    }

    for(int u = 1; u<n; u++) {
        for (int i = 0; i< n-u; i++) {
            int j=i+u;
            m[i][j] = 1e9;
            for(int k =i; k<j; k++) {
                int q = m[i][k] + m[k+1][j] + dims[i]*dims[k+1]*dims[j+1];
                if(q<m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> r(n), c(n);
    vector<int> dims(n+1);
    vector<vector<int>> m(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        cin >> r[i] >> c[i];

        if(i == 0) {
            dims[0] = r[i];
            dims[1] = c[i];
        } else {
            dims[i+1] = c[i];
        }
        
        matrix_chain(n, m, dims);

    }

    cout << m[0][n-1] << '\n';
    return 0;
}