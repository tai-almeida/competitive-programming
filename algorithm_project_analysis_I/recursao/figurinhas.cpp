#include <bits/stdc++.h>

using namespace std;

int euclides(int fig_renato, int fig_vicente) {
    if(fig_vicente <= 0) {
        return fig_renato;
    } else {
        int resto = fig_renato % fig_vicente;
        fig_renato = euclides(fig_vicente, resto);
    }
    return fig_renato;
}

int main() {
    int casos_teste;
    cin >> casos_teste;
    
    vector<int> fig_renato(casos_teste, 0), fig_vicente(casos_teste, 0);
    vector<int> tam_pilha(casos_teste, 0);
    for(int i=0; i<casos_teste; i++) {
        // le cada linha de entrada
        cin >> fig_renato[i] >> fig_vicente[i];
    }
    for(int i=0; i<casos_teste; i++) {
        tam_pilha[i] = euclides(fig_renato[i], fig_vicente[i]);
        cout << tam_pilha[i] << '\n';
    }
    return 0;
}

