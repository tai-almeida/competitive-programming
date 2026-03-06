#include <bits/stdc++.h>

using namespace std;

int main() {
    int n_jogadas;
    int pts_antonia = 100, pts_david = 100;
    cin >> n_jogadas;

    vector<int> res_antonia(n_jogadas, 0), res_david(n_jogadas, 0);

    for(int i = 0; i<n_jogadas; i++) {
        cin >> res_antonia[i] >> res_david[i];
    }

    for(int i=0; i<n_jogadas; i++) {
        if(res_antonia[i] > res_david[i]) {
            pts_david -= res_antonia[i];
        } else if(res_david[i] > res_antonia[i]) {
            pts_antonia -= res_david[i];
        } else {
            continue;
        }
    }

    cout << pts_antonia << '\n' << pts_david;
    
    return 0;
}