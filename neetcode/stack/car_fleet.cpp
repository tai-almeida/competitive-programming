#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int len = position.size();
        vector<pair<int, int>> pos_and_speed;
        for(int i=0; i<len; i++) {
            pos_and_speed.push_back({position[i], speed[i]});
        }
        sort(pos_and_speed.rbegin(), pos_and_speed.rend());

        stack<float> fleets_times;
        int fleets = 0;
        for(int i=0; i < len; i++) {
            float time = (float)(target - pos_and_speed[i].first) / pos_and_speed[i].second;
            if(fleets_times.empty()) {
                fleets_times.push(time);
                fleets++;
            } else if(time > fleets_times.top()) {
                fleets++;
                fleets_times.push(time);
                continue;
            } else {
                continue;
                
            }

        }
        return fleets;
    }
};

int main() {
    int target = 10;
    vector<int> position = {4,1,0,7}, speed = {2,2,1,1};
    Solution s = Solution();

    cout << s.carFleet(target, position, speed) << endl;
}