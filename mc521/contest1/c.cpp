#include <bits/stdc++.h>

using namespace std;


int main() {
    int n_letters, n_queries; 
    cin >> n_letters >> n_queries;

    string text;
    cin >> text;

    vector<int> query(n_queries), x(n_queries);
    for(int i=0; i<n_queries; i++) {
        cin >> query[i] >> x[i];

    }

    int offset = 0;
    for(int i=0; i<n_queries; i++) {
        if (query[i] == 2) {
            int pos_real = (x[i] - 1 - offset + n_letters) % n_letters;
            cout << text[pos_real] << '\n';
        } else {
            offset = (offset + x[i]) % n_letters;
        }

    }
}

