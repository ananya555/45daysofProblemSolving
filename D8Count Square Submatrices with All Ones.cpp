// Problem Link
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& ma) {
        int m=ma.size();
        int n=ma[0].size();
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            { 
                   if(ma[i][j])
                     ma[i][j]=ma[i][j]+min(ma[i-1][j],min(ma[i][j-1],ma[i-1][j-1]));
                   else
                       ma[i][j]=0;
                 
            }
        }
            
        int ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                ans+=ma[i][j];
        return ans;
    }
};
