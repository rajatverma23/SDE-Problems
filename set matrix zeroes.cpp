class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col = 1;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int i, j;
        
        for(i = 0; i < n; i++)
        {
            if(matrix[i][0] == 0)
            {
                col = 0;
            }
            
            for(j = 1; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(i = n-1; i >= 0; i--)
        {
            for(j = m-1; j >= 1; j--)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
            
            if(col == 0)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
