// Problem Link
// https://leetcode.com/problems/knight-dialer/

class Solution {
public:
      int knightDialer(int n) {
        vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        int count=0;
        int cache[5001][4][3]={};
        
        for(int i=0;i<4;++i)
            for(int j=0;j<3;++j)
               count= (count+getCount(mat,n,i,j,cache))%1000000007;
        
        return count;
    }
    
    int getCount(vector<vector<int>>&m, int len, int x,int y, int(&cache)[5001][4][3]) {
        if(x<0 || x>=4 || y<0 || y>=3 || m[x][y]<0) return 0;
        if(len==1) return 1;
        
        int& che =cache[len][x][y];
        if(che>0) return che;
        
        long long count=
		((long long)
		getCount(m,len-1,x-2,y+1,cache) +
		getCount(m,len-1,x-2,y-1,cache) +
		getCount(m,len-1,x-1,y+2,cache) +
		getCount(m,len-1,x-1,y-2,cache) +
		getCount(m,len-1,x+1,y+2,cache) +
		getCount(m,len-1,x+1,y-2,cache) +
		getCount(m,len-1,x+2,y+1,cache) +
		getCount(m,len-1,x+2,y-1,cache))%1000000007;
		
        che = count;
        return count;
    }
};
