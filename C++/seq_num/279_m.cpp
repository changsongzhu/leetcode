/**
279[M]. Perfect Square
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
**/


//Refined Solution
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};


class Solution {
public:
    int numSquares(int n) {
       vector<int> dp(n+1, n);
       dp[0]=0;
       for(int i=1;i<=n;i++)
       {
           for(int j=1,k=j*j;k<=i;j++,k=j*j)
              dp[i]=min(dp[i], dp[i-k]+1);
       }
       return dp[n];
    }
};

