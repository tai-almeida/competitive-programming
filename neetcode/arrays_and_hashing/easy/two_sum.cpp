#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int nums_len = 0;
        vector<int> indexes = {0, 0};
        for (auto i : nums) {
            nums_len++;
        }
        
        for(int i=0; i < nums_len; i++) {
            for(int j=i+1; j<nums_len; j++) {
                if(nums[i] + nums[j] == target) {
                    indexes[0] = i;
                    indexes[1] = j;
                    return indexes;
                }
            }
        }
        return indexes;
    }
};

int main() {
    vector<int> nums = {4,5,6};
    int target = 10;
    Solution s = Solution();
    vector<int> res = s.twoSum(nums, target);
    cout << '[' << res[0] << ", "<< res[1] << ']' << endl;
}