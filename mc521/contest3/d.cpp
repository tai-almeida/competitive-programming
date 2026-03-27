#include <bits/stdc++.h>

using namespace std;

int main() {

    string seq;
    set<string> set_sub;
    string sub;

    cin >> seq;

    int longest = 0;
    int len = seq.size();
    for(int i = 0; i<len; i++) {
        for(int j=0; j + i <= len; j++) {
            sub = seq.substr(j, i);

            // se ja ta no set, eh pq eh uma substr repetida
            if(set_sub.count(sub)) {
                longest = i;
                break;
            }

            // se n insere no set
            set_sub.insert(sub);
        }
    }
    
    cout << longest << '\n';
    return 0;
}