#include <bits/stdc++.h>

using namespace std;

bool is_wildcard_anagram(string first_line, string second_line) {
    int counter = 0; // contar asteriscos

    if(first_line.length() != second_line.length()) {
        return false;
    }

    unordered_map<char, int> char_table;
    for(int i=0; i<first_line.length(); i++) {
        char_table[first_line[i]]++;
    }

    for(int i=0; i<second_line.length(); i++) {
        if(second_line[i] == '*') {
            counter++;
        } else if(char_table[second_line[i]]) {
            char_table[second_line[i]]--;
        }  else {
            return false;
        }
    }

    // if(counter == 0) {
    //     return false;
    // }
    int non_zeros = 0;
    for(auto it = char_table.begin(); it != char_table.end(); it++) {
        if(it->second != 0) {
            non_zeros += it->second;
        }
    }
    // cout << non_zeros;

    if(counter == non_zeros) {
        return true;
    }

    return false;
}

int main() {
    string first_line;
    cin >> first_line;

    string second_line;
    cin >> second_line;

    if(is_wildcard_anagram(first_line, second_line)) {
        cout << "A\n";
    } else {
        cout << "N\n";
    }
    return 0;
}