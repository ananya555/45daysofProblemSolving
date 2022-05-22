// Problem Link
// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        
        if(v.size()==0)
            return "";
        string temp=v[0];
        int mi=INT_MAX;
        for(int i=1;i<v.size();i++)
        {
            int j=0,k=0,ans=0;
            while(j<temp.size() and k<v[i].size())
            {
                if(temp[j]==v[i][k])
                    ans++;
                else 
                    break;
                
                j++;
                k++;
            } 
            mi=min(mi,ans);
        }
        return temp.substr(0,mi);
    }
};
