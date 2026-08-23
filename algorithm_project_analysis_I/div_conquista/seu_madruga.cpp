#include <bits/stdc++.h>

using namespace std;

double calcula_area(vector<int>& comprimento_tiras, int qtd_tiras, double altura) {
    double area_cortada = 0.0;
    for(int i=0; i<qtd_tiras; i++) {
        if(comprimento_tiras[i]>altura) {
            area_cortada +=(comprimento_tiras[i]-altura);
        }
    }
    return area_cortada;
}

double busca_binaria(vector<int>& comprimento_tiras, int qtd_tiras, double esq, double dir, double area_resultante, int buscas) {
    buscas++;
    double meio = (esq+dir)/2.0;
    if(buscas < 100 && (dir - esq) > 1e-6) {
        double area_cortada = calcula_area(comprimento_tiras, qtd_tiras, meio);
        if(area_cortada == area_resultante) {
            return meio;
        }

        if(area_cortada < area_resultante) {
            return busca_binaria(comprimento_tiras, qtd_tiras, esq, meio, area_resultante, buscas);
        } else {
            return busca_binaria(comprimento_tiras, qtd_tiras, meio, dir, area_resultante, buscas);
        }
    }
    return meio;
}


void intercala(vector<int>& comprimento_tiras, int inicio, int q, int final) {
    vector<int> vetor_aux(final+1, 0);
    for(int i=inicio; i<=q; i++) {
        vetor_aux[i] = comprimento_tiras[i];
    }
    for(int i= q+1; i<=final; i++) {
        vetor_aux[final + q +1 - i] = comprimento_tiras[i];
    }

    int i=inicio;
    int j=final;
    for(int k=inicio; k<=final; k++) {
        if(vetor_aux[i] <= vetor_aux[j]) {
            comprimento_tiras[k] = vetor_aux[i];
            i++;
        } else {
            comprimento_tiras[k] = vetor_aux[j];
            j--;
        }
    }
}

void merge_sort(vector<int>& comprimento_tiras, int inicio, int final) {
    if(inicio < final) {
        int q = (inicio + final)/2;
        merge_sort(comprimento_tiras, inicio, q);
        merge_sort(comprimento_tiras, q+1, final);
        intercala(comprimento_tiras, inicio, q, final);
    }
}

int main() {
    int qtd_tiras, area_resultante;
    vector<int> comprimento_tiras;

    while(cin >> qtd_tiras >> area_resultante && (qtd_tiras != 0 || area_resultante != 0)) {
        comprimento_tiras.resize(qtd_tiras, 0);
        int area_total = 0;
        for(int i=0; i<qtd_tiras; i++) {
            cin >> comprimento_tiras[i];
            area_total +=comprimento_tiras[i];
        }
        if(area_total == area_resultante) {
            cout << ":D" << '\n';
        } else if(area_total < area_resultante) {
            cout << "-.-" << '\n';
        } else {
            merge_sort(comprimento_tiras, 0, qtd_tiras-1);

            double altura = busca_binaria(comprimento_tiras, qtd_tiras, 0, comprimento_tiras[qtd_tiras-1], area_resultante, 0);
            cout << fixed << setprecision(4) << altura << '\n';
        } 
    }
    
    return 0;
}