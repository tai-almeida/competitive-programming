#include <bits/stdc++.h>

using namespace std;

vector<int> fim_aux;
vector<int> inicio_aux;
vector<int> reservas;

void intercala(vector<int>& inicio, vector<int>& fim, int esq, int q, int dir) {
    
    for(int i=esq; i<=q; i++) {
        fim_aux[i] = fim[i];
        inicio_aux[i] = inicio[i];
    }
    for(int i= q+1; i<=dir; i++) {
        fim_aux[dir + q +1 - i] = fim[i];
        inicio_aux[dir + q +1 - i] = inicio[i];
    }

    int i=esq;
    int j=dir;
    for(int k=esq; k<=dir; k++) {
        if(fim_aux[i] <= fim_aux[j]) {
            fim[k] = fim_aux[i];
            inicio[k] = inicio_aux[i];
            i++;
        } else {
            fim[k] = fim_aux[j];
            inicio[k] = inicio_aux[j];
            j--;
        }
    }
}

void merge_sort(vector<int>& inicio, vector<int>& fim, int esq, int dir) {
    if(esq < dir) {
        int q = (esq + dir)/2;
        merge_sort(inicio, fim, esq, q);
        merge_sort(inicio, fim, q+1, dir);
        intercala(inicio, fim, esq, q, dir);
    }
    return;
}

int busca_binaria(vector<int>& fim, vector<int>& inicio, int esq, int dir, int melhor, int idx) {
    if(esq <= dir) {
        int meio = (esq+dir) / 2;
        if(fim[meio] <= inicio[idx]) {
            return busca_binaria(fim, inicio, meio+1, dir, meio, idx);
        } else  {
            return busca_binaria(fim, inicio, esq, meio-1, melhor, idx);
        }
    }
    return melhor;
}

int agenda_max_reservas(vector<int>& inicio, vector<int>& fim, int num_reservas) {
    reservas[0] = fim[0] - inicio[0];
    int tempo, max_indice;
    for(int i=1; i<num_reservas; i++) {
        tempo = fim[i] - inicio[i];
        max_indice = busca_binaria(fim, inicio, 0, i-1, -1, i);
        reservas[i] = max(tempo + reservas[max_indice], reservas[i-1]); 
    }
    return reservas[num_reservas-1];
}


int main() {
    int num_reservas;
    cin >> num_reservas;

    vector<int> inicio(num_reservas), fim(num_reservas);

    for(int i=0; i<num_reservas; i++) {
        cin >> inicio[i] >> fim[i];
    }

    // ordena pelo min de fim
    inicio_aux.resize(num_reservas);
    fim_aux.resize(num_reservas);
    merge_sort(inicio, fim, 0, num_reservas-1);

    reservas.resize(num_reservas);

    cout << agenda_max_reservas(inicio, fim, num_reservas) << '\n';
    
    return 0;
}