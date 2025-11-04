class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==1)
        {
            for(int i=0;i<matrix[0].size();i++)
            if(matrix[0][i]==target)
            return true;
        }
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][0]>target)
            {
                int k=0;
                if(i==0)
                k=0;
                else
                k=i-1;
                
                for(int j=0;j<matrix[i].size();j++)
                {
                    if(matrix[k][j]==target)
                    return true;
                }
            }
            if(i==matrix.size()-1)
            {
                for(int j=0;j<matrix[i].size();j++)
                {
                    if(matrix[i][j]==target)
                return true;
                }
            }
            
        }
        return false;
    }
};