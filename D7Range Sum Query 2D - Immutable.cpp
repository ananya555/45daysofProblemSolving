// Probelm Link
// https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
public:
    vector<vector<int>> dp;
	NumMatrix(vector<vector<int>>& matrix) {
		int r=matrix.size(),c=matrix[0].size();
		dp.resize(r,vector<int>(c,0));
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(i==0 or j==0){
					if(i==0 && j==0) dp[i][j]+=matrix[i][j];
					else if(i==0) dp[i][j]+=dp[i][j-1]+matrix[i][j];
					else if(j==0) dp[i][j]+=dp[i-1][j]+matrix[i][j];
				}
				else{
					dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i][j];
				}
			}
		}
	}

	int sumRegion(int rmin, int cmin, int rmax, int cmax) {
		if(rmin==0 && cmin==0){
			  return dp[rmax][cmax];
		  }
		else if(rmin==0){
			   return dp[rmax][cmax]-dp[rmax][cmin-1];
		   }
		else if(cmin==0){
			return dp[rmax][cmax]-dp[rmin-1][cmax];
		}
		return dp[rmax][cmax]-dp[rmin-1][cmax]-dp[rmax][cmin-1]+dp[rmin-1][cmin-1];
	}
};
