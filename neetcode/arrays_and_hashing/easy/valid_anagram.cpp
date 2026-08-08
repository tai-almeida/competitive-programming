#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> chars_in_original;
        for(char x : s) {
            chars_in_original[x]++;
        }
        for(char x : t) {
            if(chars_in_original[x]) {
                chars_in_original[x]--;
            } else {
                return false;
            }
        }

        for(const auto& element : chars_in_original) {
            if(element.second != 0) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution solution = Solution();
    string s = "xx";
    string t = "x";
    cout << solution.isAnagram(s, t) << endl;
}