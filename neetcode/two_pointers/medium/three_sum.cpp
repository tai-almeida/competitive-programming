#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        vector<vector<int>> triplets;
        sort(sorted_nums.begin(), sorted_nums.end());
        int nums_len = nums.size();
        set<vector<int>> added_triplets;
        
        for(int i=0; i<nums_len; i++) {
            int left = i + 1, right = nums_len-1;
            while(left < right) {
                int sum = sorted_nums[i] + sorted_nums[left] + sorted_nums[right];
                if(sum == 0) {
                    if(!added_triplets.count({sorted_nums[i], sorted_nums[left], sorted_nums[right]})) {
                        added_triplets.insert({sorted_nums[i], sorted_nums[left], sorted_nums[right]});
                        triplets.push_back({sorted_nums[i], sorted_nums[left], sorted_nums[right]});
                    }
                    left++;
                    // break;
                } else if(sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return triplets;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {-2,0,1,1,2};
    vector<vector<int>> triplets = s.threeSum(nums);

    for(vector<int> triplet : triplets) {
        for(int idx : triplet) {
            cout << idx << " ";
        }
        cout << endl;
    }
}