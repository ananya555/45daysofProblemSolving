// Problem Link
// https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      /*  for(int i=0;i<n;i++){
            nums1[i+m]=nums2[i];
        }
        sort(nums1.begin(),nums1.end());
        return;*/
        /*
        
        
        vector<int> temp;
        int i = 0, j = 0;
        while(i < m && j < n){
            if(nums1[i] > nums2[j]){
                temp.push_back(nums2[j]);
                j++;
            }
            else{
                temp.push_back(nums1[i]);
                i++;
            }
        }
        while(i < m){
            temp.push_back(nums1[i]);
            i++;
        }
        while(j < n){
            temp.push_back(nums2[j]);
            j++;
        }
        for(int k = 0; k < temp.size(); k++){
            nums1[k] = temp[k];
        }
        */
        
        int i = m-1, j = n-1, k = m+n-1;
		while(i >=0 && j>=0)
		{
			if(nums1[i] > nums2[j])
				nums1[k--] = nums1[i--];
			else
				nums1[k--] = nums2[j--];
		}
        // no need to traverse the nums1 array because it's elements are already in place..
		while(j >= 0)
			nums1[k--] = nums2[j--];
        
      
    }
};
