class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startrow=0;
        int endrow=matrix.size();
        int startcol=0;
        int endcol=matrix[0].size();
        vector<int> ans;
        while(startrow<endrow && startcol<endcol)
        {
            for(int i=startcol;i<endcol;i++)
            {
                ans.push_back(matrix[startrow][i]);
            }
            startrow++;
            for(int i=startrow;i<endrow;i++)
            {
                ans.push_back(matrix[i][endcol-1]);
            }
            endcol--;
            if (!(startrow < endrow && startcol < endcol)) break;
            for(int i=endcol-1;i>=startcol;i--)
            {
                ans.push_back(matrix[endrow-1][i]);
            }
            endrow--;
            for(int i=endrow-1;i>=startrow;i--)
            {
                ans.push_back(matrix[i][startcol]);
            }
            startcol++;
        }

        return ans;
    }
};
