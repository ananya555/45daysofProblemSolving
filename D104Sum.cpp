// Probelm Link
// https://leetcode.com/problems/4sum/

class Solution {
public:
    // Two Pointers Approach
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res; 
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            if (i != 0 && nums[i] == nums[i-1]) continue; //Prevent consecutive numbers
            
            for(int j=i+1; j<nums.size(); j++){
                if (j != i+1 && nums[j] == nums[j-1]) continue;
                
                int new_target = target - nums[i] - nums[j];
                int x = j+1, y = nums.size()-1;
                while(x < y){
                    int tmp = nums[x] + nums[y];
                    if (x != j+1 && nums[x] == nums[x-1]) {
                        x++;
                        continue;
                    }
                    
                    if(tmp > new_target){
                        y--;
                    }
                    else if(tmp < new_target){
                        x++;
                    }
                    else{
                        res.push_back({nums[i], nums[j], nums[x], nums[y]});
                        x++;
                        y--;
                    }
                }
            }
        }
        return res;
    }
    
    
    // Hash Map
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }
	
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
        vector<vector<int>> res;
        
        // If we have run out of numbers to add, return res.
        if (start == nums.size()) {
            return res;
        }
        
        // There are k remaining values to add to the sum. The 
        // average of these values is at least target / k.
        int average_value = target / k;
        
        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest 
        // value in nums is smaller than target / k.
        if  (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }
            
        if (k == 2) {
            return twoSum(nums, target, start);
        }
    
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                for (vector<int>& subset : kSum(nums, static_cast<long>(target) - nums[i], i + 1, k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }
                                            
        return res;
    }
	
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
        vector<vector<int>> res;
        unordered_set<int> s;
    
        for (int i = start; i < nums.size(); ++i) {
            if (res.empty() || res.back()[1] != nums[i]) {
                if (s.count(target - nums[i])) {
                    res.push_back({ target - nums[i], nums[i] });
                }
            }
            s.insert(nums[i]);
        }
                                             
        return res;
    }  

};
