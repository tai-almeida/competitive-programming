#include <bits/stdc++.h>

using namespace std;

int main() {
    string sequence;
    cin >> sequence;

    if(sequence[0] == '1') {
        cout << "No" << '\n';
        return 0;
    }

    vector<char> columns(7);
    columns[0] = sequence[6];
    columns[1] = sequence[3];
    if (sequence[7] == sequence[1]) {
        columns[2] = sequence[7];
    } else {
        columns[2] = '1';
    }
    columns[3] = sequence[4];
    
    if (sequence[8] == sequence[2]) {
        columns[4] = sequence[2];
    } else {
        columns[4] = '1';
    }
    columns[5]  = sequence[5];
    columns[6] = sequence[9];

    for(int i = 0; i < 7; i++) {
        for(int j = i + 2; j < 7; j++) {
            if(columns[i] == '1' && columns[j] == '1') {
                for(int k = i + 1; k < j; k++) {
                    if(columns[k] == '0') {
                        cout << "Yes\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No" << '\n';
    
    return 0;

}