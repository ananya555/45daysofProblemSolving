// Problem Link
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    // Brute Force Approach
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
        int maxProfit=0;
        int sum=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n && prices[j]>prices[i]; j++){
                sum += prices[j]-prices[i];
                if(sum>maxProfit)
                    maxProfit = sum;
                break;
            }
        }
        return maxProfit;
    }
    
    // Valley-Peak Approach
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit=0;
        int valley = prices[0]; //Initialize valley
        int peak = prices[0];  //Initialize peak
        int i=0;
        while(i < n-1){
            //To find earliest valley
            while(i<n-1 && prices[i]>=prices[i+1])
                i++;
            valley = prices[i];
            
            //To find farthest peak
            while(i<n-1 && prices[i]<=prices[i+1])
                i++;
            peak = prices[i];
            maxProfit += peak - valley;            
        }
				return maxProfit;
        
    }
    
    // Greedy Approach
    int maxProfit(vector<int>& prices) {
    int max_profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1])
            max_profit += prices[i] - prices[i - 1];
    }
    return max_profit;
}
};
