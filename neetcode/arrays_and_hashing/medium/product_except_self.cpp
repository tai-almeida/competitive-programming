#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int len = 0;
        for(int x : nums) {
            len++;
        }
        vector<int> prefix(len, 1), sufix(len, 1);
        for(int i=1; i<len; i++) {
            prefix[i] = nums[i-1] * prefix[i-1];
        }

        for(int i = len-2; i>=0; i--) {
            sufix[i] *= nums[i+1] * sufix[i+1];
        }

        vector<int> products(len, 0);
        for(int i=0; i<len; i++) {
            products[i] = (prefix[i] * sufix[i]);
        }

        return products;
    }
};

int main() {
    vector<int> nums = {1, 2, 4, 6};
    Solution s = Solution();
    vector<int> products = s.productExceptSelf(nums);

    for(int x : products) {
        cout << x <<  " ";
    }
    cout << endl;

}