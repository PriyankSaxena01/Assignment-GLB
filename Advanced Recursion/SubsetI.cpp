#include <bits/stdc++.h>
using namespace std;

class SubsetI {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> current;
        find(nums, 0, current, list);
        return list;
    }

    void find(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& list) {
        if (index == nums.size()) {
            list.push_back(current);
            return;
        }
        find(nums, index + 1, current, list);
        current.push_back(nums[index]);
        find(nums, index + 1, current, list);
        current.pop_back();
    }
};
