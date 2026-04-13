#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    vector<int> a;
    for(int i=0; i<t; i++) {
        cin >> n;
        a.resize(n);
        for(int j=0; j<n; j++) {
            cin >> a[j];
        }
        int maximo = a[0];
        long long soma = 0;
        for(int j=1; j<n; j++) {
            if((a[j] > 0 && maximo > 0) || (a[j] < 0 && maximo <0)) {
                maximo = max(maximo, a[j]);
            } else {
                soma += maximo;
                maximo = a[j];
                
            }
        }

        soma += maximo;

        cout << soma << '\n';

    }
    
    return 0;
}