#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2*nums.size());
        if(nums.empty()) {
            return {};
        }

        for(int i=0; i<nums.size(); i++) {
            ans[i] = nums[i];
            ans[i+nums.size()] = nums[i];
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};

    vector<int> ans = solution.getConcatenation(nums);

    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

// tempo: O(n)
// espaço: O(n)