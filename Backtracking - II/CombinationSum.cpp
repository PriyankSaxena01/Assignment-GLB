#include <bits/stdc++.h>
using namespace std;

class CombinationSum {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> p;
        sort(candidates.begin(), candidates.end());
        return letter(candidates, p, target, 0);
    }

    vector<vector<int>> letter(vector<int>& arr, vector<int>& p, int target, int start) {
        if (target == 0) {
            vector<vector<int>> list;
            list.push_back(p);
            return list;
        }

        if (target < 0) {
            return {};
        }

        vector<vector<int>> list;
        for (int i = start; i < arr.size(); i++) {
            p.push_back(arr[i]);
            vector<vector<int>> t = letter(arr, p, target - arr[i], i);
            list.insert(list.end(), t.begin(), t.end());
            p.pop_back();
        }
        return list;
    }
};
