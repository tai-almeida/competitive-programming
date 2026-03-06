#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, x;
    
    do {
        cin >> n >> x;
        if(n == 0 && x == 0) {
            return 0;
        }
            

        int counter = 0;
        for(int a = 1; a <= n; a++) {
            for(int b = a+1; b <= n; b++) {
                for(int c = b+1; c <= n; c++) {
                    if(a + b + c == x) {
                        counter++;
                    }
                }
            }
        }

        cout << counter << '\n';
    } while(n != 0 || x != 0);

    return 0;
}