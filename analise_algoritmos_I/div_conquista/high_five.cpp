#include <bits/stdc++.h>

using namespace std;

long long intercala(vector<int>& atletas, int inicio, int q, int final, vector<int>& vetor_aux) {
    long long num_hf = 0;
    
    for(int i=inicio; i<=q; i++) {
        vetor_aux[i] = atletas[i];
    }
    for(int i= q+1; i<=final; i++) {
        vetor_aux[final + q +1 - i] = atletas[i];
    }

    int i=inicio;
    int j=final;
    for(int k=inicio; k<=final; k++) {
        if(vetor_aux[i] < vetor_aux[j]) {
            atletas[k] = vetor_aux[i];
            // dif entre os maiores valores
            num_hf += j-q; 
            i++;
        } else if(vetor_aux[i] == vetor_aux[j]) {
            atletas[k] = vetor_aux[i];
            i++;
        } else {
            atletas[k] = vetor_aux[j];
    
            j--;
        }
    }
    return num_hf;
}

long long hf_merge_sort(vector<int>& atletas, int p, int r, vector<int>& vetor_aux) {
    if(p<r) {
        int q = (p+r)/2;
        long long hf_esq = hf_merge_sort(atletas, p, q, vetor_aux);
        long long hf_dir = hf_merge_sort(atletas, q+1, r, vetor_aux);
        long long hf_intercala = intercala(atletas, p, q, r, vetor_aux);
        return hf_esq+hf_dir+hf_intercala;
    }
    return 0;
}

int main() {
    int num_atletas;
    vector<int> vetor_aux;
    vector<int> atletas;
    while(cin >> num_atletas) {
        atletas.resize(num_atletas);
        int id;
        for(int i=0; i<num_atletas; i++) {
            cin >> id;
            atletas[i] = id;
        }
        vetor_aux.resize(num_atletas);
        cout << hf_merge_sort(atletas, 0, num_atletas-1, vetor_aux) << '\n';
    }
    return 0;
}