/**
139[M]. Word Break
 
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
For example, given
s = "leetcode",
dict = ["leet", "code"].
Return true because "leetcode" can be segmented as "leet code".
**/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size()==0) return true;
        unordered_set<string> dict;
        for(auto w:wordDict) dict.insert(w);
        int len=s.size();
        int dp[len+1];
        fill_n(&dp[0], len+1, false);
        dp[0]=true;

        for(int i=1;i<=len;i++)
        {
            for(int j=0;j<i;j++)
            {
               if(dp[j]&&dict.find(s.substr(j, i-j))!=dict.end())
               {
                  dp[i]=true;
                  break;
               }
            }
        }
        return dp[len];
    }
};

