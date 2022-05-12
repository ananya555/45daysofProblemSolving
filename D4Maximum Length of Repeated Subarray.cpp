// Problem Link
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
class Solution {
public:
    
    int findLength(vector<int>& t1, vector<int>& t2) { 
     vector<vector<int>>dp(t1.size()+2,vector<int>(t2.size()+2));
        // tabulation
        for(int i=0;i<=t2.size();i++)
            dp[0][i]=0;
         for(int i=0;i<=t1.size();i++)
            dp[i][0]=0;
        for(int i=1;i<=t1.size();i++)
            for(int j=1;j<=t2.size();j++)
            {
                
                 if(t1[i-1]==t2[j-1])
                      dp[i][j]=1+dp[i-1][j-1];
                 else
                      dp[i][j]=0;
            }
        int ans=-1;
        for(int i=0;i<dp.size();i++)
            for(int j=0;j<dp[0].size();j++)
            {
                if(dp[i][j]>ans)
                    ans=dp[i][j];
            }
        return ans;
    }
};
