#include <bits/stdc++.h>

using namespace std;

int percorre_grid(vector<vector<int>>& grid, int n) {
    // baixo, horizontal, diagonal principal ou contraria
    int offset_x[4] = {1, 0, 1, 1};
    int offset_y[4] = {0, 1, 1, -1};

    int num_consecutives = 0;

    for(int i =0; i< n; i++) {
        for(int j=0; j<n; j++) {

            if(grid[i][j] == 1) {
                
                for(int k = 0; k < 4; k++) {
                    int x = i, y = j, counter = 0;
                    
                    // ficar  nos limites da matriz enqt da
                    while((x >=0 && x< n) && (y>= 0 && y<n) && (grid[x][y] == 1)) {
                        x += offset_x[k];
                        y += offset_y[k];
                        counter++;
                    }

                    if(counter > num_consecutives) {
                        num_consecutives = counter;
                    }
                }
            }


        }
    }
    return num_consecutives;



}

int main() {
    int n; 
    
    while(cin >> n && n > 0) {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        for(int i=0; i<n; i++) {
            string row_i;
            cin >> row_i;
            for(int j=0; j<n; j++) {
                grid[i][j] = row_i[j] - '0';
            }
        }

        cout << percorre_grid(grid, n) << '\n';
        

    }


    return 0;

}