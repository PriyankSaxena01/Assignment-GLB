#include <bits/stdc++.h>
using namespace std;

class MinPathSum {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return find(grid, 0, 0, memo);
    }

    int find(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& memo) {
        if (row == grid.size() - 1 && col == grid[0].size() - 1)
            return grid[row][col];
        if (memo[row][col] != -1)
            return grid[row][col] + memo[row][col];

        int down = INT_MAX, right = INT_MAX;
        if (row < grid.size() - 1)
            down = find(grid, row + 1, col, memo);
        if (col < grid[0].size() - 1)
            right = find(grid, row, col + 1, memo);

        memo[row][col] = min(down, right);
        return grid[row][col] + memo[row][col];
    }
};

int main() {
}
