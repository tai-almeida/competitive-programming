#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int j=1;
            
            // retorna 0 se vetor vazio
            if (nums.size() == 0) {
                return 0; 
            }
        
            //percorre nums e substitui repetidos pelos valores unicos
            for (int i=1; i<nums.size(); i++) { 
                if(nums[i] != nums[i-1]) {
                    nums[j] = nums[i];
                    j++;
                }
            }

            // retorna numero de valores unicos
            return j;
        }
};

// tempo: O(n)
// espaço: O(1)
