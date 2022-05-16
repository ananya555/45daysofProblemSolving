// Probelm Link
// https://leetcode.com/problems/maximal-square/

class Solution {
public:
    
//     Recursion + Memoization
    
    int dp[301][301];
    int helperMethod(int i,int j,vector<vector<char>>& matrix)
    {
        if(i<0 || j<0 || i>= matrix.size()|| j>=matrix[0].size()|| matrix[i][j] == '0')
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j] = 1+min( helperMethod(i+1,j,matrix),
                            min(helperMethod(i+1,j+1,matrix),helperMethod(i,j+1,matrix))) ;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans = INT_MIN;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    ans=max(ans,helperMethod(i,j,matrix));
                }
            }
        }
        return ans==INT_MIN?0:ans*ans;
    }
    
//     DP
    int maximalSquare(vector<vector<char>>& matrix)
    {
    int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0) && matrix[i][j]=='1'){
                    dp[i][j]=1;
                }
                else{
                    if(matrix[i][j]=='1'){
                        dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
    
    // DP with Improvement in Space Complexity
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m+1);

        int maxSqrLen = 0;
        for(int i=1; i<=n; i++) {
            int prev = dp[0];
            for(int j=1; j<=m; j++) {
                int temp = dp[j];
                if(matrix[i-1][j-1] == '1') {
                    
                    // new value
                    // dp[j] = dp[i-1][j]
                    // dp[j-1] = dp[i][j]
                    // prev = dp[i-1][j-1]
                    dp[j] = min(prev, min(dp[j], dp[j-1])) + 1;
                    maxSqrLen = max(maxSqrLen, dp[j]);
                }
                else {
                    dp[j] = 0;
                }

                // update prev for next column on the same row
                prev = temp;
            }
        }
        return maxSqrLen*maxSqrLen;
    }
};
