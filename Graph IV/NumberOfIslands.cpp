#include <bits/stdc++.h>
using namespace std;

class NumberOfIslands {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int c = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    find(grid, i, j, visited);
                    c++;
                }
            }
        }
        return c;
    }

    void find(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& vis) {
        if(grid[row][col] == '0' || vis[row][col]){
            return;
        }
        vis[row][col] = true;

        if(row > 0){
            find(grid, row - 1, col, vis);
        }
        if(row < grid.size() - 1){
            find(grid, row + 1, col, vis);
        }
        if(col > 0){
            find(grid, row, col - 1, vis);
        }
        if(col < grid[0].size() - 1){
            find(grid, row, col + 1, vis);
        }
    }
};

int main() {
    
}
