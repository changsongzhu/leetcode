/**
664[H]. Strange Printer
There is a strange printer with the following two special requirements:
The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.
Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.
Example 1:
Input: "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".


Example 2:
Input: "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.


Hint: Length of the given string will not exceed 100.
**/

class Solution {
public:
    int strangePrinter(string s) {
        memset(dp, 0, sizeof(dp));
        return dfs(s, 0, s.size()-1);         
    }
    int dfs(string &s, int l, int r)
    {
        if(l>r) return 0;
        if(dp[l][r]) return dp[l][r];
        dp[l][r]=dfs(s, l, r-1)+1;
        for(int i=l;i<r;i++)
        {
            if(s[i]==s[r])
            {
                dp[l][r]=min(dp[l][r], dfs(s, l, i)+dfs(s, i+1, r-1));
            }
        }
        return dp[l][r];
    }


private:
    int dp[100][100];
};

