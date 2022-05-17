// Problem Link
// https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    // Optimized Approach
    
    void setZeroes(vector<vector<int>>& matrix) {
        bool isCol=false;
        int r=matrix.size();
        int c=matrix[0].size();
        
        for(int i=0;i<r;i++)
        {
            if(matrix[i][0]==0)
                isCol=true;
            
            for(int j=1;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        // Iterate over the array once again and using the first row and first column, update the elements.
    for (int i = 1; i < r; i++) {
      for (int j = 1; j < c; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    // See if the first row needs to be set to zero as well
    if (matrix[0][0] == 0) {
      for (int j = 0; j < c; j++) {
        matrix[0][j] = 0;
      }
    }
        if (isCol) {
      for (int i = 0; i < r; i++) {
        matrix[i][0] = 0;
      }
    }
    }
};
