class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;

        for(int i=0;i<n;i++)
        sum=sum+nums[i]; // total sum

        int left=0;

        for(int i=0;i<n;i++)
        {
            if(left==sum-left-nums[i])
            return i; // found pivot

            left=left+nums[i]; // update left sum
        }

        return -1; // pivot not found
    }
};
