/**
5[M]. Longest Palindrome SubString
 
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of sis 1000.
Example:
Input: "babad"  Output: "bab"  Note: "aba" is also a valid answer.
Example:
Input: "cbbd"  Output: "bb" 
**/
class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size();
        if(n<2) return s;
        bool dp[n][n];
        fill_n(&dp[0][0], n*n, false);
        int len=1, start=0;
        for(int j=0;j<n;j++)
        {
            dp[j][j]=true;
            for(int i=0;i<j;i++)
            {
                if((s[i]==s[j]&&j-i<2)||(dp[i+1][j-1]&&s[i]==s[j]))
                {
                    dp[i][j]=true;
                    if((j-i+1)>len)
                    {
                        start=i;
                        len=j-i+1;
                    }
                }
            }
        }
        return s.substr(start, len);
    }
};
