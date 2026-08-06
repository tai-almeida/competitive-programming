#include <bits/stdc++.h>

using namespace std;

int main() {
    int dias;
    cin >> dias;

    vector<int> a(dias), b(dias), c(dias);
    for(int i=0; i<dias; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int dp_a = a[0], dp_b = b[0], dp_c = c[0];
    int max_happiness = max({dp_a, dp_b, dp_c});
    for(int i=1; i<dias; i++) {
        int ultimo_a = a[i] + max(dp_b, dp_c);
        int ultimo_b = b[i] + max(dp_a, dp_c);
        int ultimo_c = c[i] + max(dp_a, dp_b);

        dp_a = ultimo_a;
        dp_b = ultimo_b;
        dp_c = ultimo_c;
        max_happiness = max({dp_a, dp_b, dp_c});
    }

    cout << max_happiness << '\n';

    return 0;
}