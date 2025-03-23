#include <iostream>
using namespace std;

int main() {
    int x = 0, numero_ops;
    string operation;
    cin>>numero_ops;
    for(int i=0; i<numero_ops; i++) {
        cin>>operation;
        if(operation=="X++" || operation=="++X") {
            x++;
        } else {
            x--;
        }
    }
    cout<<x;
    return 0;
}