class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i+1;j<matrix[0].size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }


        for(int i=0;i<matrix.size();i++)
        {
            int f=0;
            int l=matrix[0].size()-1;
            while(f<=l)
            {
                int temp=matrix[i][f];
                matrix[i][f]=matrix[i][l];
                matrix[i][l]=temp;
                f++;
                l--;
            }
        }

    }
};
