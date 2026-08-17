#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<pair<int, int>> copy;
        int idx = 0;
        for(int num : nums) {
            copy.push_back({num, idx});
            idx++;
        }
        sort(copy.begin(), copy.end());
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (right + left)/2;
            if(copy[mid].first == target) {
                return copy[mid].second;
            } else if(copy[mid].first < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return -1;
        
    }
};

int main() {
    vector<int> nums = {-1,0,2,4,6,8};
    int target = 3;
    Solution s = Solution();

    cout << s.search(nums, target) << endl;
}