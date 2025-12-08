#include <bits/stdc++.h>
using namespace std;

class UniquePaths {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return find(m, n, 0, 0, dp);
    }

    int find(int maxRow, int maxCol, int row, int col, vector<vector<int>>& dp) {
        if (row == maxRow - 1 && col == maxCol - 1)
            return 1;
        if (row >= maxRow || col >= maxCol)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];

        int count = 0;
        count += find(maxRow, maxCol, row + 1, col, dp);
        count += find(maxRow, maxCol, row, col + 1, dp);

        return dp[row][col] = count;
    }
};

int main() {
}
