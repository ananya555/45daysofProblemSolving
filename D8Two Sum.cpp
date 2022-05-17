// Problem Link
// https://leetcode.com/problems/two-sum/

class Solution {
public:
    // Brute Force Approach
    vector<int> twoSum(vector<int>& nums, int target) {
        int x,y;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    x=i;
                    y=j;
                }
                
            }
        }
        return {x,y};
    }
    
    // Using 2 Pointers ==> This approach can't work as indices need to be retain same and returned.
    // So, sorting will not work
    vector<int> twoSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            if(nums[i]+nums[j]==target)
                break;
            else if(nums[i]+nums[j]>target)
            {
                j--;
            }
            else
                i++;
                
        }
        return {i,j};
    }
  
  // Using Map 
    vector<int> twoSum(vector<int>& nums, int target) {
        
       map<int, int> mnums;
        for (int i = 0; i < nums.size(); i++) {
            int add_one = target - nums[i];
            if (mnums.count(add_one))
                return vector<int> {i, mnums[add_one]};
            mnums.insert({nums[i], i});
        }
        return vector<int>{};
    }
};
