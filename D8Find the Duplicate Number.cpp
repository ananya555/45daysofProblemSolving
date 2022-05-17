// Probelm Linkclass Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // 1st Approach using set
        
       set<int> check;
        int ans;
        int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(check.find(a[i])==check.end())
        {
            check.insert(a[i]);
        }
        else
        {
            ans=a[i];
            break;
        }
    }
        return ans;
        
        
        // 2nd approach
        int n=a.size();
        vector<int>arr(n,0);
        int ans;
        for(int i=0;i<n;i++)
        {
            if(arr[a[i]]==0)
                arr[a[i]]++;
            else 
            {
                ans=a[i];
                break;
            }
        }
        return ans;
        
        // Constant space
        int findDuplicate(vector<int>& nums) {
        while (nums[0] != nums[nums[0]])
            swap(nums[0], nums[nums[0]]);
        return nums[0];
        }
        
        // Floyd's Tortoise and Hare (Cycle Detection)
        int findDuplicate(vector<int>& nums) {

        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];

        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};
