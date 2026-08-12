#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public: 
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> count_s1;
        for(char c : s1) {
            count_s1[c]++;
        }

        int left = 0;
        unordered_map<char, int> count_s2;
        
        for(int right=0; right<s2.size(); right++) {

            count_s2[s2[right]]++;

            if((right - left + 1) > s1.size()) {
                count_s2[s2[left]]--;
                if(count_s2[s2[left]] == 0) {
                    count_s2.erase(s2[left]);
                }
                left++;
            }  

            if((right - left + 1) == s1.size()) {
                if(count_s1 == count_s2) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s = Solution();
    string s1 = "ab";
    string s2 = "lecabee";

    cout << s.checkInclusion(s1, s2) << endl;
}