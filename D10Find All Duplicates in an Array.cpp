// Problem Link
// https://leetcode.com/problems/find-all-duplicates-in-an-array/
class Solution {
public:
    // Brute Force Approach ==> TC:- O(N^2), SC:- O(1)
    // But this approach gives TLE
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int ele=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]==ele)
                    ans.push_back(nums[i]);
            }
        }
        return ans;
    }
    // Using Sorting ==>TC:- O(nlog(n)), SC:- O(1)
    vector<int> findDuplicates(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int check = -1;
    vector<int> ans;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] == nums[i - 1])
        {
            if(nums[i] != check)
            {
                ans.push_back(nums[i]);
                check = -1;
            }
            else{
                continue;
            }
        }
    }
    return ans;
}
    // Using Hash Map ==> SC:- O(N), TC:- O(N)
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int>m;
        
        for(auto x: nums){
            m[x]++;
        }
        vector<int>v;
        for(auto x : m){
            if(x.second == 2)v.push_back(x.first);
        }
        
        return v;
    }
    
    // Better Approach using vector but SC:- O(N), TC:- O(N)
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>res(n+1,0);
        vector <int> ans;
        for(int i: nums)
        {
                res[i]++;
        }
        
        for(int i=0;i<res.size();i++)
        {
            if(res[i]==2)
            {
                ans.push_back(i);
            }
            
        }
        return ans;
    }
    // Optimal Approach ==> SC:- O(1), TC:- O(N)
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>v;
        
    for(auto it : a){
            int x = abs(it);
            if(a[x-1]<0) v.push_back(x);
            else a[x-1]=-a[x-1];
        }
        
        return v;
    }
};
