#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> higher_temps_idxs;
        higher_temps_idxs.push(0);

        int len = temperatures.size();
        vector<int> daily_temps(len, 0);

        for(int i = 1; i<len; i++) {
            if(!higher_temps_idxs.empty() && temperatures[i] <= temperatures[higher_temps_idxs.top()]) {
                higher_temps_idxs.push(i);
            } else if(!higher_temps_idxs.empty() && temperatures[i] > temperatures[higher_temps_idxs.top()]) {
                while(!higher_temps_idxs.empty() && temperatures[i] > temperatures[higher_temps_idxs.top()]) {
                    int idx = higher_temps_idxs.top();
                    daily_temps[idx] = i - idx;
                    higher_temps_idxs.pop();
                }
                higher_temps_idxs.push(i);
            } else {
                higher_temps_idxs.push(i);
            }
            
        }
        return daily_temps;
    }
};

int main() {
    vector<int> temperatures = {30,38,30,36,35,40,28};
    Solution s = Solution();
    vector<int> res = s.dailyTemperatures(temperatures);

    for(int days : res) {
        cout << days << " ";
    }
    cout << endl;
}