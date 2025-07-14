#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int valor) {
            int counter = 0;

            for (int i=0; i<nums.size(); i++) {
                if(nums[i] != valor) {
                    nums[counter] = nums[i];
                    counter++;
                }
            }
            return counter;
        }
};

// tempo: O(n)
// espaço: O(1)

