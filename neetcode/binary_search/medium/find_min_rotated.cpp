#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size()-1;
        int min = nums[right];

        while(left <= right) {
            int mid = (left+right)/2;

            if(nums[mid] < min) {
                min = nums[mid];
                right = mid-1;
            } else if(nums[mid] >= min) {
                left = mid+1;
            }
            else if(nums[left] > nums[right]) {
                left = mid+1;
            } 
        }
        return min;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {4, 5, 0, 1, 2, 3};

    cout << s.findMin(nums) << endl;
}
