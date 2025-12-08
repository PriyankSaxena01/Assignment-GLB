class Solution {
    int check(string& text1,string& text2,int index1,int index2,int& value,vector<vector<int>>& dp){
        
        if(index1<0 || index2<0){
            return 0;
        }

        if(dp[index1][index2]!=-1)
        return dp[index1][index2];

        if(text1[index1]==text2[index2]){
            dp[index1][index2]=1+check(text1,text2,index1-1,index2-1,value,dp);
        }

        else{
        int op1=check(text1,text2,index1-1,index2,value,dp);
        int op2=check(text1,text2,index1,index2-1,value,dp);
        dp[index1][index2]=max(op1,op2);
        }
        value=max(value,dp[index1][index2]);
        return dp[index1][index2];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int value=0;
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        check(text1,text2,text1.size()-1,text2.size()-1,value,dp);
        return value;
    }
};
