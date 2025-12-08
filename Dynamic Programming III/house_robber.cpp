class Solution {
public:
    int check(vector<int>&nums,vector<int> & dp,int n,int index){
        if(index<0)
        return 0;
        if(dp[index]!=-1)
        return dp[index];
        dp[index]=max(nums[index]+check(nums,dp,n,index-2),check(nums,dp,n,index-1));
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return check(nums,dp,n,n-1);
    }
};
