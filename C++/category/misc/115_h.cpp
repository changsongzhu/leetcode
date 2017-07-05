/*
115[H]. Distinct Subsequence
Given a string S and a string T, count the number of distinct subsequences of S which equals T.
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
Here is an example:
S = "rabbbit", T = "rabbit"
Return 3.
**/

/*TLE Solution*/
class Solution {
public:
    int numDistinct(string s, string t) {
       int res=0;
       if(s.size()<t.size()) return 0;
       helper(s, t, 0, 0, res);
       return res;
    }
    void helper(string s, string t, int start, int index, int &res)
    {
       if(index==t.size())
       {
           res++;
           return;
       }
       for(int i=start;i<=s.size()-t.size()+index;i++)
       {
           if(s[i]!=t[index]) continue;
           helper(s, t, i+1, index+1, res);
       }
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int dp[t.size()+1][s.size()+1]={0};
        dp[0][0]=1;
        for(int i=1;i<=t.size();i++)dp[i][0]=0;
        for(int j=1;j<=s.size();j++)dp[0][j]=1;
        for(int i=1;i<=t.size();i++)
        {
            for(int j=1;j<=s.size();j++)
            {
                dp[i][j]=dp[i][j-1]+((s[j-1]==t[i-1])?dp[i-1][j-1]:0);
            }
        }
        return dp[t.size()][s.size()];
    }
};

