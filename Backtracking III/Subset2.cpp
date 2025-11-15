#include <bits/stdc++.h>
using namespace std;

class Subsets2 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> list;
        vector<int> current;
        find(nums, 0, current, list);
        return list;
    }

    void find(vector<int>& arr, int index, vector<int>& current, vector<vector<int>>& list) {
        list.push_back(current);

        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1]) {
                continue;
            }
            current.push_back(arr[i]);
            find(arr, i + 1, current, list);
            current.pop_back();
        }
    }
};
