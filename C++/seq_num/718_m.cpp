/**
718[M]. Maximum Length of Repeated Subarray

Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
**/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m=A.size(), n=B.size();
        int dp[m+1][n+1];
        fill_n(&dp[0][0], (m+1)*(n+1), 0);
        int res=INT_MIN;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(A[i-1]==B[j-1])
                {
                    dp[i][j]=max(dp[i-1][j-1]+1, dp[i][j]);
                    res=max(res, dp[i][j]);
                }
            }
        }
        return res==INT_MIN?0:res;
        
    }
};

