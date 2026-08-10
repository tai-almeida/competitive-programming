#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int len = prices.size();
        int diff = 0;
        for(int i=0; i<len-1; i++) {
            //compro em prices[i]
            for(int j=i+1; j<len; j++) {
                diff = prices[j] - prices[i];
                if(diff > profit) {
                    profit = diff;
                }
            }
        }

        return profit;
    }
};

int main() {
    Solution s = Solution();
    vector<int> prices = {10,1,5,6,7,1};
    cout << s.maxProfit(prices) << endl;
}