#include <bits/stdc++.h>

using namespace std;

struct Time {
    int id;
    int pontos;
    int pts_marcados;
    int pts_recebidos;
    double avg;
};

void intercala(vector<Time>& times, int inicio, int q, int final, vector<Time>& vetor_aux) {
    for(int i=inicio; i<=q; i++) {
        vetor_aux[i].id = times[i].id;
        vetor_aux[i].pontos = times[i].pontos;
        vetor_aux[i].pts_marcados = times[i].pts_marcados;
        vetor_aux[i].pts_recebidos = times[i].pts_recebidos;
        vetor_aux[i].avg = times[i].avg;
    }
    for(int i= q+1; i<=final; i++) {
        vetor_aux[final + q +1 - i].id = times[i].id;
        vetor_aux[final + q +1 - i].pontos = times[i].pontos;
        vetor_aux[final + q +1 - i].pts_marcados = times[i].pts_marcados;
        vetor_aux[final + q +1 - i].pts_recebidos = times[i].pts_recebidos;
        vetor_aux[final + q +1 - i].avg = times[i].avg;
    }

    int i=inicio;
    int j=final;
    for(int k=inicio; k<=final; k++) {
        if(vetor_aux[i].pontos > vetor_aux[j].pontos) {
            times[k] = vetor_aux[i];
            i++;
        } else if(vetor_aux[i].pontos < vetor_aux[j].pontos) {
            times[k] = vetor_aux[j];
            j--;
        } else {
            if(vetor_aux[i].avg > vetor_aux[j].avg) {
                times[k] = vetor_aux[i];
                i++;
            } else if(vetor_aux[i].avg < vetor_aux[j].avg){
                times[k] = vetor_aux[j];
                j--;
            } else {
                if(vetor_aux[i].pts_marcados > vetor_aux[j].pts_marcados) {
                    times[k] = vetor_aux[i];
                    i++;
                } else if(vetor_aux[i].pts_marcados < vetor_aux[j].pts_marcados) {
                    times[k] = vetor_aux[j];
                    j--;
                } else {
                    if(vetor_aux[i].id < vetor_aux[j].id) {
                        times[k] = vetor_aux[i];
                        i++;
                    } else {
                        times[k] = vetor_aux[j];
                        j--;
                    }
                }
            }
        } 
    }
}

void merge_sort(vector<Time>& times, int inicio, int final, vector<Time>& vetor_aux) {
    if(inicio < final) {
        int q = (inicio + final)/2;
        merge_sort(times, inicio, q, vetor_aux);
        merge_sort(times, q+1, final, vetor_aux);
        intercala(times, inicio, q, final, vetor_aux);
    }
}

int main() {
    int num_times;
    
    Time time_vazio;
    time_vazio.avg=0;
    time_vazio.pts_marcados=0;
    time_vazio.pts_recebidos=0;
    time_vazio.id=0;
    time_vazio.pontos=0;
    int instancias = 1;
    while ((cin >> num_times) && num_times != 0) {
        vector<Time> times(num_times, time_vazio);
        int x, y, z, w;
        vector<int> pontos(num_times, 0);
        for(int i=0; i<(num_times*(num_times-1)/2); i++) {
            cin >> x >> y >> z >> w;
            times[x-1].id = x;
            times[x-1].pts_marcados += y;
            times[x-1].pts_recebidos += w;   
            times[z-1].id = z;
            times[z-1].pts_marcados += w;
            times[z-1].pts_recebidos += y;   
            if(y > w) {
                times[x-1].pontos += 2;
                times[z-1].pontos += 1;
            } else {
                times[x-1].pontos += 1;
                times[z-1].pontos += 2;
            }
        }
        
        for(int i=0; i<num_times; i++) {
            if(times[i].pts_recebidos == 0) {
                times[i].avg = times[i].pts_marcados;
            } else {
                times[i].avg = (double)(times[i].pts_marcados) / (times[i].pts_recebidos);
            }
        }

        vector<Time> vetor_aux(num_times+1, time_vazio);
        merge_sort(times, 0, num_times-1, vetor_aux);

        if(instancias > 1) {
            cout << '\n';
        }
        cout << "Instancia " << instancias << '\n';
        for(int i=0; i<num_times; i++) {
            cout << times[i].id;
            if(i <num_times-1) {
                cout << ' ';
            } 
        }
        cout << '\n';

        instancias++;
    }
    
    return 0;
}