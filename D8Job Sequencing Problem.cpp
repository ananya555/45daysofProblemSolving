// Problem Link
// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1/


// Using Greedy
bool static cmpInt(struct Job Job1,Job Job2){
        if(Job1.profit>Job2.profit) return true;
        return false;
    }
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmpInt);
        int dead=0;
        int profit=0;
        int job=0;        
        vector<bool> slot(n,false);
        for(int i=0;i<n;i++){
            dead=arr[i].dead;
            while(dead-1>=0){
                if(slot[dead-1]==false){
                    slot[dead-1]=true;
                    profit+=arr[i].profit;
                    job+=1;
                    break;
                }
                dead--;
            }
        }
        return {job,profit};
    }
