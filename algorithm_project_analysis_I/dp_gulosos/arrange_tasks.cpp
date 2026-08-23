#include <bits/stdc++.h>

using namespace std;

vector<int> lucros_aux;
vector<int> prazos_aux;

void intercala(vector<int>& lucros, vector<int>& prazos, int esq, int q, int dir) {
    
    for(int i=esq; i<=q; i++) {
        prazos_aux[i] = prazos[i];
        lucros_aux[i] = lucros[i];
    }
    for(int i= q+1; i<=dir; i++) {
        prazos_aux[dir + q +1 - i] = prazos[i];
        lucros_aux[dir + q +1 - i] = lucros[i];
    }

    int i=esq;
    int j=dir;
    for(int k=esq; k<=dir; k++) {
        if(lucros_aux[i] > lucros_aux[j]) {
            prazos[k] = prazos_aux[i];
            lucros[k] = lucros_aux[i];
            i++;
        } else {
            prazos[k] = prazos_aux[j];
            lucros[k] = lucros_aux[j];
            j--;
        }
    }
}

void merge_sort(vector<int>& lucros, vector<int>& prazos, int esq, int dir) {
    if(esq < dir) {
        int q = (esq + dir)/2;
        merge_sort(lucros, prazos, esq, q);
        merge_sort(lucros, prazos, q+1, dir);
        intercala(lucros, prazos, esq, q, dir);
    }
    return;
}

int arrange_tasks(vector<int>& lucros, vector<int>& prazos, vector<int>& horarios, int tasks) {
    int lucro_total = 0;
    int lucro_obtido = 0;

    for(int i=0; i<tasks; i++) {
        lucro_total += lucros[i];
        for(int j=prazos[i]; j>0; j--){
            // se o horario tiver livre
            if(horarios[j] == 0) {
                horarios[j] = 1;
                lucro_obtido += lucros[i];
                break;
            }
        }
    }

    return (lucro_total - lucro_obtido);

}

int main() {
    int tasks, horario_disp;
    vector<int> lucros, prazos, horarios;
    while(cin >> tasks >> horario_disp) {
        lucros.resize(tasks, 0), prazos.resize(tasks, 0);

        for(int i=0; i<tasks; i++) {
            cin >> lucros[i] >> prazos[i];
        }

        lucros_aux.resize(tasks, 0);
        prazos_aux.resize(tasks, 0);
        // ordena decrescente pelo lucro
        merge_sort(lucros, prazos, 0, tasks-1);

        horarios.clear();
        horarios.resize(horario_disp+1, 0);
        

        cout << arrange_tasks(lucros, prazos, horarios, tasks) << '\n';
        
    }

    return 0;
}