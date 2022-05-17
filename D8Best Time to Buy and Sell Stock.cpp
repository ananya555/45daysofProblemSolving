// Problem Link
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    // Brute Force Approach
    int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
        int maxProfit = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            }
        }
        return maxProfit < 0 ? 0 : maxProfit;
    }
    
    
    // Using DP with Using Extra Space
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)
            return 0;
        int n=prices.size();
        int dp[n+1];
        int mi=prices[0];
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            dp[i]=max(dp[i-1],prices[i]-mi);
            mi=min(mi,prices[i]);
        }
        return dp[n-1];
    }
    
    // Optimal One
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int minSoFar = prices[0];
          int maxi = INT_MIN;
        
        for(int i=1; i<n; i++){
            if(prices[i-1] < minSoFar){
                minSoFar = prices[i-1];
            }
            if(prices[i] - minSoFar > maxi){
                maxi = prices[i] - minSoFar;
            }
        }
        if(maxi<0) return 0;
        return maxi;
    }
};
