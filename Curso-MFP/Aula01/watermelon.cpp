#include <iostream>
using namespace std;

int main() {
    int watermelon_weigth, res;

    cin>>watermelon_weigth;
    res = watermelon_weigth/2;
    if(watermelon_weigth>2 && watermelon_weigth%2 == 0) {
        int res2 = res%2;
        int soma = res + res2;
        int sub = res - res2;
        if((soma%2 == 0) && (sub%2==0) && (soma+sub==watermelon_weigth)) {
            cout<<"YES";
        } else {
            cout<<"NO";
        }
    } else {
        cout<<"NO";
    }
    
    return 0;
}