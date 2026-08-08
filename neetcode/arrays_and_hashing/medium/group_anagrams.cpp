#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string sorted;
        vector<vector<string>> anagrams = {};
        int index = 0;
        unordered_map<string, vector<string>> anagram_groups;
        for(string str_element : strs) {
            sorted = str_element;
            sort(sorted.begin(), sorted.end());

            anagram_groups[sorted].push_back(str_element);

        }

        for(const auto& group : anagram_groups) {
            anagrams.push_back(group.second);
        }

        return anagrams;
    }
};

int main() {
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    Solution s = Solution();
    vector<vector<string>> res = s.groupAnagrams(strs);

    for(vector<string> anagrams : res) {
        for(string anagram : anagrams) {
            cout << anagram << " ";
        }
        cout << endl;
    }
    
    

}