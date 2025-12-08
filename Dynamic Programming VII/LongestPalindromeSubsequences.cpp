class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int value=0;
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        int m=text1.size();
        int n=text2.size();
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++)
            {
                if(text1[i-1]==text2[j-1]){
                    
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(s,s2);
    }
};
