#include <bits/stdc++.h>

using namespace std;

int maximiza_amigos(int ferias) {
    vector<int> skiing(ferias), movie(ferias), games(ferias);
    int max_amigos = 0;

    for(int j=0; j<ferias; j++) {
        cin >> skiing[j];
    }
    for(int j=0; j<ferias; j++) {
        cin >> movie[j];
    }
    for(int j=0; j<ferias; j++) {
        cin >> games[j];
    }


    vector<pair<int, int>> pares_s, pares_m, pares_g;
    for(int j=0; j<ferias; j++) {
        pares_s.push_back({skiing[j], j});
        pares_m.push_back({movie[j], j});
        pares_g.push_back({games[j], j});
    }

    sort(pares_s.rbegin(), pares_s.rend());
    sort(pares_m.rbegin(), pares_m.rend());
    sort(pares_g.rbegin(), pares_g.rend());

    vector<pair<int, int>> candidatos_s(3), candidatos_m(3), candidatos_g(3);

    for(int j=0; j<3; j++) {
        candidatos_s[j] = pares_s[j];
        candidatos_m[j] = pares_m[j];
        candidatos_g[j] = pares_g[j];

    }
    
    for(int j=0; j<3; j++) {
        for(int k=0; k<3; k++) {
            for(int l=0; l<3; l++) {
                if(candidatos_s[j].second != candidatos_m[k].second && 
                    candidatos_s[j].second != candidatos_g[l].second && 
                    candidatos_m[k].second != candidatos_g[l].second) {
                        max_amigos = max(max_amigos, candidatos_s[j].first + candidatos_m[k].first + candidatos_g[l].first);
                    }
            }
        }
    }
    return max_amigos;
    
}

int main() {
    int t;
    cin >> t;

    int ferias;
    
    for(int i=0; i<t; i++) {
        cin >> ferias;
        int max_amigos = maximiza_amigos(ferias);
        
        cout << max_amigos << '\n';
    }
    return 0;
}