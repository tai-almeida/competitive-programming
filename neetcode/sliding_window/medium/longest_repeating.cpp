#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> frequency_chars;
        int max_frequency = 0;   
        int max_len = 0;

        int left = 0, right = 0;
        while(right < s.size()) {
            frequency_chars[s[right]]++;
            max_frequency = max(max_frequency, frequency_chars[s[right]]);
            int replacements = (right - left + 1) - max_frequency;
            if(replacements > k) {
                frequency_chars[s[left]]--;
                left++;
            } 
            if((right - left + 1) > max_len) {
                max_len = (right - left + 1);
            }

            right++;
            
        }
        return max_len;
    }
};

int main() {
    Solution solution = Solution();
    string s = "AAABABB";
    int k = 1;
    cout << solution.characterReplacement(s, k) << endl;
}