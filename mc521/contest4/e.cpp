#include <bits/stdc++.h>

using namespace std;

long long soma_digitos(long long x) {
    long long sx = 0;

    while(x != 0) {
        // vai isolando os digitos
        sx += x % 10;
        x /= 10;
    }
    return sx;
}

int main() {
    long long n;
    cin >> n;

    long long x = sqrt(n);

    // x tem so ate 10 digitos ent vale s < 9x18
    for(int s = 1; s < 90; s++) { 

        //calc bhaskara 
        long long delta = s*s + 4*n; 
        long long raiz_d = sqrt(delta);
        long long x = (raiz_d - s) / 2;

        // verifica eq
        if(x > 0 && (x*x + soma_digitos(x)*x == n)) {
            cout << x << '\n';
            return 0;
        }

    }
    cout << -1 << '\n';
    return 0;
}