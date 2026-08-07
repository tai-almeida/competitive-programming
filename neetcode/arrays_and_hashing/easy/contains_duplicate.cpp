#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums){
        unordered_set<int> seen;
        for(int x : nums) {
            if(seen.count(x)) {
                return true;
            } else {
                seen.insert(x);
            }
        }
        return false;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {1, 2, 3, 3};
    cout << s.hasDuplicate(nums) << endl;
}

