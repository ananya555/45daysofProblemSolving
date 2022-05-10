// Problem Link
// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,-1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(i>=x)dp[i]=max(dp[i],dp[i-x]);
            if(i>=y)dp[i]=max(dp[i],dp[i-y]);
            if(i>=z)dp[i]=max(dp[i],dp[i-z]);
            if(dp[i]!=-1)dp[i]++;
        }
        return max(dp[n],0);
    }
};