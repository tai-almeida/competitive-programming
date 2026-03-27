#include <bits/stdc++.h>
#include <math.h>

using namespace std;

double f(int p, int q, int r, int s, int t, int u, double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

bool theres_solution(int p, int q, int r, int s, int t, int u) {
    double f0, f1;
    f0 = f(p, q, r, s, t, u, 0);
    f1 = f(p, q, r, s, t, u, 1);
    if(f0*f1 <= 0) { // tem q ter troca de sinal
        return true;
    }
    return false;
}

double binary_search(int p, int q, int r, int s, int t, int u, double esq, double dir) {
    double meio = (esq+dir)/2.0;

    double f_esq = f(p, q, r, s, t, u, esq);
    double f_meio = f(p, q, r, s, t, u, meio);

    if(dir - esq <= 1e-9) {
        return meio;
    } else {
        if(f_meio <= 0) {
            return binary_search(p, q, r, s, t, u, esq, meio);
        } else {
            return binary_search(p, q, r, s, t, u, meio, dir);
        }
    }
    return meio;
}


int main() {
    int p, q, r, s, t, u;
    while(cin >> p >> q >> r >> s >> t >> u) {
        
        if(!theres_solution(p, q, r, s, t, u)) {
            cout << "No solution\n";
        } else {
            cout << fixed << setprecision(4) << binary_search(p, q, r, s, t, u, 0, 1) << '\n';
        }
    } 

    return 0;
}