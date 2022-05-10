// Problem Link
// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int i = 0, j = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return fun(m,n,i,j,dp);
    }
    int fun(int m, int n, int i, int j, vector<vector<int>> &dp) {
        if (i > m -1 || j > n - 1) return 0;
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        // DP
        if (dp[i][j] != -1) return dp[i][j];
        // Right
        int right = fun(m, n, i, j+1, dp);
        // Down
        int down = fun(m, n, i+1, j, dp);
        return dp[i][j] = (down + right);
    }
};
