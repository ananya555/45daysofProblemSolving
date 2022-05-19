// Problem Link
// https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int n=a.size(),count=0;
        
        //1. brute force- O(N^2),AS-O(N)
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=a[j];
                if(sum%k==0)count++;
            }
        }
        
        return count;
        
		//2. better-O(N),AS-O(N) - use of hashmap to store the remainder of cumulative sum for each index
        unordered_map<int,int>m;
        m[0]=1;
        //(y-x)%k=0 -> y%k=x%k
        int cumulativeSum=0;
        for(auto it :a){
            cumulativeSum+=it;
            int rem;
            rem=cumulativeSum%k;
            //add k when remainder is negative
            //(-4)modulo7= 3 but  C++ compiler gives -4
            //so to adjust that we will add the divisor, here 7 -> -4+7=3
            if(rem<0) rem+=k;
            if(m.count(rem)) count+=m[rem];
            m[rem]++;
        }
        
        return count;
    }
};
