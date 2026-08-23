#include <bits/stdc++.h>

using namespace std;

int fib(int n, int &num_calls) {

    num_calls++;
    if(n == 1) {
        return 1;
    } else if(n == 0) {
        return 0;
    } 
        int resultado = 0;
        resultado += fib(n-1, num_calls);
        resultado += fib(n-2, num_calls);
        return resultado;
 
}

int main() {
    int casos;
    cin >> casos;

    vector<int> num_fib(casos, 0);
    for(int i=0; i<casos; i++) {
        cin >> num_fib[i];
    }
    
    for(int i=0; i<casos; i++) {
        int num_calls = -1;
        int resultado = fib(num_fib[i], num_calls);
        cout << "fib(" << num_fib[i] << ") = " << num_calls << " calls = " << resultado << '\n';
    }
    return 0;
}