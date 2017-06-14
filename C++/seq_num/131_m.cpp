/**
131[M]. Palindrome Paritioning
 
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.
For example, given s = "aab",
Return
[  
["aa","b"],  
["a","a","b"]
 ]
**/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> path;
        helper(res, path, s, 0);
        return res;
    }
    
    void helper(vector<vector<string> >&res, vector<string> &path, string s, int start)
    {
        if(start==s.size())
        {
            res.push_back(path);
            return;
        }
        for(int i=start;i<s.size();i++)
        {
            if(isPalindrome(s.substr(start, i-start+1)))
            {
                path.push_back(s.substr(start, i-start+1));
                helper(res, path, s, i+1);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
};

