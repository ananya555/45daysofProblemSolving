// Problem Link
// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    // Brute Force Solution ==> TC:- O(N^2), SC:- O(1)
    // It gives TLE
    int maxArea(vector<int>& height) {
	    
        int len=height.size(), max=0, area=0;
            for(int i=0;i<len;i++){
                for(int j=i+1;j<len;j++){
                    area=min(height[i],height[j])*(j-i);
                    if(area>max)
                        max=area;
                }
            }
        return max;
    }
    
    // Optimal Approach using Two Pointer ==> TC:- O(N), SC:- O(1)
    int maxArea(vector<int>& height) {
        
        int i=0,j=height.size()-1;
    int maxArea=min(height[i],height[j])*(j-i);
    while(i<j){
     if(height[i]<height[j]){
          i++;
         }
     else{
         j--;  
     }
        int currArea=min(height[i],height[j])*(j-i);
        maxArea=max(currArea,maxArea);
    }
    return maxArea;
    }
};
