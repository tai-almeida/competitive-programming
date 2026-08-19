#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bottom = matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;
        int search_row = 0;
        while(top <= bottom) {
            int mid = (top + bottom)/2;
            if(matrix[mid][left] == target || matrix[mid][right] == target) {
                return true;
            } else if(matrix[mid][left] <= target && matrix[mid][right] >= target) {
                search_row = mid;
                break;
            } else if(matrix[mid][right] < target) {
                top = mid + 1;
            } else if(matrix[mid][left] > target) {
                bottom = mid - 1;
            } else {
                return false;
            }
        }

        while(left <= right) {
            int mid = (left + right)/2;
            if(matrix[search_row][mid] == target) {
                return true;
            } else if(matrix[search_row][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;

    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> matrix = {{1,2,4,8},{10,11,12,13},{14,20,30,40}};
    int target = 10;

    cout << s.searchMatrix(matrix, target) << endl;
}