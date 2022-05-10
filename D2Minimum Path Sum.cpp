// Problem Link
// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
     // 1st Approach ==>RECURSION (gives TLE because of overlapping of sub-problems)
    int helper(vector<vector<int>>& grid,int i,int j)
    {
        if(i>=grid.size() || j>=grid[0].size())
            return 1e9;
        
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return grid[i][j];
        
        int   right=grid[i][j]+helper(grid,i,j+1);
        int down=grid[i][j]+helper(grid,i+1,j);
        
        return min(right,down);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        return helper(grid,0,0);
    }
    
    // 2nd Approach ==>MEMOIZATION 
    int helper(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=grid.size() || j>=grid[0].size())
            return 1e9;
        
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return grid[i][j];
        
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        
        int   right=grid[i][j]+helper(grid,i,j+1,dp);
        int down=grid[i][j]+helper(grid,i+1,j,dp);
        
        return dp[i][j]= min(right,down);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        return helper(grid,0,0,dp);
    }
    
    // 3rd Approach ==>DP
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=grid[0][0];
                else
                {
                    if(i == 0)
                        dp[i][j] = grid[i][j] + dp[i][j-1];
                    else if(j == 0)
                        dp[i][j] = grid[i][j] + dp[i-1][j];
                    else
                        dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
