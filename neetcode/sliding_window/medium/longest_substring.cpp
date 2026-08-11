#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int len = s.size(), max_len = 0, left=0, right = 1, curr_len = 0;
        if(s[0]) {
            seen.insert(s[0]);
            curr_len++;
            max_len = 1;
        }
        while(left <= right  && right < len) {
            if(!seen.count(s[right])) {
                seen.insert(s[right]);
                right++;
                curr_len++;
            } else {
                seen.erase(s[left]);
                left++;
                curr_len--;
            }
            if(curr_len > max_len) {
                max_len = curr_len;
            }
        }
        return max_len;
    }
};

int main() {
    Solution solution = Solution();
    string s = "cdd";
    cout << solution.lengthOfLongestSubstring(s) << endl;
}