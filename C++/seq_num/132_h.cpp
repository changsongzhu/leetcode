/**
132[H]. Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
**/

class Solution {
public:
    int minCut(string s) {
        if(s.size()<2) return 0;
        int n=s.size();
        bool p[n][n];
        int dp[n];
        fill_n(&p[0][0], n*n, false);
        for(int i=n-1;i>=0;i--)
           dp[i]=n-1-i;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i]==s[j]&&(j-i<=1||p[i+1][j-1]))
                {
                   p[i][j]=true;
                   dp[i]=min(dp[i], (j==n-1?0:dp[j+1]+1));
                }
            }
        }
        return dp[0];
    }
};

//Another Solution
class Solution {
public:
    int minCut(string s) {
        if(s.size()<2) return 0;
        int n=s.size();
        bool p[n][n];
        int dp[n];
        fill_n(&p[0][0], n*n, false);
        for(int i=0;i<n;i++) dp[i]=i;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(s[i]==s[j]&&(i-j<=1||p[j+1][i-1]))
                {
                    p[j][i]=true;
                    dp[i]=min(dp[i], j==0?0:dp[j-1]+1);
                }
            }
        }
        return dp[n-1];
    }
};
