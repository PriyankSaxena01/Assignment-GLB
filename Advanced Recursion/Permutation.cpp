#include <bits/stdc++.h>
using namespace std;

class Permutation {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> p;
        find(nums, list, p, 0);
        return list;
    }

    void find(vector<int>& nums, vector<vector<int>>& list, vector<int>& p, int index) {
        if (index == nums.size()) {
            list.push_back(p);
            return;
        }
        int val = nums[index];
        for (int i = 0; i <= p.size(); i++) {
            p.insert(p.begin() + i, val);
            find(nums, list, p, index + 1);
            p.erase(p.begin() + i);
        }
    }
};
