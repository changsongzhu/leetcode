/**
647[M]. Palindromic Substrings


Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".


Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Note:
The input string length won't exceed 1000.
**/

class Solution {
public:
    int countSubstrings(string s) {
        if(s.size()<2) return s.size();
        int n=s.size();
        int res=0;
        vector<vector<int> > dp(n+1, vector<int>(n+1, false));
        for(int i=1;i<=n;i++)
        {
            dp[i][i]=true;
            res++;
            for(int j=1;j<=i-1;j++)
            {
                if(((i-j)<2||dp[j+1][i-1])&&s[i-1]==s[j-1])
                {
                    dp[j][i]=true;
                    res++;
                }
                
            }
        }
        return res;
        
    }
};

