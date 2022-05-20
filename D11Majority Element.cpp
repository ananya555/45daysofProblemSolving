// Problem Link
// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size()/2;
        map<int,int>mp;
        int ans;
        for(auto i:nums)
        {
            mp[i]++;
            if(mp[i]>n)
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};
