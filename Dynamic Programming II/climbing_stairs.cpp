class Solution {
public:
    int check(int stair,int n,vector<int>& dp){
        if(n<stair)
        return 0;
        if (dp[stair]!=-1)
        return dp[stair];
        else
        dp[stair]=check(stair+1,n,dp)+check(stair+2,n,dp);
        return dp[stair];
    }
    int climbStairs(int n) {
        if(n==0 || n==1)
        return 1;
        vector<int> dp(n+2,-1);
        dp[n]=1;
        dp[n+1]=0;
        dp[n-1]=1;
        dp[n-2]=2;
        for(int i=n-3;i>=0;i--){
            dp[i]=dp[i+1]+dp[i+2];
        }
        return dp[0];
    }
};  
