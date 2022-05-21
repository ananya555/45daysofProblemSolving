// Problem Link
// https://leetcode.com/problems/spiral-matrix/

vector<int> ans;
    void find(vector<vector<int>>& mat,int m,int n,int i,int j){
        if(i>m || j>n){
            return;
        }
        if(i==m && j==n){
            ans.push_back(mat[i][j]);
            return;
        }
        for(int t=j;t<=n;t++){
            ans.push_back(mat[i][t]);
        }
        
        for(int t=i+1;t<=m;t++){
            ans.push_back(mat[t][n]);
        }
        if(i==m || j==n){
            return;
        }
        for(int t=n-1;t>=j;t--){
            ans.push_back(mat[m][t]);
        }
        for(int t=m-1;t>i;t--){
            ans.push_back(mat[t][j]);
        }
        find(mat,m-1,n-1,i+1,j+1);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size()-1;
        
        int n = matrix[0].size()-1;
        find(matrix,m,n,0,0);
        return ans;
    }
