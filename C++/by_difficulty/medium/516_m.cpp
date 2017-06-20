/**

516[M]. Longest Palindromic Subsequence
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
Example 1:
Input:
"bbbab"


Output:
4


One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:
"cbbd"


Output:
2

One possible longest palindromic subsequence is "bb".
**/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size()<2) return s.size();
        vector<vector<int> > dp(s.size(),vector<int>(s.size(), 0));
        for(int j=0;j<s.size();j++)
        {
            dp[j][j]=1;
            for(int i=j-1;i>=0;i--)
            {
               if(s[i]==s[j]) 
               {
                  dp[i][j]=(j-i>=2)?dp[i+1][j-1]+2:2;
               }
               else
                {
                    dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];

    }
};
