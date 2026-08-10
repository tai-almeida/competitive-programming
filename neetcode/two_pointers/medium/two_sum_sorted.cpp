#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int numbers_len = numbers.size();
        vector<int> indices(2, 0);
        

        int left = 0, right = numbers_len - 1;
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            if(sum == target) {
                indices[0] = left + 1;
                indices[1] = right + 1;
                return indices;
            } else if(sum > target) {
                right--;
            } else {
                left++;
            }
        }
        return indices;

        // // brute force
        // vector<int> indices(2, 0);
        // int counter = 0;
        // for(int i = 0; i<numbers_len-1; i++) {
        //     for(int j=i+1; j<numbers_len; j++) {
        //         if(numbers[i] + numbers[j] == target) {
        //             indices[0] = i + 1;
        //             indices[1] = j + 1;
        //             return indices;
        //         }
        //     }
        // }
        // return indices;
    }
};

int main() {
    Solution s = Solution();
    vector<int> numbers = {1, 9, 13, 14};
    int target = 23;

    vector<int> res = s.twoSum(numbers, target);

    cout << res[0] << ' ' << res[1] << endl;
}