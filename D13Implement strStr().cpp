// Problem Link
// https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string h, string n) {
        int m = h.size(), n1 = n.size();
        if (n1 == 0) {
            return 0;
        }
        
        if (m == 0) {
            return -1;
        }
        
        int flag = 0;
        for (int i = 0; i < m; i++) {
            if (h[i] == n[0]) {
                flag = 0;
                for (int j = 0; j < n1; j++) {
                    if (h[i+j] != n[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    return i;
                }
            }
        }
        return -1;
    }
};
