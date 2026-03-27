#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;
    float res;
    bool remove = true;
    while(remove == true) {
        if(b*c >= a) {
            res = (double)a / b;
            cout << fixed << setprecision(15) << res;
            remove = false;
        } else {
            a--;
        }
    }
    
    return 0;
}