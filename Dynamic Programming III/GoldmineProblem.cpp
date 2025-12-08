#include <bits/stdc++.h>
using namespace std;

class GoldMineProblem {
public:
    int m, n;
    int gr[3][2] = {{1,1}, {0,1}, {-1,1}};

    int maxGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans = max(ans, find(grid, i, 0, memo));
        }
        return ans;
    }

    int find(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& memo) {
        if (row < 0 || row >= m || col < 0 || col >= n) return 0;
        if (memo[row][col] != -1) return grid[row][col] + memo[row][col];
        int maxGold = 0;
        for (auto& d : gr) {
            int r = row + d[0];
            int c = col + d[1];
            maxGold = max(maxGold, find(grid, r, c, memo));
        }
        memo[row][col] = maxGold;
        return grid[row][col] + memo[row][col];
    }
};

int main() {
}
