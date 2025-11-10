class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n1,n2;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                n1=i;
                n2=j;
                break;
                }
            }
        }
        return {n1,n2};
    }
};
