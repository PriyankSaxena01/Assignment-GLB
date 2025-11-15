#include <bits/stdc++.h>
using namespace std;

class Combination {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> p;
        find(n, k, p, ans, 1);
        return ans;
    }

    void find(int n, int k, vector<int>& p, vector<vector<int>>& ans, int start) {
        if (start > n + 1) {
            return;
        }
        if (p.size() == k) {
            ans.push_back(p);
            return;
        }

        for (int i = start; i <= n; i++) {
            p.push_back(i);
            find(n, k, p, ans, i + 1);
            p.pop_back();
        }
    }
};
