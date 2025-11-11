class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> col;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(int i=0;i<row.size();i++)
        {
            int index=row[i];
            for(int j=0;j<matrix[0].size();j++){
                matrix[index][j]=0;
            }
        }
        for(int i=0;i<col.size();i++)
        {
            int index=col[i];
            for(int j=0;j<matrix.size();j++){
                matrix[j][index]=0;
            }
        }
    }
};
