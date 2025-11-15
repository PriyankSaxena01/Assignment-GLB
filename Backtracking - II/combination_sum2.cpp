#include <bits/stdc++.h>
using namespace std;

class CombinationSumII {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> list;
        sort(candidates.begin(), candidates.end());
        find(candidates, target, 0, vector<int>(), list);
        return list;
    }

    void find(vector<int>& candidates, int target, int start, vector<int> p, vector<vector<int>>& list) {
        if (target == 0) {
            list.push_back(p);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            p.push_back(candidates[i]);
            find(candidates, target - candidates[i], i + 1, p, list);
            p.pop_back();
        }
    }
};
