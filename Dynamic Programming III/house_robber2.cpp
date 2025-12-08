class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        int n=nums.size();
        vector<int>dp (n+2,-1);
        dp[n]=0;
        dp[n-1]=dp[nums.size()-1];
        for(int i=n-1;i>=1;i--){
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        vector<int>dp2 (n+1,-1);
        dp2[n]=0;
        dp2[n-1]=dp[nums.size()-1];
        for(int i=n-2;i>=0;i--){
            dp2[i]=max(nums[i]+dp2[i+2],dp2[i+1]);
        }
        return max(dp[0],dp2[0]);
    }
};
