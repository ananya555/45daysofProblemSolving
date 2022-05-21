// Problem Link
// https://leetcode.com/problems/game-of-life/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
         int m = board.size(), n=board[0].size();
        vector <vector<int>> v=board;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int sm = max(0, i-1), sn=max(0, j-1);
                int em=min(i+1, m-1), en = min(j+1, n-1);
                int c =0;
                for(int i1=sm; i1<=em;i1++) {
                    for(int j1=sn; j1<=en; j1++) {
                        if(i1==i && j1==j)
                            continue;
                        else if(board[i1][j1]!=0)
                            c++;
                    }
                }
                if(board[i][j]==1) {
                    if(c<2)
                        v[i][j]=0;
                    else if(c>3)
                        v[i][j]=0;
                }
                else if(board[i][j]==0) {
                    if(c==3)
                        v[i][j]=1;
                }
            }
        }
        board=v;
    }
};
