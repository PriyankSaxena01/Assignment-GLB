#include <bits/stdc++.h>
using namespace std;

class EggDropping {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return find(k, n, dp);
    }

    int find(int k, int n, vector<vector<int>>& dp) {
        if (n == 0 || n == 1 || k == 1)
            return n;

        int count = INT_MAX;
        int low = 1, high = n;

        while (low <= high) {
            int mid = (low + high) / 2;

            int breakCase, surviveCase;

            if (dp[k - 1][mid - 1] != -1)
                breakCase = dp[k - 1][mid - 1];
            else {
                breakCase = find(k - 1, mid - 1, dp);
                dp[k - 1][mid - 1] = breakCase;
            }

            if (dp[k][n - mid] != -1)
                surviveCase = dp[k][n - mid];
            else {
                surviveCase = find(k, n - mid, dp);
                dp[k][n - mid] = surviveCase;
            }

            int worst = 1 + max(breakCase, surviveCase);
            count = min(count, worst);

            if (breakCase > surviveCase)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return dp[k][n] = count;
    }
};

int main() {
}
