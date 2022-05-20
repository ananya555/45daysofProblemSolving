// Problem Link
// https://leetcode.com/problems/word-search/

class Solution {
public:
    /*
    bool search(vector<vector<char>>& board, int i, int j, string& word, int pos, vector<vector<bool>>& visited){
        if(pos == word.length() - 1)
            return true;
        
        visited[i][j] = true;
        
        if(i > 0 && !visited[i-1][j] && board[i-1][j] == word[pos+1] &&search(board ,i-1 ,j ,word, pos+1, visited))
            return true;
        if(j > 0 && !visited[i][j-1] && board[i][j-1] == word[pos+1] &&search(board ,i ,j-1 ,word, pos+1, visited))
            return true;
        if(i < board.size()-1 && !visited[i+1][j] && board[i+1][j] == word[pos+1] &&search(board ,i+1 ,j ,word, pos+1, visited))
            return true;
        if(j < board[0].size()-1 && !visited[i][j+1] && board[i][j+1] == word[pos+1] &&search(board ,i ,j+1 ,word, pos+1, visited))
            return true;
        
        visited[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(board[i][j] == word[0] && search(board,i,j,word,0,visited))
                    return true;
        
        return false;
    }
    
    */
    
    // 2nd Method without using extra space
    bool search(vector<vector<char>>& board, int i, int j, string& word, int pos){
        if(pos == word.length() - 1)
            return true;
        
        /* ASCII value of A-Z : 65-90 && a-z : 97-122
         That's why i took 65, i.e ASCII value of A so that when i subtract it goes out of range of a-z & A-Z 
         U can take any other no. also but after subtracting it should go out of range of words
        It works similar as visited just having less space now*/
        board[i][j] -= 65;
        
        if(i > 0 && board[i-1][j] == word[pos+1] && search(board ,i-1 ,j ,word, pos+1))
            return true;
        if(j > 0 &&  board[i][j-1] == word[pos+1] && search(board ,i ,j-1 ,word, pos+1))
            return true;
        if(i < board.size()-1 && board[i+1][j] == word[pos+1] &&search(board ,i+1 ,j ,word, pos+1))
            return true;
        if(j < board[0].size()-1 && board[i][j+1] == word[pos+1] &&search(board ,i ,j+1 ,word, pos+1))
            return true;
        
        board[i][j] += 65;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
      
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(board[i][j] == word[0] && search(board,i,j,word,0))
                    return true;
        
        return false;
    }
  
    
