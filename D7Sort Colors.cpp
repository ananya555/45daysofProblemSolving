// Problem Link
//https://leetcode.com/problems/sort-colors/

class Solution {
public:
    
    // Two Pointers Approach
    void sortColors(vector<int>& arr) {
        
        // DUTCH FLAG Approach
        
        int low = 0, mid = 0, high = arr.size()-1;
        
        while(mid <= high)
        {
            if(arr[mid] == 0)
                swap(arr[low++], arr[mid++]);
            else if(arr[mid] == 1)
                mid++;
            else
                swap(arr[mid], arr[high--]);
        }
    }
};
