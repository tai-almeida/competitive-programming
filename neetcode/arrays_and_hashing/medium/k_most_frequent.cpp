#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> frequency;
        for(int num : nums) {
            frequency[num]++;
        }

        vector<int> k_most_frequent(k, 0);
        for(int i=0; i<k; i++) {
            int most_frequent = 0;
            int max_frequency = 0;
            for( auto& element : frequency) {
                if(element.second > max_frequency) {
                    max_frequency = element.second;
                    most_frequent = element.first;
                }
            }
            k_most_frequent[i] = most_frequent;
            frequency[most_frequent] = 0;
        }
        return k_most_frequent;

    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> res = s.topKFrequent(nums, k);

    for(int i=0; i<k; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}