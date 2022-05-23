// Problem Link
// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    // Brute Force Approach
//     string reverseWords(string s) {
//         string ans;
//         int n=s.size();
//         stack<string> st;
//         string currWord;
//         for(int i=0;i<n;i++)
//         {
//             if(s[i]==' ')
//             {
//                 if(currWord.size())
//                 {
//                     st.push(currWord);
//                     currWord="";
//                 }
//             }
//             else
//                 currWord+=s[i];
//         }
//         if(currWord.size()) st.push(currWord);
        
//         while(st.size()>1)
//         {
//             ans+=st.top()+' ';
//             st.pop();
//         }
//         ans+=st.top();
        
//         return ans;
//     }
    
    // Optimal Approach
    string reverseWords(string s) {
        string result;
        int i = 0, n = s.length();
        
        while(i < n){
			//to detect spaces and ignore them
            while(i < n && s[i] == ' ') i++;
            
            if(i >= n) break;
            
            int j = i;
            
			//to detect characters and break when we detect any space
            while(j < n && s[j] != ' ') j++;
            
			//to take out the first word
            string sub = s.substr(i, j-i);
            
            if(result.length() == 0) result = sub;
            
            else result = sub + " " + result;
            
            i = j+1;
        }
        return result;
    }
};
