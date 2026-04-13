#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, x, y, z;
    cin >> n >> x >> y >> z;

    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> scores(n);
    for(int i=0; i<n; i++) {
        scores[i] = {a[i], b[i]};
    }

    sort(scores.begin(), scores.end(), greater<>());
    int aceitos = 0;
    for(int i=0; i<x; i++) {
        aceitos++;
    }
    scores.erase(scores.begin(), scores.begin() + x);
    
    
    return 0;
}