// Problem Link
// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#

int dp[1001][1001];
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        
        int ans=0;
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0)
                dp[i][j]=0;
                else if(j==0)
                dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else
                dp[i][j]=0;
            }
        }
        return ans;
    }
