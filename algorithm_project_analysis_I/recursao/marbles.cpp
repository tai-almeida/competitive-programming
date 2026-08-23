#include <bits/stdc++.h>

using namespace std;

void intercala(vector<int>& vetor_marbles, int inicio, int q, int final) {
    vector<int> vetor_aux(final+1, 0);
    for(int i=inicio; i<=q; i++) {
        vetor_aux[i] = vetor_marbles[i];
    }
    for(int i= q+1; i<=final; i++) {
        vetor_aux[final + q +1 - i] = vetor_marbles[i];
    }

    int i=inicio;
    int j=final;
    for(int k=inicio; k<=final; k++) {
        if(vetor_aux[i] <= vetor_aux[j]) {
            vetor_marbles[k] = vetor_aux[i];
            i++;
        } else {
            vetor_marbles[k] = vetor_aux[j];
            j--;
        }
    }
}

void merge_sort(vector<int>& vetor_marbles, int inicio, int final) {
    if(inicio < final) {
        int q = (inicio + final)/2;
        merge_sort(vetor_marbles, inicio, q);
        merge_sort(vetor_marbles, q+1, final);
        intercala(vetor_marbles, inicio, q, final);
    }
}

int busca_binaria(vector<int>& vetor_marbles, int esq, int dir, int elemento) {
    // while(consultas_feitas <=consultas) {
    if(esq <= dir) {
        int meio = (esq+dir)/2;
        if(vetor_marbles[meio] == elemento) {
            // pegar o primeiro
            while(meio>=1 && vetor_marbles[meio-1] == elemento) {
                meio--;
            }
            return meio+1;
        } else if (vetor_marbles[meio] < elemento) {
            return busca_binaria(vetor_marbles, meio+1, dir, elemento);
        } else {
            return busca_binaria(vetor_marbles, esq, meio-1, elemento);
        }
    } else {
        return 0;
    }
}

int main() {
    int marbles, num_consultas;
    int j=1;
    
    while ((cin >> marbles) && (cin >> num_consultas) && marbles != 0  && num_consultas != 0) {
        vector<int> vetor_marbles(marbles, 0);
        for(int i=0; i<marbles; i++) {
            cin >> vetor_marbles[i];
        }

        vector<int> elementos(num_consultas);
        for(int i=0; i<num_consultas; i++) {
            cin >> elementos[i];
        }

        // ordena ascendente
        merge_sort(vetor_marbles, 0, vetor_marbles.size()-1);
        
        cout << "CASE# " << j <<":\n";

        // busca binaria q vezes
        for(int i=0; i<num_consultas; i++) {
            int posicao = busca_binaria(vetor_marbles, 0, marbles-1, elementos[i]);
            if(posicao == 0) {
                cout << elementos[i] << " not found\n";
            } else {
                cout << elementos[i] << " found at " << posicao << "\n";
            }
        }
        j++;
    }
}