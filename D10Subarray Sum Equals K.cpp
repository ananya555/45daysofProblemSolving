// Problem Link
// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    // Brute Force Approach ===>O(n^3)
    int subarraySum(vector<int>& nums, int k) {
        // Brute Force Solution Time O(N^3) & Auxiliary Space O(1)
        // Time Limit Exceed(TLE) 61/89 test cases passed
        int len=nums.size(),count=0;
        // Consider all possible subarrays
        for(int i=0;i<len;i++){ 
            for(int j=i;j<len;j++){ // Consider subarray from nums[i] to nums[j]
                int sum=0;
                for(int s=i;s<=j;s++){ // Calculate sum of elements from nums[i] to nums[j]
                   sum+=nums[s]; 
        }
                if(sum==k) // Check if sum is equal to k
                    count++;
        }
        }
        return count;
    }
   
    // Better Solution ==> O(n^2)
    int subarraySum(vector<int>& nums, int k) {
        // Better Solution Time O(N^2) & Auxiliary Space O(N)
        // Time Limit Exceed(TLE) 84/89 test cases passed
        int len=nums.size(), count=0;
        vector<int> ls; // prefix sum array or left sum array
                        // ls[i] will be sum of elemensts from nums[0] to nums[i]
        ls.push_back(0);
        for(int i=0;i<len;i++)
            ls.push_back(ls.back()+nums[i]); // inserting elements in ls
        for(int i=0;i<ls.size();i++){ 
            for(int j=i+1;j<ls.size();j++){ 
                   // For example: nums[]={2,8,5,-3,1,8}, k=10
                   // ls[]={2,10,15,12,13,21}, k=10
                   // nums[1]+nums[2]+nums[3]=8+5+(-3)=10. 
                   // j runs from 1 to 3. For j=i+1 & j=1, we get i=0.
                   // Therefore i=0 & j=3.
                   // ls[j=3]-ls[i=0]=12-2=10 which is equal to k.
                   if(ls[j]-ls[i]==k) 
                       count++;
            }
        }
        return count;
    }
    
    // Optimal Approach ===>O(n)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int c=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==k)
                c++;
            
            if(mp.find(sum-k)!=mp.end())
                c+=mp[sum-k];
            
            mp[sum]++;
        }
        return c;
    }
};
