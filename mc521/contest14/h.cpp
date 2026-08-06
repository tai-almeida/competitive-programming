#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<vector<double>> cups_matrix(n, vector<double>(n, 0));
    cups_matrix[0][0] = t;
    double excess_cups;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(cups_matrix[i][j] > 1.0) {
                excess_cups = cups_matrix[i][j] - 1;
                cups_matrix[i][j] = 1;

                if(i+1 < n) {
                    cups_matrix[i+1][j] += excess_cups / 2;
                    cups_matrix[i+1][j+1] += excess_cups / 2;
                }
                
            }

            
        }
    }

    int cups = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if (cups_matrix[i][j] >= 1.0)
                cups++;
        }   
    }

    cout << cups << endl;
            
}