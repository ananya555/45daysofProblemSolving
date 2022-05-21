// Problem Link
// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool helper(int inx, vector<int>& nums){
        if(inx >= nums.size()-1) return true;
     
        bool val = false;
        for(int i=1; i<=nums[inx]; i++){
            val = val || helper(inx + i, nums);
        }
        return val;
    }
    bool canJump(vector<int>& nums) {
        return helper(0, nums);
    }
};
// Time Complexity - O(K^N) where k is the max value in the array
// Space Complexity - O(N) - Recursive Stack Space

// Approach 2 : Recursion + Memoization
class Solution {
public:
    bool helper(int inx, vector<int>& nums, vector<int>& dp){
        if(inx >= nums.size()-1) return true;
        
        if(dp[inx] != -1) return dp[inx];
        bool val = false;
        for(int i=1; i<=nums[inx]; i++){
            val = val || helper(inx + i, nums, dp);
        }
        return dp[inx] = val;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, dp);
    }
};
// Time Complexity - O(K*N) where k is the max value in the array
// Space Complexity - O(N + N) - Recursive Stack Space + Memoization table

// Approach 3 : Tabulation
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[nums.size()-1] = 1;
        
        for(int inx = nums.size()-2; inx>=0; inx--){
            bool val = false;
            for(int i=1; i<=nums[inx]; i++){
               if(inx + i < nums.size()) val = val || dp[inx + i];
            }
            dp[inx] = val;
        }
        return dp[0];
    }
};
// Time Complexity - O(K*N) where k is the max value in the array
// Space Complexity - O(N) - Dp Table

// Approach 4 : Greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goalPost = nums.size()-1;
        for(int i=nums.size()-2; i>=0; i--){
            if(i + nums[i] >= goalPost){
                goalPost = i;
            }
        }
        return goalPost == 0;
    }
};
// Time Complexity - O(N)
// Space Complexity - O(1)
