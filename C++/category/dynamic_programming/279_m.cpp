/**
279[M]. Perfect Square
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
**/

class Solution {
public:
    int numSquares(int n) {
       vector<int> dp(n+1, n);
       dp[0]=0;
       dp[1]=1;
       for(int i=2;i<=n;i++)
       {
           for(int j=0,k=j*j;k<=i;j++,k=j*j)
              dp[i]=min(dp[i], dp[i-k]+1);
       }
       return dp[n];
    }
};

