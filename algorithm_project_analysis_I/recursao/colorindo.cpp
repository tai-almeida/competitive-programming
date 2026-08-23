#include <bits/stdc++.h>

using namespace std;

int colorindo(vector<vector<int>>& matriz, int i, int j, int linhas, int colunas) {
    // casos de parada (saiu ou ja preencheu tudo)
    if(i < 0 || i>= linhas || j < 0 || j >= colunas || matriz[i][j] == 1) {
        return 0;
    } 

    int num_coloridos = 1; // considera ja o que a crianca comeca
    for(int vizinhos_i = -1; vizinhos_i <=1; vizinhos_i++) {
        for (int vizinhos_j = -1; vizinhos_j <= 1; vizinhos_j++) {
            if (vizinhos_i == 0 && vizinhos_j ==0) {
                continue;
            } else {
                matriz[i][j] = 1;
                num_coloridos += colorindo(matriz, i+vizinhos_i, j+vizinhos_j, linhas, colunas);
            }
        }
    }

    return num_coloridos;
}


int main()  {
    int linhas, colunas, k, posicao_i, posicao_j;
    cin >> linhas >> colunas >> posicao_i >> posicao_j >> k;

    int quadrados_i, quadrados_j;
    vector<vector<int>> matriz(linhas, vector<int>(colunas, 0));
    for(int i = 0; i< k; i++) {
        cin >> quadrados_i >> quadrados_j;
        matriz[quadrados_i-1][quadrados_j-1] = 1;
    }


    cout << colorindo(matriz, posicao_i-1, posicao_j-1, linhas, colunas) << '\n';
    
    return 0;
}
