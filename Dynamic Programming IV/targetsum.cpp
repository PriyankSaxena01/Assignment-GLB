class Solution {
public:
    int find(vector<int>& arr,int diff,int sum,int index,int range,vector<vector<int>>& dp){
    if(index == arr.size()){
       return (range - 2*sum == diff) ? 1 : 0;
    }
    if(sum>range)
    return 0;
    if(dp[index][sum]!=-1)
    return dp[index][sum];
    int take=find(arr,diff,sum+arr[index],index+1,range,dp);
    int nottake=find(arr,diff,sum,index+1,range,dp);
    
    return dp[index][sum]= take+nottake;
    
  }

    int findTargetSumWays(vector<int>& arr, int diff) {
        int range=0;
        for(int i=0;i<arr.size();i++){
            range+=arr[i];
        }
        vector<vector<int>> dp(arr.size()+1,vector<int>(range+1,-1));
        return find(arr,diff,0,0,range,dp);
    }
};
