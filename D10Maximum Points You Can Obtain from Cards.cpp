// Problem Link
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

int result = 0;

for(int i = 0; i < k; i++)
{
    result += cardPoints[i];
}

int sum = result;

for(int i = 0; i < k; i++)
{
    sum -= cardPoints[k - 1 - i];
    sum += cardPoints[n - 1- i];
    
    result = max(result, sum);
}

return result;
    }
};
