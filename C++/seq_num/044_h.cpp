/**
44[H]. Wildcard Matching
Implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
 
The matching should cover the entire input string (not partial).
 
The function prototype should be:
bool isMatch(const char *s, const char *p)
 
Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "*") ? true
isMatch("aa", "a*") ? true
isMatch("ab", "?*") ? true
isMatch("aab", "c*a*b") ? false
**/

//DP Solution
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
        dp[0][0]=true;
        for(int i=0;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i][j-1]||(i>0&&dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=i>0&&dp[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='?');
                }
            }
        }
        return dp[m][n];        
    }
}; 

class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0,j=0,m=-1,k=-1;
        while(i<s.size())
        {
            if(s[i]==p[j]||p[j]=='?')
            {
                i++;j++;
            }
            else if(p[j]=='*')
            {
                k=j++;
                m=i;
            }
            else if(k!=-1)
            {
                j=k+1;
                i=++m;
            }
            else return false;
        }
        while(p[j]=='*') j++;
        return j==p.size();
    }
};

//TLE Solution
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p.size()==1&&p[0]=='*') return true;
        if(p[0]=='*')
        {
            if(p[1]=='*')
            {
                return isMatch(s, p.substr(1));
            }
            else
            {
                for(int i=0;i<s.size();i++)
                {
                    if(s[i]==p[1]||p[1]=='?')
                    {
                        if(isMatch(s.substr(i), p.substr(1))) return true;
                    }
                }
                return false;
            }
        }
        else if(!s.empty()&&(s[0]==p[0]||p[0]=='?'))
        {
            return isMatch(s.substr(1), p.substr(1));
        }
        else return false;
        
    }
};

