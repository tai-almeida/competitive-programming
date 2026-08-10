#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = 0;
        len = s.size();

        int left = 0, right = len - 1;

        while(left < right) {
            if(!((s[left] >= 'A' && s[left] <= 'Z') || (s[left] >= 'a' && s[left] <= 'z') || (s[left] >= '0' && s[left] <= '9'))) {
                left++;
                continue;
            }
            if(!((s[right] >= 'A' && s[right] <= 'Z') ||  (s[right] >= 'a' && s[right] <= 'z') || (s[right] >= '0' && s[right] <= '9'))) {
                right--;
                continue;
            }
            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution solution = Solution();
    string s = "No lemon, no melon";

    cout << solution.isPalindrome(s) << endl;
}